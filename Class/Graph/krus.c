#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_EDGES 10

// Structure to represent an edge
typedef struct {
    int src, dest, weight;
} Edge;

// Input edges
Edge edges[MAX_EDGES] = {
    {0, 1, 4},
    {0, 2, 4},
    {1, 2, 2},
    {1, 3, 6},
    {2, 3, 8},
    {3, 4, 9},
    {2, 4, 7}
};

int p[4]; // Parent array for union-find

// Find the root of a node
int applyfind(int i) {
    while (p[i] != -1) // Updated to -1 for better initialization check
        i = p[i];
    return i;
}

// Union operation for two sets
int applyunion(int i, int j) {
    if (i != j) {
        p[j] = i; // Attach one tree under another
        return 1;
    }
    return 0;
}

int main() {
    int n = 5;  // Number of vertices (0 to 4)
    int ne = 0; // Number of edges in MST
    int mincost = 0; // Minimum cost of MST
    int a, b;
    int numEdges = 7; // Total number of edges

    // Initialize union-find parent array
    for (int i = 0; i < n; i++) {
        p[i] = -1; // Using -1 to indicate no parent
    }

    printf("Edges in Minimum Cost Spanning Tree:\n");

    // Sorting edges based on their weights (Selection sort used for simplicity)
    for (int i = 0; i < numEdges; i++) {
        for (int j = i + 1; j < numEdges; j++) {
            if (edges[i].weight > edges[j].weight) {
                Edge temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }
        }
    }

    // Process edges in sorted order
    for (int i = 0; i < numEdges; i++) {
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