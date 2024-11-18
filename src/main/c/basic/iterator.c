#include "iterator.h"
#include <stdbool.h>
#include <stddef.h>
#include <assert.h>

/* Inititialize the iterator.*/
iterator iterator_init(ll* head) {
    iterator it = {head, IN_PROGRESS};
    return it;
}

/* jump iterator by one step. */
ll* iterator_next(iterator* it) {
    if ( it -> curr != NULL) {
        it -> curr = it -> curr -> next;
    }
    return it -> curr;
}

/* jump iterator by n steps. */
ll* iterator_next_steps(iterator* it,  int* steps) {
    while ( it -> curr != NULL && *steps-- > 0) {
        it -> curr = it -> curr -> next;
    }
    return it -> curr;
}


/* whether iterator has any  more elements. */
bool iterator_has(iterator*  it) {
    bool result =  it -> curr != NULL;
    if ( ! result)
        it -> state = COMPLETED;
    return result;
}