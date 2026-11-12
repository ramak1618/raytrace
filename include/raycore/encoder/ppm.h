#ifndef PPM_H
#define PPM_H

#include <stdint.h>
#include <stdbool.h>
#include <raycore/colors.h>

// We shall not worry about gamma correction for now.
bool generatePPM(lRGB** img, uint32_t width, uint32_t height, const char* filename);

#endif
