#ifndef ICOSPHERE_H
#define ICOSPHERE_H

#include <stdint.h>
#include <raycore/triangle.h>

// k is number of times to divide each triangle into 4 triangles,
// starting from a regular icosahedron
// returns no. of triangles, and populates the `trngls` pointer-to-array
uint32_t icosphere_create(pos3 centre, double radius, uint32_t k, triangle** trgnls);
void icosphere_destroy(triangle** trngls);

#endif
