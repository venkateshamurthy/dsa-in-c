#include "linked_list_int.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

int * int_dup(int data) {
    return int_ptr_dup(&data);
}

int * int_ptr_dup(int* data) {
    int * data_ptr = (int *) malloc (sizeof(int));
    memcpy(data_ptr, data, sizeof(int));
    return  data_ptr;
}

void free_int(int * p) { 
    free(p);
}

ll * ll_int(int data) {
    ll * node = (ll*) malloc(sizeof(ll));
    node -> data = int_dup(data);
    return node;
}

ll * ll_ints_va(va_list ap, int count) {
    ll * head = ll_int(va_arg(ap, int));//i=0
    for (ll* link = head; --count > 0; link = link -> next) {
        link -> next = ll_int(va_arg(ap, int));
    }
    return head;
}

ll * ll_ints(int count, int data[]) {
    int i=0;
    ll * head = ll_int(data[i++]);//i=0
    for (ll* link = head; --count > 0; link = link -> next) {
        link -> next = ll_int(data[i++]);
    }
    return head;
}
char buffer[20]; 
void ll_ints_display (ll* head) {
    if (head != NULL) {
        printf("%s,", int_to_string(head->data));
        ll_ints_display(head->next);
    }
}

void ll_ints_free (ll * p) {
    if (p != NULL) {
        ll_ints_free(p->next);
        free_int((int*)p->data);
        free(p);
    }
}

char * int_to_string(void * data) {
    buffer[0]='\0';
    sprintf(buffer,"%d", *(int*)data);
    return buffer;
}