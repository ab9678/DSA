#include <stdio.h>
#define V 5

void dfs(int node, int visited[], int edge[V][V]) {
    visited[node] = 1; // Mark current node as visited
    printf("%d ", node); // Print the node

    for (int i = 0; i < V; i++) {
        if (edge[node][i] == 1 && visited[i] == 0) {
            dfs(i, visited, edge); // Recursively visit unvisited neighbors
        }
    }
}

int main() {
    int edge[V][V] = {0}; // Adjacency matrix initialized to 0
    int visited[V] = {0}; // Visited array initialized to 0
    int e, src, dest;

    printf("Enter the number of edges: ");
    scanf("%d", &e);

    for (int i = 0; i < e; i++) {
        printf("Enter source and destination: ");
        scanf("%d %d", &src, &dest);
        edge[src][dest] = 1; // Add edge from source to destination
        edge[dest][src] = 1; // Add edge for undirected graph
    }

    printf("DFS Traversal: ");
    dfs(0, visited, edge); // Start DFS from node 0
    printf("\n");

    return 0;
}
