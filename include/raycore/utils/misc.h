#ifndef MISC_H
#define MISC_H

#include <stdbool.h>

// if any of the three given values satisfy threshold, return true
bool any3_under_threshold(double x, double y, double z, double thresh);
bool any3_over_threshold(double x, double y, double z, double thresh);

#endif
