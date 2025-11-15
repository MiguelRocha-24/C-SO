#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"

int main(void) {
    srand((unsigned)time(NULL));

    list* a = list_new();
    list_add_first(10, a);
    list_add_last(20, a);
    list_add_first(5, a);

    printf("List a: ");
    list_print(a);
    printf("first = %d, last = %d, size = %d\n",
           list_get_first(a), list_get_last(a), list_size(a));

    list_remove_first(a);
    list_remove_last(a);
    printf("After removing first and last: ");
    list_print(a);
    printf("size = %d\n", list_size(a));

    list* b = list_new_random(5, 100);
    printf("Random list b: ");
    list_print(b);
    printf("size = %d\n", list_size(b));

    return 0;
}
