
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char display[100];
const char * format = "USN:%s, Name:%s, Branch:%s, Sem:%d, Phone:%d";

struct Node {
    char usn[12];
    char name[25];
    char branch[25];
    int sem;
    int phone_no;
    struct Node*  next;
};

typedef struct Node* NPTR;

//Linked list head
NPTR head;

//Function to allocate a Node
NPTR allocate_node() {
    NPTR nptr = (NPTR) malloc(sizeof(struct Node));
    if (nptr == NULL) {
        printf("INSUFFICIENT MEMORY\n");
        exit(0);
    }
    nptr->next = NULL;
    return nptr;
}

//Function: Create Node  (alias for readnodedata)
NPTR create_node() {
    NPTR nptr = allocate_node();
    printf("USN:\n");    scanf("%s", nptr->usn);
    printf("Name:\n");   scanf("%s", nptr->name);
    printf("Branch:\n"); scanf("%s", nptr->branch);
    printf("Sem:\n");    scanf("%d", &(nptr->sem));
    printf("Phone:\n");  scanf("%d", &(nptr->phone_no));
    return nptr;
}
//Function: Free Node
void free_node(NPTR nptr) {  free(nptr);}

//Function: String form of the node
char * node_to_string(NPTR nptr) {
    display[0] = '\0';
    int result = sprintf(display, format, nptr->usn,
                        nptr->name, nptr->branch,
                        nptr->sem,  nptr->phone_no
                        );
    return display;
}

NPTR insert_front(NPTR original_head) {
    NPTR new_head = create_node();
    new_head -> next = original_head;
    return new_head;
}

NPTR insert_rear(NPTR first) {
    NPTR current = create_node();
    while(first->next != NULL) first = first->next;
    return first->next = current;;
}

void display_list(const NPTR current) {
    NPTR temp = current;
    while( temp -> next != NULL){
        printf("Student record : %s\n", node_to_string(temp));
        temp = temp -> next;
    }
    printf("Last record : %s\n", node_to_string(temp));
}


int main() {
    head = create_node();
    printf("Head record : %s\n", node_to_string(head));
    head = insert_front(head);
    display_list(head);
    insert_rear(head);
    display_list(head);
    free_node(head);
}