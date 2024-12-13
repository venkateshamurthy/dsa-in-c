
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
int num=0;
//Function: Create Node  (alias for readnodedata)
NPTR create_node() {
    printf("Creating Node..\n");
    NPTR nptr = (NPTR) malloc(sizeof(struct Node));
    if (nptr == NULL) {
        printf("INSUFFICIENT MEMORY\n");
        exit(0);
    }
    nptr->next = NULL; // First make sure to set the next/link pointer to be NULL
    const int expected_num_args = 5;
    int received_num_args =0;
    while (received_num_args != expected_num_args) {
        printf("Make sure to Enter all %d args with space seperated for : USN Name Branch Sem Phone\n",
        expected_num_args);
        char buf[50];
        num++;
        sprintf(buf, "usn%d n%d b%d %d %d", num, num, num, num, num);
        printf("Values:%s\n", buf);
        received_num_args = sscanf(buf, "%s %s %s %d %d",
                            nptr->usn, nptr->name, nptr->branch,
                            &(nptr->sem), &(nptr->phone_no));
    }
    return nptr;
}

//Function: Free Node
void free_node(NPTR node) {
    if (node != NULL) {
        printf ("Freeing %s\n", node->name);
        free(node);
    }
}
// Function removing any nde in the middle
void remove_node(NPTR node) {
    printf("Removing Node..%s\n", node!=NULL?node->name:"LAST Node");
    if (head != NULL && node == head) {
        printf("Head node removal %s\n", head->name);
        head = head -> next;
    } else if (node != NULL) {
        NPTR curr = head;
        NPTR prev = NULL;
        while (curr != node) {
            prev = curr;
            curr = curr -> next;
        }
        prev -> next = curr->next;
    }
    free_node(node);
}

// Function : Remove the front node or the head node
void remove_front() {
    printf("Removing front..\n");
    remove_node(head);
}

void remove_rear() {
    NPTR curr = head;
    NPTR prev = NULL;
    printf("Removing rear..\n");
    while (curr -> next != NULL) {
        prev = curr;
        curr = curr -> next;
    }
    prev -> next = NULL;
    free_node(curr);
}

//Function: Free the complete list
void free_list() {
   NPTR curr = head;
   NPTR prev = NULL;
   while (curr -> next != NULL) {
       prev = curr;
       curr = curr -> next;
       free_node(prev);
   }

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

NPTR insert_front() {
    printf("Prepending...\n");
    NPTR new_head = create_node();
    new_head -> next = head;
    return head = new_head;
}

NPTR insert_rear() {
    printf("Appending...\n");
    NPTR curr = head;
    NPTR prev = NULL;
    while(curr -> next != NULL) curr = curr->next;
    return curr ->next = create_node();
}

void display_list() {
    NPTR curr = head;
    while( curr -> next != NULL){
        printf("Student record : %s\n", node_to_string(curr));
        curr = curr -> next;
    }
    printf("Student record : %s\n", node_to_string(curr));
}

void add_and_free_list() {
    head = create_node();
    printf("Head record : %s\n", node_to_string(head));
    head = insert_front();
    head = insert_front();
    display_list();
    insert_rear();
    insert_rear();
    display_list();
    free_list();
}

void add_and_remove_node_front_rear() {
    head = create_node();
    head = insert_front();
    head = insert_front();
    insert_rear();
    insert_rear();
    insert_rear();
    display_list();
    remove_node(head->next->next);
    display_list();
    remove_front();
    display_list();
    remove_rear();
    display_list();
    free_list();
}

int main() {
    add_and_remove_node_front_rear();
}

