#include <stddef.h>
#include <stdlib.h>

#include "list.h"

void list_remove_last(list *l) {
    node*a = l->first;
    while (a->next->next != NULL) {
        a = a->next;
    }
    node* t = a->next;
    a->next = NULL;
    free(t);
    l->size--;
}