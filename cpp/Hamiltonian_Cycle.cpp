#include <stdio.h>
#define MAX 20
int n;
int graph[MAX][MAX];
int path[MAX];
int isSafe(int vertex, int position)
{
    int i;
    // Check if the vertex is connected to the previous vertex
    if (graph[path[position - 1]][vertex] == 0)
        return 0;


    // Check if the vertex is already included in the path
    for (i = 0; i < position; i++) {
        if (path[i] == vertex)
             return 0;
    }
    return 1;
}
int hamiltonianCycle(int position)
{
    int vertex;
    // All vertices are included
    if (position == n) {
        // Check if last vertex is connected to the first vertex
        if (graph[path[position - 1]][path[0]] == 1)

            return 1;
        return 0;
    }
    // Try all vertices
    for (vertex = 1; vertex < n; vertex++) {
        if (isSafe(vertex, position)) {
            path[position] = vertex;
            if (hamiltonianCycle(position + 1))
                return 1;
            // Backtrack
            path[position] = -1;
        }
    }
    return 0;
}
int main()
{
    int i, j;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    // Initialize path
    for (i = 0; i < n; i++)
        path[i] = -1;


    // Start from vertex 0
    path[0] = 0;

    if (hamiltonianCycle(1)) {
        printf("\nHamiltonian Cycle exists:\n");


        for (i = 0; i < n; i++)
          printf("%d -> ", path[i] + 1);


        printf("%d\n", path[0] + 1);
    }
    else {
        printf("\nHamiltonian Cycle does not exist.\n");
    }
    return 0;
}
