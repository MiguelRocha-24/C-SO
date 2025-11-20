#include "list.h"
void list_remove_last(list *l) {
    if (l->size == 0){return;}
    node* p = l->first;

    if (l->size == 1) {
        free(p);
        l->first = NULL;
    }
    else {
        while (p->next->next != NULL) {
            p = p->next;
        }
        free(p->next);
        p->next = NULL;
    }
    l->size--;
}