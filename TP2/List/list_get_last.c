#include <stdlib.h>

#include "list.h"

int list_get_last(list *l) {
    node* a = l->first;
    while (a->next != NULL) {
        a = a->next;
    }
    return a->val;
}
