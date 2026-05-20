#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <vecs/vecs.h>

struct triangle_t {
    pos3 A;
    pos3 B;
    pos3 C;
};
typedef struct triangle_t triangle;

triangle triangle_from_edges(pos3 p, vec3 e1, vec3 e2);
triangle triangle_from_vertices(pos3 a, pos3 b, pos3 c);

// The triangle_hit function needs to return normal,
// the scale value of incident direction,
// and the texture coords.
struct hit_record_t {
    dir3 normal;
    double t;

    // note that im using alpha and beta instead of u and v.
    // i just like the edge interpretation over barycentric.
    // It is same as barycentric, wherein alpha is coeff. of B vtx and beta is coeff. of C vtx.
    double alpha;
    double beta;
};
typedef struct hit_record_t hit_record;

// if return.t < 0, the ray did not hit.
// if tmax < 0; then treats as if there is no upper bound
// tmin is implicitly set as 0
hit_record triangle_hit(const triangle* trngl, ray incident, double tmax);

#endif
