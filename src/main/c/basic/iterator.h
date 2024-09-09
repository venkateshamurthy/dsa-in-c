#ifndef _ITERATOR_H_
#define _ITERATOR_H_
#include <stdbool.h>
#include "linked_list.h"

/* Define state for node iterator.*/
typedef enum ITER_STATE {
    PENDING,
    IN_PROGRESS,
    COMPLETED
} ITER_STATE;

typedef struct _iter {
    ll * curr;
    ITER_STATE state;
} iterator;

iterator  iterator_init(ll*        head);
ll*       iterator_next(iterator*  it);
bool      iterator_has (iterator*  it);

#endif
