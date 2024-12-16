#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    char usn[12];     //char*  usn = malloc(12*sizeof(char));
    char name[25];
    char branch[25];
    int sem;
    int phone_no;
    struct Node*  next;
    struct Node*  prev;
};

typedef struct Node* NPTR;

//Linked list head
NPTR head;

//Function: Create Node  (alias for readnodedata)
NPTR create_node() {
    printf("Creating Node..\n");
    NPTR nptr = (NPTR) malloc(sizeof(struct Node));
    if (nptr == NULL) {
        printf("INSUFFICIENT MEMORY\n");
        exit(0);
    }
    // First make sure to set the next/prev pointer to be NULL
    nptr->prev = NULL;
    nptr->next = NULL;

    printf("Make sure to Enter all args with space seperated for : USN Name Branch Sem Phone\n");
    int received_num_args = scanf("%s %s %s %d %d",
                                   nptr->usn, nptr->name, nptr->branch,
                                   &(nptr->sem), &(nptr->phone_no));
    return nptr;
}


//Function: Free Node
void free_node(NPTR node) {
    if (node != NULL) {
        printf ("Freeing %s\n", node->name);  //Node n = ;   n.name
        node->prev = NULL;                    //Node*p = ;   p->name; (*p).name
        node->next = NULL;
        free(node);// c method
    }
}

// Function removing any nde in the middle
//remove_node(head); remove_node(tail);
void remove_node(NPTR node) {
    if (node != NULL) {
        NPTR next_node = node->next; //if node is tail then next_node is null
        NPTR prev_node = node->prev; //if node is head then prev_node is null
        if(prev_node != NULL)
            prev_node->next = next_node;  //null->next, null->name --> error
        if(next_node != NULL)
            next_node->prev = prev_node;
    }
    free_node(node);
}

// Function : Remove the front node or the head node
void remove_front() {
    if (head != NULL) {
        printf("Removing front..\n");
        NPTR next_head  = head->next;
        remove_node(head);
        head = next_head;
    }
}

void remove_rear() {
    if (head != NULL) {
        printf("Removing rear..\n");
        NPTR tail = head; // start from head and reach tail
        while (tail -> next != NULL) tail = tail -> next;
        remove_node(tail);
    }
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
char display[100];
const char * format = "USN:%s, Name:%s, Branch:%s, Sem:%d, Phone:%d";
char * node_to_string(NPTR nptr) {
    display[0] = '\0';
    sprintf(display, format,
            nptr->usn,
            nptr->name, nptr->branch,
            nptr->sem,  nptr->phone_no
            );
    return display;
}

void print( bool forward) {
    if (forward) {
        printf ("Printing from head to tail\n");
        for (NPTR node = head; node!=NULL; node = node->next)
            printf("FWD: %s\n", node_to_string(node));
    } else {
        printf ("Printing from tail to head\n");
        NPTR tail = head;
        while(tail->next!=NULL) tail = tail->next;

        for (NPTR node = tail; node != NULL; node = node->prev)
            printf("BWD: %s\n", node_to_string(node));
    }
}

NPTR insert_front() {
    NPTR node = create_node();
    if (head != NULL) {
        node->next = head;
        head->prev = node;
    }
    printf("Prepending...%s\n", node_to_string(node));
    return head = node;
}

NPTR insert_rear() {
    NPTR node  = create_node();
    NPTR  tail = head;
    while(tail->next!=NULL) tail = tail->next;
    tail->next = node;
    node->prev = tail;
    printf("Appending...%s\n", node_to_string(node));
    return node;
}

void add_and_free_list() {
    head = create_node();
    printf("Head record : %s\n", node_to_string(head));
    free_list();
}

void add_and_remove_node_front_rear() {
    insert_front();
    insert_front();
    insert_front();
    insert_rear();
    insert_rear();
    insert_rear();
    print(true);
    print(false);
    remove_front();
    remove_rear();
    print(true);
    print(false);
    free_list();
}

int main() {
    add_and_remove_node_front_rear();
    return 0;
}
