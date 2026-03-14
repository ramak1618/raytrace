#ifndef CAMERA_H
#define CAMERA_H

#include <stdint.h>
#include <stdbool.h>
#include <vecs/vecs.h>
#include "colors.h"
#include "triangle.h"

struct viewport_t {
    double width;
    double height;
    double dist;
};
typedef struct viewport_t viewport;

struct cam_orient_rfu_t {
    dir3 right;
    dir3 forward;
    dir3 up;
};
typedef struct cam_orient_rfu_t cam_orient_rfu;

struct resolution_t {
    uint32_t width;
    uint32_t height;
    uint32_t samples_per_pixel;
};
typedef struct resolution_t resolution;

struct camera_t {
    pos3 pos;
    viewport vp;
    cam_orient_rfu orient;
    resolution res;
    lRGB* imgbuf;
    lRGB** img;
};
typedef struct camera_t camera;

camera camera_create(pos3 pos, viewport vp, cam_orient_rfu orient, resolution res);
void camera_destroy(camera* cam);
bool render(const camera* cam, const triangle* triangles, uint32_t num_triangles); 

#endif
