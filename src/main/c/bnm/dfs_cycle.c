#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

int N;
int a[MAX][MAX];
int visited[MAX] = {0};

void createGraph() {
   printf("Enter the number of vertices (N): ");
   scanf("%d", &N);
   printf("Enter the adjacency matrix:\n");
   for (int i = 1; i <= N; i++)
      for (int j = 1; j <= N; j++)
          scanf("%d", &a[i][j]);
}

int dfsVisited[MAX] = {0};
void dfs(int i) {
   visited[i] = true;
   printf("%d ", i);

   dfsVisited[i] = true;
   for (int j = 1; j <= N; j++){
       if (a[i][j] && ! visited[j])
           dfs(j);
       else if (a[i][j] && dfsVisited[j]) {
           printf("%d\ncycle detected at %d\n", j, j);
           exit(-1);
       }
   }
   dfsVisited[i] = false;
}

int isCyclic() {
    printf("DFS Path: ");
    for (int i = 1; i <= N; i++)
        dfsVisited[i] = visited[i] = 0;
    for (int i = 1; i <= N; i++) {
        if ( ! visited[i])
            dfs(i);
    }
    printf("\nNo cycle detected!!\n");
    return 0;
}

int main() {
   createGraph();
   isCyclic();
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