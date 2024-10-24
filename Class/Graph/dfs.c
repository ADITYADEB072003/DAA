#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Define the structure for a graph
struct Graph {
    int numVertices;  // Number of vertices in the graph
    int* visited;     // Array to keep track of visited vertices
    struct Node** adjLists;  // Array of adjacency lists
};

// Function to create a node
struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with a given number of vertices
struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    // Allocate memory for adjacency lists and visited array
    graph->adjLists = malloc(vertices * sizeof(struct Node*));
    graph->visited = malloc(vertices * sizeof(int));

    // Initialize adjacency lists and visited array
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add an edge from dest to src (because the graph is undirected)
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Depth-First Search (DFS) algorithm
void DFS(struct Graph* graph, int vertex) {
    struct Node* adjList = graph->adjLists[vertex];
    struct Node* temp = adjList;

    // Mark the current vertex as visited
    graph->visited[vertex] = 1;
    printf("Visited %d\n", vertex);

    // Recursively visit all the adjacent vertices that are not visited
    while (temp != NULL) {
        int connectedVertex = temp->vertex;

        if (graph->visited[connectedVertex] == 0) {
            DFS(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

// Main function
int main() {
    // Create a graph with 4 vertices
    struct Graph* graph = createGraph(4);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);

    // Perform DFS starting from vertex 2
    DFS(graph, 2);

    // Free allocated memory (optional but good practice)
    free(graph->adjLists);
    free(graph->visited);
    free(graph);

    return 0;
}
