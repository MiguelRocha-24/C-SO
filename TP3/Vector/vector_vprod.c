#include "vector.h"
vector* vector_vprod(vector*a, vector*b) {
    double c = a->y * b->z - a->z * b->y;
    double d = a->z * b->x - a->x * b->z;
    double e = a->x * b->y - a->y * b->x;
    return vector_new(c,d,e);
}