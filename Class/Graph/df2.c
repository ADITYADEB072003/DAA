#include <stdio.h>
#include <stdlib.h>

// Simpler graph representation using adjacency matrix
struct Graph {
    int vertices;
    int **adjacency_matrix;
    int *visited;
};

// Create a new graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    
    // Create adjacency matrix
    graph->adjacency_matrix = malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        graph->adjacency_matrix[i] = calloc(vertices, sizeof(int));
    }
    
    // Create visited array
    graph->visited = calloc(vertices, sizeof(int));
    
    return graph;
}

// Add an edge between two vertices
void addEdge(struct Graph* graph, int src, int dest) {
    // Add edges for undirected graph
    graph->adjacency_matrix[src][dest] = 1;
    graph->adjacency_matrix[dest][src] = 1;
}

// Simplified DFS
void DFS(struct Graph* graph, int vertex) {
    // Mark current vertex as visited and print it
    graph->visited[vertex] = 1;
    printf("Visited %d\n", vertex);
    
    // Visit all adjacent vertices
    // For vertex 2:
for (int i = 0; i < graph->vertices; i++) {
    // If vertex 2 is connected to vertex i AND vertex i is not visited
    if (graph->adjacency_matrix[2][i] == 1 && !graph->visited[i]) {
        // Visit it
        DFS(graph, i);
    }
    // Otherwise, skip to next vertex
}
}

int main() {
    // Create a graph with 4 vertices
    struct Graph* graph = createGraph(4);
    
    // Add edges
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    
    // Run DFS starting from vertex 2
    DFS(graph, 1);
    
    // Free memory
    for (int i = 0; i < graph->vertices; i++) {
        free(graph->adjacency_matrix[i]);
    }
    free(graph->adjacency_matrix);
    free(graph->visited);
    free(graph);
    
    return 0;
}