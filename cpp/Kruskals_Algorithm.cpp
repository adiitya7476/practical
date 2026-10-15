#include <stdio.h>
#define MAX 20
struct Edge {
     int u, v, weight;
};
int parent[MAX];
int find(int i)
{
     while (parent[i] != i)
        i = parent[i];
     return i;
}
void unionSet(int u, int v)
{
     parent[u] = v;
}
int main()
{
     struct Edge edge[MAX * MAX], temp;
     int n, e;
     int i, j;
     int count = 0;
     int minCost = 0;
     printf("Enter number of vertices: ");
     scanf("%d", &n);

printf("Enter number of edges: ");
scanf("%d", &e);
printf("Enter edges (source destination weight):\n");
for (i = 0; i < e; i++) {
    scanf("%d %d %d",
            &edge[i].u,
            &edge[i].v,
            &edge[i].weight);
}
for (i = 1; i <= n; i++)
    parent[i] = i;
for (i = 0; i < e - 1; i++) {
    for (j = i + 1; j < e; j++) {
        if (edge[i].weight > edge[j].weight) {
             temp = edge[i];
             edge[i] = edge[j];
             edge[j] = temp;
        }
    }
}
printf("\nEdges in Minimum Spanning Tree:\n");
for (i = 0; i < e && count < n - 1; i++) {
    int u = find(edge[i].u);
    int v = find(edge[i].v);
    if (u != v) {
        printf("%d -- %d = %d\n",
               edge[i].u,
               edge[i].v,
               edge[i].weight);
        minCost += edge[i].weight;
        count++;

            unionSet(u, v);
        }
    }
    printf("\nMinimum Cost = %d\n", minCost);
    return 0;
}
