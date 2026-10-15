#include <stdio.h>
#include <limits.h>
#define MAX 20
int main()
{
    int n, graph[MAX][MAX];
    int distance[MAX], visited[MAX];
    int i, j, source;
    int min, u;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter the cost adjacency matrix:\n");
    printf("(Enter 0 if there is no direct edge)\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter source vertex: ");
    scanf("%d", &source);
    source;
    for (i = 0; i < n; i++) {
        distance[i] = INT_MAX;
        visited[i] = 0;
    }

    distance[source] = 0;
    for (i = 0; i < n - 1; i++) {
        min = INT_MAX;
        u = -1;
        for (j = 0; j < n; j++) {
            if (!visited[j] && distance[j] < min) {
                min = distance[j];
                u = j;
            }
        }
        if (u == -1)
            break;
        visited[u] = 1;
        for (j = 0; j < n; j++) {
            if (!visited[j] &&
                graph[u][j] != 0 &&
                distance[u] != INT_MAX &&
                distance[u] + graph[u][j] < distance[j]) {
                distance[j] = distance[u] + graph[u][j];
            }
        }
    }
    printf("\nShortest distances from vertex %d:\n", source + 1);


    for (i = 0; i < n; i++) {
        if (distance[i] == INT_MAX)
            printf("Vertex %d : INF\n", i + 1);
        else
            printf("Vertex %d : %d\n", i + 1, distance[i]);
    }
    return 0;
}
