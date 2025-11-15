#include <stdlib.h>

#include "complex.h"
complex* complex_div(complex* z, complex* w){
    complex * conj = complex_conj(w);
    complex* size = complex_mul(w, conj);
    double s = size->x;
    complex* ans = complex_mul(z, conj);
    free(conj);
    free(size);
    ans->x/=s;
    ans->y/=s;
    return ans;
}