#include "vector.h"
vector* vector_add(vector* a, vector* b) {
    return vector_new(a->x+b->x, b->y+a->y, a->z + b->z);
}