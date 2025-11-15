#include "vector.h"
vector* vector_scale(double a, vector* b) {
    return vector_new(b->x*a, b->y *a, b->z*a);
}