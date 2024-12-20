//BFS and DFS in DFS.C
//  ——————————-
  #include <stdio.h>
  #include <stdbool.h>

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

  int f=0, r=-1, q[MAX]={0};
  void bfs(int start) {
      q[++r] = start; //enque v and visited[v]=1
      visited[start] = true;

      while (f <= r ) {
          int i = q[f++]; //deque to i and print i
          printf ("%d ", i);

          for (int j = 1; j <= N; j++) {
              if (a[i][j]  &&  ! visited[j]) {
                  q[++r] = j;  //enque j and visited[j]=1
                  visited[j] = true;
              }
          }
      }
   }

  int main() {
    printf ("BFS program starting:\n");
    createGraph();
    printf("Enter  start vertex: \n");
    int i;
    scanf("%d", &i);
    printf("BFS in progress\n");
    bfs(i);
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
  BFS Traversal from 1: 1 3 4 2 5
  */
