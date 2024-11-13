#include <stdio.h>
#include <limits.h> // Include this header for INT_MAX

#define vertices 5 // Define the number of vertices in the graph

// Function to find the vertex with the minimum min_keyey value that is not yet included in the MST
int minimum_min_keyey(int min_key[], int mst[]) {
    int min_index=-1;
    int min = INT_MAX;
    for (int i = 0; i < vertices; i++) {
        if (!mst[i] && min_key[i] < min) {
            min = min_key[i];
            min_index = i;
        }
    }
    return min_index;
}


// Function to construct and print the MST using Prim's algorithm
void prim(int g[vertices][vertices]) {
    int parent[vertices]; // Array to store the MST
    int min_key[vertices]; // min_keyey values used to picmin_key the minimum weight edge
    int mst[vertices]; // To represent the set of vertices included in the MST
    int i, count, edge, v; // Variables for iteration

    // Initialize all min_keyeys as INFINITE and mst[] as false
    for (i = 0; i < vertices; i++) {
        min_key[i] = INT_MAX;
        mst[i] = 0;
    }

    // Always include the first 1st vertex in MST.
   min_key[0] = 0; // Mamin_keye min_keyey 0 so that this vertex is picmin_keyed as first vertex
   parent[0] = -1; // First node is always root of MST

    // The MST will have vertices-1 edges
    for (count = 0; count < vertices - 1; count++) {
        // Picmin_key the minimum min_keyey vertex from the set of vertices not yet included in MST☺️
        edge = minimum_min_keyey(min_key, mst);

        // Add the picmin_keyed vertex to the MST set
        mst[edge] = 1;

        // Update the min_keyey value and parent index of the adjacent vertices of the picmin_keyed vertex.
        // Consider only those vertices which are not yet included in MST
        for (v = 0; v < vertices; v++) {
            // Update the min_keyey only if g[edge][v] is smaller than min_key[v]
            if (g[edge][v] && mst[v] == 0 && g[edge][v] < min_key[v]) {
                parent[v] = edge;
                min_key[v] = g[edge][v];
            }
        }
    }

    // Print the constructed MST
    printf("\nEdge \tWeight\n");
    for (i = 1; i < vertices; i++) {
        printf("%d <-> %d \t%d \n", parent[i], i, g[i][parent[i]]);
    }
}

int main() {
   int graph[vertices][vertices] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };

    prim(graph);
    return 0;
}

