#include <stdio.h>

#include "list.h"

int main() {
    list* l = list_new();
    list_add_first(1, l);
    list_add_last(2, l);
    list_add_last(3, l);
    int i = list_get_first(l);
    int j = list_get_last(l);
    list_print(l);
    list_remove_first(l);
    list_print(l);
    list_remove_last(l);
    list_print(l);
    int k = list_size(l);
    list_print(l);
    printf("%i - %i - %i \n", i,j,k);

    return 0;
}