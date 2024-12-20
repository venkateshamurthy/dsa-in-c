#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    char usn[12];
    char name[25];
    char branch[25];
    int sem;
    int phone_no;
    struct Node*  next;
};

typedef struct Node* NPTR;

//Linked list head - to start iterating
NPTR head;

//Function: Create Node  (alias for read node data)
NPTR create_node() {
    NPTR temp = (NPTR) malloc(sizeof(struct Node));
    temp -> next = NULL;
    printf("Please enter all args in this style : USN Name Branch Sem Phone\n");
    scanf("%s %s %s %d %d",
           temp->usn, temp->name, temp->branch,
           &(temp->sem), &(temp->phone_no));
    return temp;
}

//Function: Free Node
void free_node(NPTR node) {
    if (node != NULL) {
        free(node);
    }
}

// Function : Remove the front node or the head node and reassign the head
void remove_front() {
    if (head == NULL) return;
    printf("Removing front..\n");
    NPTR current_head = head;
    head = head->next;
    free_node(current_head);
}

void remove_rear() {
    if (head == NULL) return;
    NPTR cur_tail = head;  //start from head and reach the tail
    NPTR new_tail = head;
    printf("Removing rear..\n");
    while (cur_tail -> next != NULL) {
        new_tail = cur_tail;
        cur_tail = cur_tail -> next;
    }
    new_tail -> next = NULL;// by this new tail will become actual tail
    free_node(cur_tail);//remove current tail
    if(new_tail == head) head = NULL;
}

//Function: Free the complete list
void free_list() {
   if (head == NULL) return;
   NPTR curr = head;
   NPTR prev = NULL;
   while (curr -> next != NULL) {
       prev = curr;
       curr = curr -> next;
       free_node(prev);
   }
   free_node(curr);
   printf("List cleared..\n");
}

//Function: String form of the node
const char * format = "USN:%s, Name:%s, Branch:%s, Sem:%d, Phone:%d\n";
void print() {
    if (head != NULL) {
        for (NPTR temp = head; temp!=NULL; temp = temp->next) {
            printf(format, temp->usn, temp->name, temp->branch,
                           temp->sem,  temp->phone_no);
        }
    } else printf("No nodes in the list\n");
}

NPTR insert_front() {
    NPTR new_head = create_node();
    new_head -> next = head; //existing head assign
    head = new_head;
    return head;
}

NPTR insert_rear() {
    NPTR new_tail = create_node();
    if (head != NULL) {
        NPTR  tail = head;
        while (tail->next != NULL) tail = tail->next;
        tail->next = new_tail;
    } else
        head = new_tail;
    return new_tail;
}

int main() {
    int choice=0;
    int N=0;
    while(1) {
        printf("Enter one of the choice\n");
        printf(" 0. Exit. 1. Create. 2. Display. 3. Remove rear 4. Remove front\n");
        printf(" 5. Insert front 6. Insert rear 7. Free \n");
        scanf("%d", &choice);
        switch(choice) {
            case 0:  {printf ("Exiting the program\n"); exit(0);}
            case 1:  {
                          printf("Enter number of nodes:");
                          scanf("%d",&N);
                          for(int i = 1; i<= N; i++) {
                            printf("Adding %d of %d Nodes..\n",i, N);
                            insert_rear();
                          }
                          printf("Done creating list of %d nodes\n",N);
                          break;
                     }
            case 2:  {print();        break;}
            case 3:  {remove_rear();  break;}
            case 4:  {remove_front(); break;}
            case 5:  {insert_front(); break;}
            case 6:  {insert_rear();  break;}
            case 7:  {free_list();    break;}
            default: {printf("Invalid choice. please enter between 0 to 7\n");}
        }
    }
}

