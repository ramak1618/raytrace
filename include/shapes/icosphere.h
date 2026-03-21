#ifndef ICOSPHERE_H
#define ICOSPHERE_H

#include <stdint.h>
#include <raycore/object.h>

// k is number of times to divide each triangle into 4 triangles,
// starting from a regular icosahedron
object icosphere_create(pos3 centre, double radius, uint32_t k);
void icosphere_destroy(object* obj);

#endif
