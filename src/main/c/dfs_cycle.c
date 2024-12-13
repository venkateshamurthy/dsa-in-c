#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

int N;
int a[MAX][MAX];
int visited[MAX];
int dfsVi[MAX];

void createGraph() {
   printf("Enter the number of vertices (N): ");
   scanf("%d", &N);
   printf("Enter the adjacency matrix:\n");
   for (int i = 0; i < N; i++)
       for (int j = 0; j < N; j++)
           scanf("%d", &a[i][j]);
}

void dfs(int i) {
   visited[i] = true;
   dfsVi[i] = true;

   for (int j = 0; j < N; j++) {
      if (a[i][j] == true && visited[j] == false)
           dfs(j);
      else if (a[i][j] == true && dfsVi[j] == true) {
           printf("Cycle Detected\n");
           exit(0);
      }
   }
   dfsVi[i] = false;
}

int isCyclic() {
   for (int i = 0; i < N; i++) { visited[i] = 0;dfsVi[i] = 0;}
   for (int i = 0; i < N; i++) {
       if (visited[i] == false)
           dfs(i);
   }
   return 0;
}

int main() {
   createGraph();
   isCyclic();
   printf("No Cycle Detected\n");
   return 0;
}

/*
OUTPUT:
Enter the number of vertices (N): 6
Enter the adjacency matrix:
0 1 0 0 0 0
0 0 1 0 0 1
0 0 0 0 1 0
0 0 1 0 0 0
0 0 0 1 0 0
0 0 0 0 0 0
Cycle Detected

OUTPUT:
Enter the number of vertices (N): 4
Enter the adjacency matrix:
0 1 0 0
0 0 0 0
0 1 0 0
0 1 1 0
No Cycle Detected
*/