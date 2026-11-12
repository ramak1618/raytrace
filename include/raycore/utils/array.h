#ifndef ARRAY_H
#define ARRAY_H

#include <stdint.h>
#include <stdbool.h>

struct Array_t {
    void* data;
    uint32_t elesize;
    uint32_t size;
    uint32_t capacity;
};
typedef struct Array_t Array;

struct Slice_t {
    void* data;
    uint32_t size;
};
typedef struct Slice_t Slice;

Array Array_create(uint32_t elesize, uint32_t capacity);
void Array_destroy(Array* arr);
Slice Slice_from_Array(Array* arr, uint32_t start, uint32_t length);
bool Array_grow(Array* arr);
bool Array_grow_if_full(Array* arr);

#endif
