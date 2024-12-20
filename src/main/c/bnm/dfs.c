#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 20
int a[MAX][MAX], visited[MAX] = {false}, N;

void createGraph() {
   printf("Enter the number of vertices (N): ");
   scanf("%d", &N);
   printf("Enter the adjacency matrix:\n");
   for (int i = 1; i <= N; i++)
       for (int j = 1; j <= N; j++)
           scanf("%d", &a[i][j]);
}

void dfs(int i){
   visited[i] = true;
   printf("%d ", i);

   for (int j = 1; j <= N; j++){
       if (a[i][j] && ! visited[j])
           dfs(j);
   }
}

int isPathExists(int start, int end){
    for (int i = 1; i <= N; i++)
        visited[i] = 0;
    dfs(start);
    return visited[end];
}

int main() {
        // Create Graph with Adjacency Matric
        printf ("DFS program starting:\n");
        createGraph();

        // Just plain DFS traversal from start vertex: i
        printf("Enter start vertex: ");
        int i;
        scanf("%d", &i);
        printf(" DFS in progress\n");
        dfs(i);
}
/*
Enter the number of vertices: 5
Enter graph data in matrix form:

0 0 1 1 0
1 0 0 0 0
0 1 0 0 0
0 0 0 0 1
1 0 0 0 0
Enter the starting vertex for DFS traversal: 1
DFS Traversal from 1: 1 3 2 4 5


DFS_CYCLE
0 1 0 0 0 0
0 0 1 0 0 1
0 0 0 0 1 0
0 0 1 0 0 0
0 0 0 1 0 0
0 0 0 0 0 0
*/