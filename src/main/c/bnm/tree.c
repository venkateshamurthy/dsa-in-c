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
    if (temp == NULL) return create_node(item);
    if (item == temp->data)  return temp;
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

int maxDepth(NPTR temp) {
    if  (temp == NULL) return 0;
    return 1 + (int) fmax(maxDepth(temp->left), maxDepth(temp->right));
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

 /*             4
        2               6
   1         3      5        7
   // 4-->2-->1
   // 4-->2-->3
   // 4-->6-->5
   // 4-->6-->7
 */
 int path[100];
 void printPaths(NPTR temp, int pathLen) {
    if (temp == NULL) return;

    path[pathLen] = temp->data;
    pathLen++;

    if (temp->left==NULL && temp->right==NULL) {
        for(int i = 0; i < pathLen; i++) printf("%d ", path[i]);
        printf("\n");
    } else {
       printPaths(temp->left,  pathLen);
       printPaths(temp->right, pathLen);
    }
 }

void create_nodes_get_height() {
    NPTR root =         create_node(4);
    root->left =        create_node(2);
    root->right =       create_node(6);
    root->left->left =  create_node(1);
    root->left->right = create_node(3);
    root->right->left = create_node(5);
    root->right->right =create_node(7);
    printf("The maximum depth of the complete binary tree is: %d\n", maxDepth(root));
}

int main () {
    NPTR root = NULL;
    int choice, value, key;
    while(1) {
        printf("-- Binary Search Tree Menu ---\n");
        printf("0. Exit 1. Insert 2. Preorder 3. Inorder 4. Postorder 5. Search 6. Height 7. Pre-populate 8. Print all paths\n");
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

            case 6:   {printf("Height:%d \n", maxDepth(root));
                      break;}

            case 7:   {int items[] = {4, 2, 6, 1, 3, 5, 7};
                       printf("Pre-populating known values: ");
                       for (int i=0; i<7; i++) root = insert(root, items[i]);
                       break;}

            case 8:    {printf("Print all Paths:\n"); printPaths(root, 0);break;}

            default:  printf("Invalid choice. Please try again.\n");
        }
        printf("\n");
    }
    return 0;
}

