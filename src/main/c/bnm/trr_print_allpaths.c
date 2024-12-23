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

    if (temp->left == NULL && temp->right == NULL) {
        for(int i = 0; i < pathLen; i++) printf("%d ", path[i]);
        printf("\n");
    } else {
       printPaths(temp->left,  pathLen);
       printPaths(temp->right, pathLen);
    }
 }

int main() {
   int items[] = {4, 2, 6, 1, 3, 5, 7};
   printf("Pre-populating known values: ");
   for (int i=0; i<7; i++) root = insert(root, items[i]);
   printPaths(root, 0);
}

