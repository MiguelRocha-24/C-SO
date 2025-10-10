//
// Created by miguel on 10/10/25.
//

#ifndef SO_COMPLEX_H
#define SO_COMPLEX_H
typedef struct {
    double x;
    double y;
} complex;


complex complex_new(double,double);
complex complex_add(complex,complex);
complex complex_sub(complex,complex);
complex complex_mul(complex,complex);
complex complex_div(complex,complex);
complex complex_conj(complex);
double complex_mod(complex);
double complex_arg(complex z);
double complex_re(complex z);
double complex_im(complex z);


#endif //SO_COMPLEX_H