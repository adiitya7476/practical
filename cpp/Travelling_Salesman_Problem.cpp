#include <stdio.h>
#include <limits.h>


#define MAX 10


int n;
int cost[MAX][MAX];
int visited[MAX];
int bestCost = INT_MAX;
int bestPath[MAX + 1];
int path[MAX + 1];


void tsp(int city, int count, int currentCost)
{
    int i;


    // All cities have been visited
    if (count == n) {
       // Return to the starting city
       int totalCost = currentCost + cost[city][0];


       if (totalCost < bestCost) {
             bestCost = totalCost;


             for (i = 0; i < n; i++)
               bestPath[i] = path[i];

            bestPath[n] = 0;
        }


        return;
    }


    // Try visiting every unvisited city
    for (i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            path[count] = i;


            tsp(i, count + 1, currentCost + cost[city][i]);


            visited[i] = 0;
        }
    }
}


int main()
{
    int i, j;


    printf("Enter number of cities: ");
    scanf("%d", &n);


    printf("Enter the cost matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }

    }


    // Start from city 0
    for (i = 0; i < n; i++)
        visited[i] = 0;


    visited[0] = 1;
    path[0] = 0;


    tsp(0, 1, 0);


    printf("\nMinimum cost: %d\n", bestCost);


    printf("Optimal path: ");
    for (i = 0; i <= n; i++) {
        printf("%d", bestPath[i] + 1);
        if (i < n)
          printf(" -> ");
    }


    printf("\n");


    return 0;
}
