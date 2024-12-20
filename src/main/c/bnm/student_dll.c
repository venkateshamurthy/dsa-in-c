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
    NPTR temp = (NPTR) malloc(sizeof(struct Node));
    temp->prev = NULL;
    temp->next = NULL;
    printf("Enter: USN Name Branch Sem Phone\n");
    scanf("%s %s %s %d %d",
           temp->usn, temp->name, temp->branch,
           &(temp->sem), &(temp->phone_no));
    return temp;
}

// Function : Remove the front node or the head node
void remove_front() {
    if (head == NULL) return;
    NPTR current_head = head;
    head = head->next;
    free(current_head);
    if (head != NULL) head->prev = NULL;
}

void remove_rear() {
    if (head == NULL) return;
    // start from head and reach tail
    NPTR cur = head;
    while (cur -> next != NULL) cur = cur -> next;

    NPTR prev = cur->prev;        //get previous to tail
    if (prev == NULL) head = NULL; // if previous is null then head should become nULL
    else prev->next = NULL;
    free(cur);
}

void print() {
    int count = 0;
    if (head != NULL ) {
        for (NPTR temp = head; temp!=NULL; temp = temp->next) {
             printf("USN:%s, Name:%s, Branch:%s, Sem:%d, Phone:%d\n",
             temp->usn, temp->name, temp->branch, temp->sem,  temp->phone_no);

             count++;
        }
    }
    printf("List has %d nodes\n", count);
}

NPTR insert_front() {
    NPTR node = create_node();
    if (head != NULL) head->prev = node;
    node->next = head;
    head = node;
    return node;
}

NPTR insert_rear() {
    NPTR node  = create_node();
    if (head == NULL) {
        head = node;
        return node;
    }
    NPTR  tail = head;
    while(tail->next != NULL) tail = tail->next;
    tail->next = node;

    node->prev = tail;
    return node;
}

int main() {
    int choice=0;
    int N=0;
    while(1) {
        printf("Enter one of the choice\n");
        printf(" 0. Exit. 1. Create. 2. Display. 3. Remove rear 4. Remove front\n");
        printf(" 5. Insert front 6. Insert rear.\n");
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
            case 2:  {print();    break;}
            case 3:  {remove_rear();  break;}
            case 4:  {remove_front(); break;}
            case 5:  {insert_front(); break;}
            case 6:  {insert_rear();  break;}
            default: {printf("Invalid choice. please enter between 0 to 6\n");}
        }
    }
}


