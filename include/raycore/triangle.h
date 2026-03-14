#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <vecs/vecs.h>

struct triangle_t {
    pos3 vtx;
    vec3 p1;
    vec3 p2;
    dir3 normal;
};
typedef struct triangle_t triangle;

triangle triangle_from_edges(pos3 p, vec3 e1, vec3 e2);
triangle triangle_from_vertices(pos3 a, pos3 b, pos3 c);

// returns -1 if did not hit
// if tmax < 0; then treats as if there is no upper bound
// tmin is implicitly set as 0
double triangle_hit(const triangle* trngl, ray incident, double tmax);

#endif
