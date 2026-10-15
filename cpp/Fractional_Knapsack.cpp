#include <stdio.h>
struct Item {
     int weight;
     int profit;
     float ratio;
};
int main() {
     int n, capacity;
     int i, j;
     float totalProfit = 0;


     printf("Enter number of items: ");
     scanf("%d", &n);


     struct Item items[n];


     printf("Enter weight and profit of each item:\n");
     for (i = 0; i < n; i++) {
         printf("Item %d: ", i + 1);
         scanf("%d %d", &items[i].weight, &items[i].profit);


         items[i].ratio = (float)items[i].profit / items[i].weight;
     }


     printf("Enter knapsack capacity: ");
     scanf("%d", &capacity);

// Sort items by profit/weight ratio in descending order
for (i = 0; i < n - 1; i++) {
    for (j = i + 1; j < n; j++) {
        if (items[i].ratio < items[j].ratio) {
            struct Item temp = items[i];
            items[i] = items[j];
            items[j] = temp;
        }
    }
}


// Select items
for (i = 0; i < n; i++) {
    if (capacity >= items[i].weight) {
        // Take the entire item
        capacity -= items[i].weight;
        totalProfit += items[i].profit;


        printf("Item %d: 100%% taken\n", i + 1);
    }
    else {
        // Take the fraction that fits
        float fraction = (float)capacity / items[i].weight;
        totalProfit += items[i].profit * fraction;


        printf("Item %d: %.2f%% taken\n", i + 1, fraction * 100);


        capacity = 0;
        break;
    }
}

    printf("\nMaximum Profit = %.2f\n", totalProfit);


    return 0;
}
