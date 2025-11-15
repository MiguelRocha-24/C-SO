#include "vector.h"

double vector_sprod(vector* a, vector* b) {
    return a->x*b->x + b->y * a->y + a->z * b->z;
}