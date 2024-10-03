#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct Graph {
    int adj[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} Graph;

void initGraph(Graph *g, int vertices) {
    g->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adj[i][j] = 0; // Initialize adjacency matrix
        }
    }
}

void addEdge(Graph *g, int src, int dest) {
    g->adj[src][dest] = 1; // Directed graph
    g->adj[dest][src] = 1; // Uncomment this line for undirected graph
}

void dfsUtil(Graph *g, int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%d ", vertex);

    for (int i = 0; i < g->numVertices; i++) {
        if (g->adj[vertex][i] && !visited[i]) {
            dfsUtil(g, i, visited);
        }
    }
}

void depthFirstSearch(Graph *g, int startVertex) {
    bool visited[MAX_VERTICES] = {false};
    dfsUtil(g, startVertex, visited);
}

void breadthFirstSearch(Graph *g, int startVertex) {
    bool visited[MAX_VERTICES] = {false};
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    visited[startVertex] = true;
    printf("%d ", startVertex);
    queue[rear++] = startVertex;

    while (front < rear) {
        int currentVertex = queue[front++];
        
        for (int i = 0; i < g->numVertices; i++) {
            if (g->adj[currentVertex][i] && !visited[i]) {
                visited[i] = true;
                printf("%d ", i);
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    Graph g;
    initGraph(&g, 5); // Example with 5 vertices

    addEdge(&g, 0, 1);
    addEdge(&g, 0, 4);
    addEdge(&g, 1, 2);
    addEdge(&g, 1, 3);
    addEdge(&g, 1, 4);
    addEdge(&g, 2, 3);
    addEdge(&g, 3, 4);

    printf("Depth First Search starting from vertex 0:\n");
    depthFirstSearch(&g, 0);
    printf("\n");

    printf("Breadth First Search starting from vertex 0:\n");
    breadthFirstSearch(&g, 0);
    printf("\n");

    return 0;
}
