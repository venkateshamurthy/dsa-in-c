// Tree.c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

typedef struct Node * NPTR;

NPTR create_node(int info) {
    NPTR temp = (NPTR) malloc(sizeof(struct Node));
    temp->data = info;
    temp->left = temp->right = NULL;
    return temp;
}

NPTR insert(NPTR temp, int item) {
    if (temp == NULL) return temp = create_node(item);
    if (item == temp->data) return temp;
    if (item <  temp->data)
         temp->left = insert(temp->left, item);
    else
         temp->right = insert(temp->right, item);
    return temp;
}

int search(NPTR temp, int item) {
    while (temp != NULL) {
        if (item == temp->data)  return 1;
        temp = (item < temp->data) ? temp->left : temp->right;
    }
    return 0;
}

// L-->N-->R
void inorder(NPTR temp) {
    if (temp != NULL) {
        inorder(temp->left);
        printf("%d\t", temp->data);
        inorder(temp->right);
    }
}

// N-->L-->R
void preorder(NPTR temp) {
     if (temp != NULL) {
         printf("%d\t", temp->data);
         preorder(temp->left);
         preorder(temp->right);
     }
}

 // L-->R-->N
void postorder(NPTR temp) {
     if (temp != NULL) {
         postorder(temp->left);
         postorder(temp->right);
         printf("%d\t", temp->data);
     }
 }

int main () {
    NPTR root = NULL;
    int choice, value, key;
    while(1) {
        printf("-- Binary Search Tree Menu ---\n");
        printf("0. Exit 1. Insert 2. Preorder 3. Inorder 4. Postorder 5. Search \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        /*             4
               2               6
          1         3      5        7
        */
        switch (choice) {
            case 0:   {printf("Exiting program\n");exit(0);}

            case 1:   {printf("Enter the element to insert: ");
                      scanf("%d", &value);
                      root = insert(root, value);
                      break;}

            case 2:   {if (root == NULL) printf("The tree is empty.\n");
                      else	{printf("Pre-order:\n"); preorder(root);}
                      break;}

            case 3:   {if (root == NULL) printf("The tree is empty.\n");
                      else {printf("In-order:\n");inorder(root);}
                      break;}

           case 4:    {if (root == NULL) printf("The tree is empty.\n");
                      else {printf("Post-order:\n");postorder(root);}
                      break;}

           case 5:    {if (root == NULL) printf("The tree is empty.\n");
                  	  printf("Enter the element to search: ");
                   	  scanf("%d", &key);
                   	  int found = search(root, key);
                      printf("Element %d is %s in the BST.\n", key, found ? "present" : "absent");
                      break;}

            default:  printf("Invalid choice. Please try again.\n");
        }
        printf("\n");
    }
    return 0;
}
