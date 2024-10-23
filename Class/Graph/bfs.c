#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Define the maximum number of vertices in the graph

// Queue structure for BFS
typedef struct Queue {
    int items[MAX];  // Array to store queue elements
    int front;       // Index of the front element
    int rear;        // Index of the rear element
} Queue;

// Function to create and initialize a queue
void createQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return q->rear == -1;
}

// Function to add an element to the queue
void enqueue(Queue* q, int value) {
    if (q->rear == MAX - 1) {
        // Queue is full
        printf("\nQueue is Full!!");
    } else {
        if (q->front == -1) q->front = 0;  // Initialize front if it was -1
        q->rear++;
        q->items[q->rear] = value;  // Add element to the rear
    }
}

// Function to remove an element from the queue
int dequeue(Queue* q) {
    int item;
    if (isEmpty(q)) {
        // Queue is empty
        printf("Queue is empty");
        item = -1;
    } else {
        item = q->items[q->front];  // Get the front element
        q->front++;
        if (q->front > q->rear) {
            // Reset the queue if it's empty after dequeue
            q->front = q->rear = -1;
        }
    }
    return item;
}

// BFS algorithm
void bfs(int graph[MAX][MAX], int numVertices, int startVertex) {
    Queue q;  // Declare a queue
    createQueue(&q);  // Initialize the queue

    int visited[MAX] = {0};  // Array to keep track of visited vertices
    visited[startVertex] = 1;  // Mark the start vertex as visited
    enqueue(&q, startVertex);  // Enqueue the start vertex

    // Loop until the queue is empty
    while (!isEmpty(&q)) {
        int currentVertex = dequeue(&q);  // Dequeue a vertex
        printf("Visited %d\n", currentVertex);  // Print the visited vertex

        // Explore all adjacent vertices of the current vertex
        for (int i = 0; i < numVertices; i++) {
            // If there is an edge and the vertex is not visited
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;  // Mark the vertex as visited
                enqueue(&q, i);  // Enqueue the vertex
            }
        }
    }
}

int main() {
    int numVertices = 4;  // Number of vertices in the graph
    // Adjacency matrix representing the graph
    int graph[MAX][MAX] = {
        {0, 1, 1, 0},  // Edges from vertex 0
        {0, 0, 1, 0},  // Edges from vertex 1
        {0, 0, 0, 0},  // Edges from vertex 2
        {0, 0, 1, 0}   // Edges from vertex 3
    };

    printf("Breadth First Search starting from vertex 0:\n");
    bfs(graph, numVertices, 0);  // Perform BFS starting from vertex 0
    
    return 0;
}
