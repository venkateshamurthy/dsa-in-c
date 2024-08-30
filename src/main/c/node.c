#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <limits.h>
#include "node.h"
#include "iterator.h"

node * node_make (data_creator dc, int n,  ...){
    node * p = (node *) malloc(sizeof(node));
    va_list ap; 
    va_start(ap, n);
    p -> data = (*dc)(ap);
    va_end(ap);
    return p;
}

node * node_link( node * p, node *c) {
    p -> next = c;
    return c;
}

void node_display(node * n, const char* context,  data_to_string stringer) {
    printf ("Displaying %s..Name:%s\n", context, (*stringer)(n->data));
}

void node_display_recursive(node * n, data_to_string stringer) {
    if(n != NULL) {
        node_display(n, "recursively", stringer);
        node_display_recursive(n->next, stringer);
    }
}

void node_display_iterative(node * n, data_to_string stringer) {
    for(iterator it = iterator_init(n); iterator_has(it);
                 it = iterator_next(it)) {
        node_display(it.curr, "iteratively", stringer);
    }
}

int node_size(node * n) {
    if (n == NULL)
        return 0;
    int _size = (n == NULL) ? 0 : 1;
    while(n -> next!=NULL) {
        _size++;
        n = n -> next;
    }
    return _size;
}

void node_free(node * n,  free_up free_er) {
    if (n -> next != NULL) {
         node_free (n -> next, free_er);
         n -> next = NULL;
    }
    
    if (n->data!=NULL) {
       (*free_er)(n->data);
    }
}

