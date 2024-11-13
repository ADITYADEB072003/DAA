#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_EDGES 10

// Structure to represent an edge
typedef struct {
    int src, dest, weight;
} Edge;

Edge edges[MAX_EDGES] = {
    {0, 1, 10},
    {0, 2, 6},
    {0, 3, 5},
    {1, 3, 15},
    {2, 3, 4}
};

int p[4]; // Parent array for union-find

int applyfind(int i) {
    while (p[i] != -1) // Updated to -1 for better initialization check
        i = p[i];
    return i;
}

int applyunion(int i, int j) {
    if (i != j) {
        p[j] = i; // Attach one tree under another
        return 1;
    }
    return 0;
}

int main() {
    int n = 4;  // Number of vertices (0 to 3)
    int ne = 0; // Number of edges in MST
    int mincost = 0; // Minimum cost of MST
    int a, b;

    // Initialize union-find parent array
    for (int i = 0; i < n; i++) {
        p[i] = -1; // Using -1 to indicate no parent
    }

    printf("Edges in Minimum Cost Spanning Tree:\n");

    // Sorting edges based on their weights (Selection sort used for simplicity)
    for (int i = 0; i < n+1; i++) {
        for (int j = i + 1; j < n+1; j++) {
            if (edges[i].weight > edges[j].weight) {
                Edge temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }
        }
    }
// //insertion sort
//  // Sorting edges based on their weights using insertion sort
//     for (int i = 1; i < n+1; i++) {
//         Edge key = edges[i];
//         int j = i - 1;

//         // Move elements of edges[0..i-1] that are greater than key
//         // to one position ahead of their current position
//         while (j >= 0 && edges[j].weight > key.weight) {
//             edges[j + 1] = edges[j];
//             j--;
//         }
//         edges[j + 1] = key;
//     }
    // Process edges in sorted order
    for (int i = 0; i < n+1; i++) {
        a = applyfind(edges[i].src);
        b = applyfind(edges[i].dest);

        // If adding this edge doesn't cause a cycle
        if (applyunion(a, b)) {
            printf("%d -> %d (Weight: %d)\n", edges[i].src, edges[i].dest, edges[i].weight);
            mincost += edges[i].weight;
            ne++;
        }
        if (ne == n - 1) // Stop if we have enough edges
            break;
    }

    printf("Minimum cost = %d\n", mincost);
    return 0;
}

