#include "linked_list_person.h"
#include <stdlib.h>
#include <stdio.h>

ll * ll_person(const person data) {
    ll * node = (ll*) malloc(sizeof(ll));
    node -> data = person_dup(data);
    return node;
}

ll * ll_persons_va(va_list ap, int count) {
    ll * head = ll_person(va_arg(ap, person));//i=0
    for (ll* link = head; --count > 0; link = link -> next) {
        link -> next = ll_person(va_arg(ap, person));
    }
    return head;
}

ll * ll_persons(int count, const person data[]) {
    int i=0;
    ll * head = ll_person(data[i++]);
    for (ll* link = head; --count > 0; link = link -> next) {
        link -> next = ll_person(data[i++]);
    }
    return head;
}

void ll_persons_display (ll* head) {
    if (head != NULL) {
        printf("person:%s\n", person_ptr_display((person *)head->data));
        ll_persons_display(head->next);
    }
}

void ll_persons_free(ll * p) {
    if (p != NULL) {
        ll_persons_free(p->next);
        free_person((person*)p->data);
        free(p);
    }
}

