#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node NODE;
typedef NODE* NPTR;
struct Node {
    int data;
    NPTR left;
    NPTR right;
};

NPTR create_node(int info) {
    NPTR temp = (NPTR) malloc(sizeof(NODE));
    temp->data = info;
    temp->left = temp->right = NULL;
    return temp;
}

int maxDepth(NPTR temp) {
    if  (temp == NULL) return 0;
    /*
    int left_depth = maxDepth(temp->left);
    int right_depth = maxDepth(temp->right);
    int child_depth=0;
    if (left_depth > right_depth)
         child_depth = left_depth;
    else
         child_depth = right_depth;
    return 1 + child_depth;
    */
    return temp == NULL
           ? 0
           : 1 + (int) fmax(maxDepth(temp->left), maxDepth(temp->right));
}

/*
               4
            /    \
          2       6
         /  \   /   \
       1    3  5     7
*/
int main() {
    NPTR root =         create_node(4);
    root->left =        create_node(2);
    root->right =       create_node(6);
    root->left->left =  create_node(1);
    root->left->right = create_node(3);
    root->right->left = create_node(5);
    root->right->right =create_node(7);
    printf("The maximum depth of the complete binary tree is: %d\n", maxDepth(root));
    return 0;
}
