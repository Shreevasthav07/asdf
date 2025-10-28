#include <stdio.h>

struct Item {
    int weight;
    int profit;
    float ratio;
};

// Function to swap two items
void swap(struct Item *a, struct Item *b) {
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort items by profit/weight ratio (descending order)
void sortByRatio(struct Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (items[j].ratio < items[j + 1].ratio) {
                swap(&items[j], &items[j + 1]);
            }
        }
    }
}

// Function to implement the greedy fractional knapsack algorithm
void fractionalKnapsack(struct Item items[], int n, int capacity) {
    int i;
    float totalProfit = 0.0;
    int remainingCapacity = capacity;

    // Sort items by profit/weight ratio
    sortByRatio(items, n);

    printf("\nItems sorted by Profit/Weight ratio:\n");
    printf("Item\tProfit\tWeight\tRatio\n");
    for (i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%.2f\n", i + 1, items[i].profit, items[i].weight, items[i].ratio);

    // Greedy selection
    for (i = 0; i < n; i++) {
        if (items[i].weight <= remainingCapacity) {
            // Take the whole item
            totalProfit += items[i].profit;
            remainingCapacity -= items[i].weight;
        } else {
            // Take a fraction of the item
            totalProfit += items[i].ratio * remainingCapacity;
            break;  // Knapsack is full
        }
    }

    printf("\nMaximum profit that can be obtained = %.2f\n", totalProfit);
}

int main() {
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    printf("Enter profit and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d profit: ", i + 1);
        scanf("%d", &items[i].profit);
        printf("Item %d weight: ", i + 1);
        scanf("%d", &items[i].weight);
        items[i].ratio = (float)items[i].profit / items[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    fractionalKnapsack(items, n, capacity);

    return 0;
}
