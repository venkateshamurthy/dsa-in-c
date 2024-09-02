#ifndef _ITERATOR_H_
#define _ITERATOR_H_
#include <stdbool.h>
#include "node.h"

/* Define state for node iterator.*/
typedef enum ITER_STATE {
    PENDING,
    IN_PROGRESS,
    COMPLETED
} ITER_STATE;

typedef struct _iter {
    node * curr;
    ITER_STATE state;
} iterator;

iterator iterator_init(node* head);
iterator iterator_next(iterator it);
bool     iterator_has(iterator  iter);
#endif
