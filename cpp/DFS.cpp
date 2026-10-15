#include <stdio.h>
#define MAX 20
int graph[MAX][MAX];
int visited[MAX];
int n;
void DFS(int vertex)
{
    int i;
    // Mark the current vertex as visited
    visited[vertex] = 1;
    printf("%d ", vertex + 1);
    // Visit all adjacent vertices
    for (i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && visited[i] == 0) {
             DFS(i);
        }
    }
}
int main()
{
    int i, j, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {

            scanf("%d", &graph[i][j]);
        }
    }
    // Initialize all vertices as unvisited
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }
    printf("Enter starting vertex: ");
    scanf("%d", &start);
    printf("\nDFS Traversal: ");
    DFS(start - 1);
    printf("\n");
    return 0;
}
