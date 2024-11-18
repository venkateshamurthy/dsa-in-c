#include "linked_list.h"
#include "iterator.h"
#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


ll * ll_from_va(node_fabricator fa, int count, ...) {
    va_list ap;
    va_start(ap, count);
    ll * node = (*fa)(ap, count);
    va_end(ap);
    return head = node;
}

void ll_free(ll* node, free_data free_er) {
    if (node != NULL) {
        ll_free(node->next, free_er);
        (*free_er)(node->data);
        free(node);
    }
}

void ll_display(ll* node, char * context, to_string tos) {
    if (node != NULL) {
        printf("%s: %s\n",context, (*tos)(node->data));
        ll_display(node->next, context, tos);
    }
}


void ll_display_iterate(ll* node, char * context, to_string tos) {
    for (iterator it = iterator_init(node); iterator_has(&it); node = iterator_next(&it)) {
        printf("%s: %s\n",context, (*tos)(node->data));
    }
}

ll * ll_insert(ll * current, ll * new_node) {
    ll * next_node = current -> next;
    new_node -> next  = next_node;
    current -> next = new_node;
    return current;
}

ll * ll_append(ll * appending_node) {
    ll * last = ll_last(head);
    return ll_insert(last, appending_node);
}

ll * ll_prepend(ll * prepending_node) {
    prepending_node -> next = head;
    return head = prepending_node;
}

bool ll_remove(ll * removing_node, equalizer equalizer, free_data free_er) {
    ll * p = head;
    ll *old=p;
    for(iterator it = iterator_init(p); iterator_has(&it);
             p = iterator_next(&it)) {
        if (p == removing_node || (*equalizer)(removing_node->data, p->data)) {
            
            return true;
        }
    }
}

ll * ll_last  (const ll * node) {
    if (node == NULL)
        return NULL;
    ll* link = (ll*) node;
    while (link -> next != NULL) {
        link = link -> next;
    }
    return link;
}

ll * ll_middle (const ll * node) {
    ll* fast = (ll*)node;
    ll* slow = (ll*)node;
    while(fast && fast -> next && fast -> next -> next) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}

ll * ll_last_n (const ll * node, int n) {
    ll* fast = (ll*) node;
    ll* slow = (ll*) node;
    while (--n > 0 && fast) fast = fast -> next;
    while (fast -> next) {
        slow = slow -> next;
        fast = fast -> next;
    }
    return slow;
}

int sizeof_ll (const ll * node) {
    if (node == NULL) return 0;
    int sz = 1;
    ll* link = (ll*) node;
    while (link -> next != NULL) {
        link = link -> next;
        sz++;
    }
    return sz;
}

ll * ll_detect_loop (const ll * node, bool break_free_loop) {

    ll * fast = (ll*)node, * normal = (ll*)node;
    bool loop_detected = false;

    while ( !loop_detected && fast != NULL && fast->next != NULL && normal->next != NULL) {
        normal = normal->next;
        fast = fast->next->next;
        loop_detected = fast == normal;
    }

    if (loop_detected) {

        // Break free the loop if break_free_loop is passed as true
        if (break_free_loop) {
            normal = (ll*)node;
            ll * previous_to_fast = fast;
            while (normal != fast) {
                normal = normal -> next;
                previous_to_fast = fast;
                fast = fast -> next;
            }
            previous_to_fast -> next = NULL;
        }
    }

    // return the intersection/meeting node if as long as loop is detected
    return normal;
}











