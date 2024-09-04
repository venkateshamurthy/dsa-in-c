#include "linked_list_string.h"


ll * ll_string(const char * data) {
    ll * node = (ll*) malloc(sizeof(ll));
    node -> data = strdup(data);
    return node;
}

ll * ll_strings(int count, const char* data[]) {
    int i = 0;
    ll * head = ll_string(data[i++]);
    for (ll* link = head; --count > 0; link = link -> next) {
        link -> next = ll_string(data[i++]);
    }
    return head;
}

 
void ll_strings_display (ll* head) {
    if (head != NULL) {
        printf("\n%s,", (char *)head->data);
        ll_strings_display(head->next);
    }
}

void  free_string(char * p) {
    printf("\nclearing %s\n",p);
    free(p);
}
void ll_strings_free( ll* p){
    if(p != NULL){
        ll_strings_free(p->next);
        free_string(p->data);
        free(p);
    }
}