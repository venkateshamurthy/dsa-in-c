#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <limits.h>
#include <assert.h>
#include <stdbool.h>
#include "node.h"
#include "iterator.h"
#include "utils.h"

node * node_allocate(data_creator dc, va_list* ap) {
    node * root = (node *) malloc(sizeof(node));
    root -> data = (*dc)(ap);
    root -> next = NULL;
    return root;
}

node * node_va_data(data_creator dc, int count, va_list* ap) {
      node * root = node_allocate(dc, ap);
      // Please note the use of pre-decrement on count as root get allocated outside the loop
      for (node * p = root; --count > 0; p = p -> next) {
          p -> next = node_allocate(dc, ap);
      }
      return root; // return the head/root node
}

node * node_last(node * root) {
    node * q = root;
    do { q = q -> next;} while(q->next!= NULL); //Get to the last node
    return q;
}

node * node_data (data_creator dc, int count, ...) {
    va_list ap;
    va_start(ap, count);
    node * result = node_va_data(dc, count, &ap);
    va_end(ap);
    return result;
}

node * detect_loop_in_linkedlist(node * head, bool break_free_loop) {
    node * fast = head, * normal = head;
    bool loop_detected = false;

    while ( !loop_detected && fast != NULL && fast->next != NULL && normal->next != NULL) {
        normal = normal->next;
        fast = fast->next->next;
        loop_detected = fast == normal;
    }

    if (loop_detected) {

        // Break free the loop if break_free_loop is passed as true
        if (break_free_loop) {
            normal = head;
            node * previous_to_fast = fast;
            while (normal != fast) {
                normal = normal -> next;
                previous_to_fast = fast;
                fast = fast -> next;
            }
            previous_to_fast -> next = NULL;
        }

        // return the intersection/meeting node if as long as loop is detected
        return normal;
    }

    // No loop is detected and hence return NULL
    return NULL;
}

void node_display(node * n, const char* context,  data_to_string stringer) {
    if (n!=NULL)
        printf ("Displaying %s:%s\n",  context, (*stringer)(n->data));
}

void node_display_recursive(node * n, data_to_string stringer) {
    if(n != NULL) {
        node_display(n, "recursively", stringer);
        node_display_recursive(n->next, stringer);
    }
}

void node_display_iterative(node * n, data_to_string stringer) {
    for(iterator it = iterator_init(n); iterator_has(it); it = iterator_next(it)) {
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
    
    if (n->data != NULL) {
       (*free_er)(n->data);
    }
}