#include "vector.h"
#include <math.h>
double vector_mod(vector* a) {
    return sqrt(a->x * a->x + a->y * a->y + a->z * a->z);
}