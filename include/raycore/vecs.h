#ifndef VECS_H
#define VECS_H

struct vec3_t {
    double X;
    double Y;
    double Z;
};

typedef struct vec3_t vec3;
typedef vec3 dir3;
typedef vec3 pos3;

struct ray_t {
    pos3 src;
    dir3 dir;
};

typedef struct ray_t ray;

double dot(vec3 u, vec3 v);
vec3 cross(vec3 u, vec3 v);
double magnitude(vec3 u);
vec3 dir(vec3 u);
pos3 ray_at(ray r, double t);

#endif
