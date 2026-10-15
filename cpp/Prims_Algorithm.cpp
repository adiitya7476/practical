#include <stdio.h>
#define MAX 20
#define INF 9999
int main()
{
    int n;
    int graph[MAX][MAX];
    int selected[MAX];
    int i, j;
    int edges = 0;
    int min, x, y;
    int totalCost = 0;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter the cost adjacency matrix:\n");
    printf("Enter 0 if there is no edge.\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0)
                graph[i][j] = INF;
        }
    }
    for (i = 0; i < n; i++)
        selected[i] = 0;

    // Start from vertex 0
    selected[0] = 1;
    printf("\nEdges in Minimum Spanning Tree:\n");
    while (edges < n - 1) {
        min = INF;
        x = -1;
        y = -1;
        for (i = 0; i < n; i++) {
            if (selected[i]) {
                for (j = 0; j < n; j++) {
                    if (!selected[j] && graph[i][j] < min) {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }
        if (x == -1 || y == -1) {
            printf("Graph is not connected.\n");
            return 0;
        }
        printf("%d -- %d = %d\n", x + 1, y + 1, min);


        totalCost += min;
        selected[y] = 1;
        edges++;
    }
    printf("\nMinimum Cost = %d\n", totalCost);


    return 0;
}
