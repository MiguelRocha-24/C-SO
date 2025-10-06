//
// Created by miguel-rocha on 10/2/25.
//

#include <stdio.h>

int main() {
    int i, j, *p, *q;
    i = 5;
    p = &i;
    *p = 7;
    printf("i=%d, p=%p", i, p);
    j = 3;
    p = &j;
    q = p;
    p = &i;
    *q = 2;
    return 0;
}
