#include "iterator.h"
#include <stdbool.h>
#include <stddef.h>
#include <assert.h>

iterator iterator_init(node* head) {
    iterator i = {head, IN_PROGRESS};
    return i;
}

iterator iterator_next(iterator it) {
    assert(it.state != PENDING && it.state != COMPLETED &&
    "Iterator may have been completed or not initialized");
    if ( it.curr!=NULL)
        it.curr = it.curr->next;
    return it;
}

bool iterator_has(iterator  iter) {
    const bool result =  iter.curr != NULL;
    if (!result) iter.state=COMPLETED;
    return result;
}

