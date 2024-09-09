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
    ll * head = (*fa)(ap, count);
    va_end(ap);
    return head;
}

void ll_free( ll* p, free_data free_er) {
    if (p != NULL) {
        ll_free(p->next, free_er);
        (*free_er)(p->data);
        free(p);
    }
}

void ll_display(ll* p, char * context, to_string tos) {
    if (p != NULL) {
        printf("%s: %s\n",context, (*tos)(p->data));
        ll_display(p->next, context, tos);
    }
}

void ll_display_iterate(ll* p, char * context, to_string tos) {
    for (iterator it = iterator_init(p); iterator_has(&it); p = iterator_next(&it)) {
        printf("%s: %s\n",context, (*tos)(p->data));
    }
}

ll * ll_insert(ll * current, ll * new_node) {
    ll * next_node = current -> next;
    new_node -> next  = next_node;
    current -> next = new_node;
    return current;
}
ll * ll_last  (const ll * head) {
    if (head == NULL)
        return NULL;
    ll* link = (ll*) head;
    while (link -> next != NULL) {
        link = link -> next;
    }
    return link;
}

ll * ll_middle (const ll * head) {
    ll* fast = (ll*)head;
    ll* slow = (ll*)head;
    while(fast && fast -> next && fast -> next -> next) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}

ll * ll_last_n (const ll * head, int n) {
    ll* fast = (ll*) head;
    ll* slow = (ll*) head;
    while (--n > 0 && fast) fast = fast -> next;
    while (fast -> next) {
        slow = slow -> next;
        fast = fast -> next;
    }
    return slow;
}

int sizeof_ll (const ll * head) {
    if (head == NULL) return 0;
    int sz = 1;
    ll* link = (ll*) head;
    while (link -> next != NULL) {
        link = link -> next;
        sz++;
    }
    return sz;
}

ll * ll_detect_loop (const ll * head, bool break_free_loop) {

    ll * fast = (ll*)head, * normal = (ll*)head;
    bool loop_detected = false;

    while ( !loop_detected && fast != NULL && fast->next != NULL && normal->next != NULL) {
        normal = normal->next;
        fast = fast->next->next;
        loop_detected = fast == normal;
    }

    if (loop_detected) {

        // Break free the loop if break_free_loop is passed as true
        if (break_free_loop) {
            normal = (ll*)head;
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











