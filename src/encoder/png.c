#include "../../include/encoder/png.h"

#include <stdio.h>
#include <libavcodec/avcodec.h>

struct encoder {
    AVCodecContext* ctx;
    AVFrame* frame;
    AVPacket** pkts;
    size_t num_pkts;
};

// Reference: https://ffmpeg.org/doxygen/trunk/encode_video_8c-example.html
enum PNGerr encoder_create(struct encoder* enc, lRGB** img, uint32_t width, uint32_t height) {
    enc->ctx = NULL;
    enc->frame = NULL;
    enc->pkts = NULL;

    const AVCodec* codec = avcodec_find_encoder(AV_CODEC_ID_PNG);
    if(!codec)
        return PNG_CODEC_LOST;

    enc->ctx = avcodec_alloc_context3(codec);
    if(!codec)
        return PNG_ALLOC_ERR;

    enc->ctx->width = width;
    enc->ctx->height = height;
    enc->ctx->pix_fmt = AV_PIX_FMT_RGBA;
    enc->ctx->time_base = (AVRational) {1, 1};
    enc->ctx->framerate = (AVRational) {1, 1};
    if(avcodec_open2(enc->ctx, codec, NULL) < 0)
        return PNG_CODEC_CLOSED;

    AVFrame* frame = av_frame_alloc();
    if(!frame)
        return PNG_ALLOC_ERR;
    frame->width = enc->ctx->width;
    frame->height = enc->ctx->height;
    frame->format = enc->ctx->pix_fmt;

    if(av_frame_get_buffer(frame, 0) < 0)
        return PNG_BUFFER_ERR;

    for(uint32_t i=0; i<height; i++) {
        for(uint32_t j=0; j<width; j++) {
            uint8_t R = (uint8_t)(255.999999 * img[i][j].red);
            uint8_t G = (uint8_t)(255.999999 * img[i][j].green);
            uint8_t B = (uint8_t)(255.999999 * img[i][j].blue);

            frame->data[0][i*frame->linesize[0] + j*4 + 0] = R;
            frame->data[0][i*frame->linesize[0] + j*4 + 1] = G;
            frame->data[0][i*frame->linesize[0] + j*4 + 2] = B;
            frame->data[0][i*frame->linesize[0] + j*4 + 3] = 255;
        }
    }

    if(avcodec_send_frame(enc->ctx, frame) < 0)
        return PNG_FRAME_ERR;

    size_t capacity = 5;
    enc->num_pkts = 0;
    enc->pkts = malloc(capacity * sizeof(AVPacket*));
    if(!enc->pkts)
        return PNG_ALLOC_ERR;
    int result;
    do {
        enc->pkts[enc->num_pkts] = av_packet_alloc();
        if(!enc->pkts[enc->num_pkts])
            return PNG_ALLOC_ERR;

        result = avcodec_receive_packet(enc->ctx, enc->pkts[enc->num_pkts]);
        enc->num_pkts++;
        if(result == AVERROR(EAGAIN) || result == AVERROR_EOF)
            break;
        else if(result < 0)
            return PNG_PKT_ERR;

        if(enc->num_pkts == capacity) {
            capacity *= 2;
            AVPacket** tmp = realloc(enc->pkts, capacity*sizeof(AVPacket*));
            if(!tmp)
                return PNG_ALLOC_ERR;
            enc->pkts = tmp;
        }
    } while(result >= 0);

    return PNG_OK;
}

void encoder_destroy(struct encoder* enc) {
    if(enc->pkts) {
        for(size_t i=0; i<enc->num_pkts; i++)
            av_packet_free(&enc->pkts[i]);
        free(enc->pkts);
    }

    if(enc->frame)
        av_frame_free(&enc->frame);

    if(enc->ctx)
        avcodec_free_context(&enc->ctx);
}

enum PNGerr generatePNG(lRGB** img, uint32_t width, uint32_t height, const char* filename) {
    struct encoder enc;
    enum PNGerr err = encoder_create(&enc, img, width, height);
    if(err != PNG_OK) {
        goto exit;
    }

    FILE* file = fopen(filename, "wb");
    if(!file) {
        err = PNG_BADFILE;
        goto exit;
    }
    for(size_t i=0; i<enc.num_pkts; i++) {
        fwrite(enc.pkts[i]->data, 1, enc.pkts[i]->size, file);
    }
    fclose(file);


exit:
    encoder_destroy(&enc);
    return err;
}
