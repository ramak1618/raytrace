#ifndef PNG_H
#define PNG_H

#include <stdint.h>
#include <raycore/colors.h>

enum PNGerr {
    PNG_OK,
    PNG_CODEC_LOST,
    PNG_ALLOC_ERR,
    PNG_CODEC_CLOSED,
    PNG_BUFFER_ERR,
    PNG_FRAME_ERR,
    PNG_PKT_ERR,
    PNG_BADFILE,
};
enum PNGerr generatePNG(lRGB** img, uint32_t width, uint32_t height, const char* filename);

#endif
