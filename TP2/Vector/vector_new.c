#include <stdlib.h>

#include "vector.h"

vector* vector_new(double a, double b, double c) {
    vector * ans = (vector*) malloc(sizeof(vector));
    ans->x = a;
    ans->y = b;
    ans->z = c;
    return ans;
}