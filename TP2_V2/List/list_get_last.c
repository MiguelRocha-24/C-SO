#include <stddef.h>

#include "list.h"
int list_get_last(list *l) {
    if (l->size == 0){return -1;}
    node* iter = l->first;
    while (iter->next != NULL) {
        iter = iter->next;
    }
    return iter->val;
}
