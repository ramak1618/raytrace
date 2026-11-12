#include <raycore/utils/array.h>

#include <stdlib.h>

Array Array_create(uint32_t elesize, uint32_t capacity) {
    Array r = {
        .data = malloc(elesize * capacity),
        .elesize = elesize,
        .size = 0,
        .capacity = capacity,
    };
    if(r.data == NULL)
        return (Array) {0};
    return r;
}

void Array_destroy(Array* arr) {
    if(arr->data)
        free(arr->data);
    *arr = (Array) {0};
}

Slice Slice_from_Array(Array* arr, uint32_t start, uint32_t length) {
    return (Slice) {
        .data = (char*)arr->data + arr->elesize*start,
        .size = length
    };
}

bool Array_grow(Array* arr) {
    uint32_t new_cap = arr->capacity * 2;
    void* tmp = realloc(arr->data, new_cap*arr->elesize);
    if(tmp == NULL) {
        return false;
    }

    arr->capacity = new_cap;
    arr->data = tmp;

    return true;
}

bool Array_grow_if_full(Array* arr) {
    if(arr->size == arr->capacity) {
        return Array_grow(arr);
    }
    return true;
}
