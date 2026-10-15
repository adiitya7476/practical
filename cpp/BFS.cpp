#include <stdio.h>
#define MAX 20
int graph[MAX][MAX];
int visited[MAX];
int queue[MAX];
int n;
void BFS(int start)
{
    int front = 0, rear = 0;
    int i, current;
    // Mark starting vertex as visited
    visited[start] = 1;
    queue[rear++] = start;
    while (front < rear) {
        current = queue[front++];
        printf("%d ", current + 1);
        // Visit all adjacent vertices
        for (i = 0; i < n; i++) {
            if (graph[current][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[rear++] = i;
            }
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
    printf("\nBFS Traversal: ");
    BFS(start - 1);
    printf("\n");
    return 0;
}
