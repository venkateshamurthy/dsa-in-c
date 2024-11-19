
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
    printf("Creating Node..\n");
    NPTR nptr = allocate_node();
    printf("USN:");    scanf("%s", nptr->usn);
    printf("Name:");   scanf("%s", nptr->name);
    printf("Branch:"); scanf("%s", nptr->branch);
    printf("Sem:");    scanf("%d", &(nptr->sem));
    printf("Phone:");  scanf("%d", &(nptr->phone_no));
    return nptr;
}
//Function: Free Node
void free_node(NPTR node) {
    if (node != NULL) {
        node->usn[0]='\0';
        node->name[0]='\0';
        node->branch[0]='\0';
        node->next=NULL;
        free(node);
    }
}

void remove_node(NPTR node) {
    printf("Removing Node..%s", node->name);
    NPTR curr = head;
    NPTR prev = NULL;
    while (curr != NULL && curr != node) {
        prev = curr;
        curr = curr->next;
    }
    prev->next=curr->next;
    free_node(curr);
}

void remove_front() {
    printf("Removing front..\n");
    NPTR original_head = head;
    if (head -> next != NULL) {
        head = head->next;
    }
    free_node(original_head);
}

void remove_rear() {
    printf("Removing rear..\n");
    NPTR curr = head;
    NPTR prev = NULL;
    while (curr -> next != NULL) {
        prev = curr;
        curr = curr -> next;
    }
    free_node(curr);
    prev -> next = NULL;
}

void free_list() {
   NPTR curr = head;
   NPTR prev = NULL;
   while (curr -> next != NULL) {
       prev = curr;
       curr = curr -> next;
       free_node(prev);
    }

    if(curr != NULL)
        free_node(curr);

}

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
    printf("Prepending...\n");
    NPTR new_head = create_node();
    new_head -> next = original_head;
    return head=new_head;
}

NPTR insert_rear(NPTR first) {
    printf("Appending...\n");
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

void add_and_free_list() {
    head = create_node();
    printf("Head record : %s\n", node_to_string(head));
    head = insert_front(head);
    head = insert_front(head);
    display_list(head);
    insert_rear(head);
    insert_rear(head);
    display_list(head);
    free_list();
}

void add_and_remove_node_front_rear() {
    head = create_node();
    head = insert_front(head);
    head = insert_front(head);
    NPTR temp= insert_rear(head);
    insert_rear(head);
    insert_rear(head);
    display_list(head);
    remove_node(temp);
    display_list(head);
    remove_front();
    display_list(head);
    remove_rear();
    display_list(head);
    free_list();
}

int main() {
    add_and_remove_node_front_rear();
}
