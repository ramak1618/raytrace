#include "../../include/utils/random.h"

/*
 * Refer to https://github.com/imneme/pcg-c-basic/blob/master/pcg32x2-demo.c
 * This algorithm is slightly modified to generate random mantissa for double, 
 * instead of 64-bit int.
 */
double uniform_unit_double(pcg32_gen_pair* rng) {

    // lower 32 bits of mantissa
    uint64_t lo = (uint64_t) pcg32_random_r(&rng->gen1);

    // higher 20 bits of mantissa
    uint64_t hi = (uint64_t) pcg32_boundedrand_r(&rng->gen2, 1 << 20);

    // Set sign as 0, true exponent as 0
    uint64_t val = (0x3FFULL << 52) | (hi << 32) | lo;
    
    /*
     * val, when read as double, reads a random number in the range [1.0, 2.0)
     * The reasoning is that, if we directly generate random numbers in the range [0.0, 1.0),
     * denormalized numbers are over-represented.
     * All numbers in the range [1.0, 2.0) have the same exponent, and hence are equally spaced apart
     */

    union {
        uint64_t as_int64;
        double as_double;
    } converter;
    converter.as_int64 = val;

    // subtract 1 to get the range [0.0, 1.0)
    return converter.as_double - 1.0;
}
