#include <stdlib.h>

#include "vector.h"
vector* vector_new(double x, double y, double z) {
    vector* a = malloc(sizeof(vector));
    a->x = x;
    a->y = y;
    a->z = z;
    return a;
}