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

    // Check if path exists between p and q;
    printf ("Checking path between start and destination using DFS:\n");
    int p, q;
    printf("Enter start and destination : ");
    scanf("%d %d", &p, &q);
    bool found = isPathExists(p, q);
    printf("\nPath between %d and %d : %s \n",
    p, q, (found ? "present" : "absent"));
}
/*
Enter the number of vertices (N): 6
Enter the adjacency matrix:
0 1 0 0 0 0
0 0 1 0 0 1
0 0 0 0 1 0
0 0 1 0 0 0
0 0 0 1 0 0
0 0 0 0 0 0

Checking path between start and destination using DFS:
Enter start and destination : 3 5
3 2 4
Path between 3 and 5 : absent
*/