#include <stdio.h>
#include <limits.h>

#define N 4  // Number of cities

int next_permutation(int *p, int n);  // Function prototype

int tsp(int graph[N][N], int start) {
    int visited[N] = {0};
    int path[N + 1];
    int min_path_cost = INT_MAX;
    int city[N - 1];
    int i, j, k;

    // Prepare cities except the start city
    for (i = 0, j = 0; i < N; i++) {
        if (i != start)
            city[j++] = i;
    }

    // Permutation generation
    do {
        int current_cost = 0;
        int k = start;

        for (i = 0; i < N - 1; i++) {
            current_cost += graph[k][city[i]];
            k = city[i];
        }
        current_cost += graph[k][start]; // return to start

        if (current_cost < min_path_cost)
            min_path_cost = current_cost;

    } while (next_permutation(city, N - 1));

    return min_path_cost;
}

// Helper function to generate next permutation (already defined)
int next_permutation(int *p, int n) {
    int i = n - 2;
    while (i >= 0 && p[i] > p[i + 1])
        i--;
    if (i < 0)
        return 0;

    int j = n - 1;
    while (p[j] < p[i])
        j--;

    int temp = p[i];
    p[i] = p[j];
    p[j] = temp;

    for (int a = i + 1, b = n - 1; a < b; a++, b--) {
        temp = p[a];
        p[a] = p[b];
        p[b] = temp;
    }
    return 1;
}

int main() {
    int graph[N][N] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int start = 0;
    int min_cost = tsp(graph, start);

    printf("Minimum cost of travelling salesman tour: %d\n", min_cost);
    return 0;
}
