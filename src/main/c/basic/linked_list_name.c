#include "linked_list_name.h"
#include <stdlib.h>
#include <stdio.h>

ll * ll_name(const name data) {
    ll * node = (ll*) malloc(sizeof(ll));
    node -> data = name_dup(data);
    return node;
}

ll * ll_names_va(va_list ap, int count) {
    ll * head = ll_name(va_arg(ap, name));//i=0
    for (ll* link = head; --count > 0; link = link -> next) {
        link -> next = ll_name(va_arg(ap, name));
    }
    return head;
}

ll * ll_names(int count, const name data[]) {
    int i=0;
    ll * head = ll_name(data[i++]);
    for (ll* link = head; --count > 0; link = link -> next) {
        link -> next = ll_name(data[i++]);
    }
    return head;
}

void ll_names_display (ll* head) {
    if (head != NULL) {
        printf("name:%s\n", name_ptr_display((name *)head->data));
        ll_names_display(head->next);
    }
}

void ll_names_free(ll * p) {
    if (p != NULL) {
        ll_names_free(p->next);
        name_free((name*)p->data);
        free(p);
    }
}

