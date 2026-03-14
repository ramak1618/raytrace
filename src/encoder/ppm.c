#include "../../include/encoder/ppm.h"

#include <stdio.h>

bool generatePPM(lRGB** img, uint32_t width, uint32_t height, const char* filename) {
    FILE* file = fopen(filename, "wb");
    if(!file) {
        fprintf(stderr, "Could not open file for writing: %s\n", filename);
        return false;
    }

    fprintf(file, "P3\n%u %u\n255\n", width, height);
    for(uint32_t i=0; i<height; i++) {
        for(uint32_t j=0; j<width; j++) { 
            int R = (int)(img[i][j].red*255.999999);
            int G = (int)(img[i][j].green*255.999999);
            int B = (int)(img[i][j].blue*255.999999);
            fprintf(file, "%d %d %d\n", R, G, B);
        }
    }

    fclose(file);
    return true;
}
