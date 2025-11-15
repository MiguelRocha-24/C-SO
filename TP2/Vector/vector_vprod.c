#include "vector.h"
vector* vector_vprod(vector* a, vector* b) {
    double c,d,e;
    c = a->y * b->z - a->z*b->y;
    d = -(a->x*b->z-b->x*a->z);
    e = a->x*b->y-b->x*a->y;
    return vector_new(c,d,e);
}