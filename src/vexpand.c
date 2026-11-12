#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int EXIT_STATUS = EXIT_SUCCESS;

    if(argc != 3) {
        fprintf(stderr, "Usage: vexpand srcfile dstfile\n");
        return EXIT_FAILURE;
    }

    const char* srcfilepath = argv[1];
    const char* dstfilepath = argv[2];

    FILE* srcfile = fopen(srcfilepath, "r");
    FILE* dstfile = fopen(dstfilepath, "w");
    if(!srcfile) {
        fprintf(stderr, "Could not open file for reading: %s\n", srcfilepath);
        EXIT_STATUS = EXIT_FAILURE;
        goto close_files;
    }
    if(!dstfile) {
        fprintf(stderr, "Could not open file for writing: %s\n", dstfilepath);
        EXIT_STATUS = EXIT_FAILURE;
        goto close_files;
    }

    fseek(srcfile, 0, SEEK_END);
    long srcsize = ftell(srcfile);
    fseek(srcfile, 0, SEEK_SET);

    char* srcbuf = malloc(srcsize);
    if(!srcbuf) {
        fprintf(stderr, "malloc error!\n");
        EXIT_STATUS = EXIT_FAILURE;
        goto close_files;
    }

    long bytes_read = fread(srcbuf, 1, srcsize, srcfile);
    if(bytes_read < srcsize) {
        fprintf(stderr, "file read error!\n");
        EXIT_STATUS = EXIT_FAILURE;
        goto free_srcbuf;
    }

    // keeps track of till where in the srcbuf we have written to in dstbuf
    long write_head = 0;

    // 1024 bytes per expansion line for expressions should be more than enough.
    char* exprX = malloc(1024);
    char* exprY = malloc(1024);
    char* exprZ = malloc(1024);

    if(!exprX || !exprY || !exprZ) {
        fprintf(stderr, "malloc error!\n");
        EXIT_STATUS = EXIT_FAILURE;
        goto free_exprs;
    }

    for(long i=0; i<srcsize; i++) {
        // wait until "[["
        if(srcbuf[i] != '[' || srcbuf[i+1] != '[')
            continue;
        
        // now write all bytes before this point.
        fwrite(srcbuf+write_head, 1, i-write_head, dstfile);

        // advance i to after "[["
        i += 2;

        int j=0;
        while(srcbuf[i] != ']' || srcbuf[i+1] != ']') {
            if(j > 1000) {
                fprintf(stderr, "Vector expression too large! (stopped at byte: %ld)\n", i);
                goto free_exprs;
            }

            if(srcbuf[i] == '`') {
                exprX[j] = '.';
                exprY[j] = '.';
                exprZ[j] = '.';
                j++;
                exprX[j] = 'X';
                exprY[j] = 'Y';
                exprZ[j] = 'Z';
                j++;
            }
            else {
                exprX[j] = srcbuf[i];
                exprY[j] = srcbuf[i];
                exprZ[j] = srcbuf[i];
                j++;
            }
            i++;
        }
        
        // advance i to after "]]"
        i += 2;

        // Make sure last byte is null
        exprX[j] = '\0';
        exprY[j] = '\0';
        exprZ[j] = '\0';

        fprintf(dstfile, "(vec3) {%s,%s,%s}", exprX, exprY, exprZ);

        // advance write_head to here
        write_head = i;
    }

    // write remaining bytes
    fwrite(srcbuf+write_head, 1, srcsize-write_head, dstfile);


free_exprs:
    if(exprX)
        free(exprX);
    if(exprY)
        free(exprY);
    if(exprZ)
        free(exprZ);
free_srcbuf:
    free(srcbuf);
close_files:
    if(srcfile)
        fclose(srcfile);
    if(dstfile)
        fclose(dstfile);

    return EXIT_STATUS;
}
