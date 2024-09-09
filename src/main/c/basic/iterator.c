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
    ll * node = NULL;
    if ( it -> curr != NULL) {
        node = it -> curr;
        it -> curr = it -> curr -> next;
    }
    return node;
}

/* whether iterator has any  more elements. */
bool iterator_has(iterator*  it) {
    bool result =  it -> curr != NULL;
    if ( ! result)
        it -> state = COMPLETED;
    return result;
}