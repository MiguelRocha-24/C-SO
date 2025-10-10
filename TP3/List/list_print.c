#include <stdio.h>

#include "list.h"
void list_print(list *l) {
    if (l->size == 0){return;}
    node*p = l->first;
    while (p->next != NULL) {
        printf("%i - ", p->val);
        p = p->next;
    }
    printf("%i \n", p->val);
}