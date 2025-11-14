
#include <stdio.h>
#include <stdlib.h>
/*
void f() {
    int x;
    g(&x);
}


int* f() {
    int x;
    return &x;
}
*/
int* f() {
    int* x = (int*)malloc(sizeof(int));
    return x;
}


int g(int (*h)(int), int y) {
    return h(y + 2);
}
int h(int x) {
    return x*x;
}
int main() {
    printf("value: %d\n", g(f,2));
    return 0;
}