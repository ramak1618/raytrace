#include <raycore/utils/misc.h>

bool any3_under_threshold(double x, double y, double z, double thresh) {
    return x <= thresh || y <= thresh || z <= thresh;
}

bool any3_over_threshold(double x, double y, double z, double thresh) {
    return x >= thresh || y >= thresh || z >= thresh;
}
