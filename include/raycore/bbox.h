#ifndef BBOX_H
#define BBOX_H

#include <stdbool.h>
#include "utils/array.h"
#include "triangle.h"

// Axis Aligned Bounding Box. (A cuboid whose edges are along global axes)
struct AABB_t {
    double x_min;
    double x_max;
    double y_min;
    double y_max;
    double z_min;
    double z_max;
};
typedef struct AABB_t AABB;

// if tmax < 0, it treats as if there is no upper bound
// tmin is implicitly set as 0
bool AABB_hit(AABB bbox, ray incident, double tmax);

// BVH is strictly binary. i.e. node->left == NULL iff node->right == NULL
struct BVH_t {
    AABB bbox;

    Array trngl_indices;
    
    struct BVH_t* left;
    struct BVH_t* right;
};
typedef struct BVH_t BVH;

enum XYZ_axis_t {
    AXIS_X, AXIS_Y, AXIS_Z
};
typedef enum XYZ_axis_t XYZ_axis;

bool BVH_is_leaf(const BVH* node);
bool is_triangle_in_left(const triangle* trngl, double mid, XYZ_axis axis);
bool is_triangle_in_right(const triangle* trngl, double mid, XYZ_axis axis);
hit_record BVH_hit(const triangle* trngls, const BVH* node, ray incident, double* tmax);

struct object_t {
    triangle* trngls;
    uint32_t num_trngls;

    BVH* bound_vol;
};
typedef struct object_t object;

#endif
