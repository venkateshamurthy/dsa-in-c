#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 20
int a[MAX][MAX], visited[MAX] = {false}, dfsVi[MAX]={false}, n;

void createGraph(){
   printf("\nEnter the number of cities (vertices): ");
   scanf("%d", &n);

   printf("\nEnter the adjacency matrix for the directed graph:\n");
   for (int i = 1; i <= n; i++)
       for (int j = 1; j <= n; j++)
           scanf("%d", &a[i][j]);
}

void dfs(int i){
   visited[i] = true;
   printf("%d ", i);
   for (int j = 1; j <= n; j++){
       if (a[i][j]==true && visited[j]==false)
           dfs(j);
   }
 }

 void dfs_cycle(int i){
    visited[i] = true;
    dfsVi[i] = true;
    printf("%d ", i);
    for (int j = 1; j <= n; j++){
        if (a[i][j]==true && visited[j]==false)
            dfs(j);
        else if (a[i][j]==true && dfsVi[i]==true) {
            printf("Cycle Detected\n");
            exit(0);
        }
    }
    dfsVi[i]=false;
  }


int f=0, r=-1, q[MAX]={0};
void bfs(int i) {
    q[++r] = i;
    visited[i] = true;
    while (f <= r) {
        int v = q[f++];
        printf ("%d ", v);
        for (int j = 1; j <= n; j++) {
            if (a[v][j] == 1  &&  visited[j] == 0) {
                q[++r] = j;
                visited[j] = true;
            }
        }
   }
 }

int main() {

   createGraph();

   int i;
   printf("Enter the starting vertex for DFS traversal: ");
   scanf("%d", &i);

   printf(" DFS in progress\n");
   for (int k=1;k<=n; k++)  {visited[k]=0; dfsVi[k]=0;}
   dfs(i);

   printf("\nBFS in progress\n");
   for (int k=1;k<=n; k++)  visited[k]=0;
   bfs(i);
   printf("\n");

   printf("DFS_CYCLE in progress\n");
   for (int k=1;k<=n; k++)  {visited[k]=0; dfsVi[k]=0;}
   for (int k=1;k<=n; k++)  {
       if (visited[k]==false) dfs_cycle(k);
   }


}
/*
Enter the number of vertices: 5
Enter graph data in matrix form:
  1 2 3 4 5
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