#ifndef RANDOM_H
#define RANDOM_H

#include "pcg/pcg_basic.h"

struct pcg32_gen_pair_t {
    pcg32_random_t gen1;
    pcg32_random_t gen2;
};
typedef struct pcg32_gen_pair_t pcg32_gen_pair;

// generate a random double from uniform distribution in the unit interval
// i.e. [0.0, 1.0)
double uniform_unit_double(pcg32_gen_pair* rng);

#endif
