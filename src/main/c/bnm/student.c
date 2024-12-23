#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node* NPTR;
struct Node {
    char usn[12];
    char name[25];
    char branch[25];
    int  sem;
    int  phone_no;
    NPTR  next;
};

//Linked list head - to start iterating
NPTR head = NULL;

//Function: Create Node  (alias for read node data)
NPTR create_node() {
    NPTR temp = (NPTR) malloc(sizeof(struct Node));
    temp -> next = NULL;//temp -> prev = NULL;
    printf("Enter: USN Name Branch Sem Phone\n");
    scanf("%s %s %s %d %d",
           temp->usn, temp->name, temp->branch,
           &(temp->sem), &(temp->phone_no));
    return temp;
}

// Insert from rear
NPTR insert_rear() {
    NPTR node = create_node();
    if (head == NULL) {  // if this is the first time
        head = node;     // then make it head
        return node;
    }
    NPTR  tail = head;
    while (tail->next != NULL) tail = tail->next;
    tail->next = node;

    //node->prev = tail;
    return node;
}

// Function : Remove the front node or the head node and reassign the head
void remove_front() {
    if (head == NULL) return;
    printf("Removing front..\n");
    NPTR current_head = head;
    head = head->next;
    free(current_head);
}

void remove_rear() {
    if (head == NULL) return;
    NPTR curr = head;  //start from head and reach the tail
    NPTR prev = head;
    while (curr -> next != NULL) {
        prev = curr;
        curr = curr -> next;
    }
    // at this stage
    // prev will be last but one node and curr will be last node
    prev -> next = NULL;
    free(curr);
    if(prev == head) head = NULL;
}

//Function: String form of the node
void print() {
    int count = 0;
    if (head != NULL) {
        for (NPTR temp = head; temp!=NULL; temp = temp->next) {
             printf("USN:%s, Name:%s, Branch:%s, Sem:%d, Phone:%d\n",
             temp->usn, temp->name, temp->branch, temp->sem,  temp->phone_no);

             count++;
        }
    }
    printf("List has %d node\n", count);
}



int main() {
    int choice = 0;
    int N = 0;
    while(1) {
        printf("Enter one of the choice\n");
        printf(" 0. Exit. 1. Create. 2. Display. 3. Remove rear 4. Remove front\n");
        printf(" 5. Insert rear \n");
        scanf("%d", &choice);
        switch(choice) {
            case 0:  {printf ("Exiting the program\n"); exit(0);}
            case 1:  {
                          printf("Enter number of nodes:");
                          scanf("%d",&N);
                          for (int i = 1; i<= N; i++) {
                             printf("Adding %d of %d Nodes..\n",i, N);
                             insert_rear();
                          }
                          printf("Done creating list of %d nodes\n",N);
                          break;
                     }
            case 2:  {print();        break;}
            case 3:  {remove_rear();  break;}
            case 4:  {remove_front(); break;}
            case 5:  {insert_rear();  break;}
            default: {printf("Invalid choice. please enter between 0 to 5\n");}
        }
    }
}

/*
NPTR insert_front() {
    NPTR node = create_node();
    node -> next = head; //existing head assign
    head = node;
    return head;
}
*/

