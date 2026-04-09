#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX];   // Adjacency matrix
int indegree[MAX];     // In-degree array
int n;                 // Number of vertices

void topologicalSort() {
    int queue[MAX], front = 0, rear = 0;
    int topo[MAX];
    int count = 0;

    // Step 1: Calculate indegree
    for (int i = 0; i < n; i++) {
        indegree[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    // Step 2: Add nodes with indegree 0 to queue
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    // Step 3: Process queue
    while (front < rear) {
        int u = queue[front++];
        topo[count++] = u;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] == 1) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    queue[rear++] = v;
                }
            }
        }
    }

    // Step 4: Check for cycle
    if (count != n) {
        printf("Cycle detected! Topological sort not possible.\n");
        return;
    }

    // Step 5: Print result
    printf("Topological Order: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", topo[i]);
    }
    printf("\n");
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    topologicalSort();

    return 0;
}