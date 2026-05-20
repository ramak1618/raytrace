#ifndef OBJECT_H
#define OBJECT_H

#include "triangle.h"

struct object_t {
    triangle* trngls;
    uint32_t num_trngls;
};
typedef struct object_t object;

#endif
