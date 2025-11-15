#include <stddef.h>
#include <stdio.h>

#include "list.h"

void list_print(list* l) {
    node* a = l->first;
    while (a!= NULL) {
        printf("%i\n", a->val);
        a = a->next;
    }
}