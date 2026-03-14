#include "../../include/vecs/vecs.h"

#include <math.h>

double dot(vec3 u, vec3 v) {
    return u.X*v.X + u.Y*v.Y + u.Z*v.Z;
}

vec3 cross(vec3 u, vec3 v) {
    return (vec3) {
        u.Y*v.Z - u.Z*v.Y,
        u.Z*v.X - u.X*v.Z,
        u.X*v.Y - u.Y*v.X
    };
}

double magnitude(vec3 u) {
    return hypot(hypot(u.X, u.Y), u.Z);
}

vec3 dir(vec3 u) {
    double mag = magnitude(u);
    return (vec3) { u.X/mag, u.Y/mag, u.Z/mag };
}

pos3 ray_at(ray r, double t) {
    return (pos3) {
        fma(t, r.dir.X, r.src.X),
        fma(t, r.dir.Y, r.src.Y),
        fma(t, r.dir.Z, r.src.Z)
    };
}
