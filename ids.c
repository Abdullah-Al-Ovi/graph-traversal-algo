#include <stdio.h>

#define MAX 100

int adj[MAX][MAX], visited[MAX];

int DFS_Limit(int v, int n, int depth, int limit) {
    if (depth > limit) return 0;
    printf("%c ", v + 'A');
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i]) {
            DFS_Limit(i, n, depth + 1, limit);
        }
    }
    return 1;
}

void IDS(int start, int n, int maxDepth) {
    for (int limit = 0; limit <= maxDepth; limit++) {
        for (int i = 0; i < n; i++) visited[i] = 0;
        printf("\nDepth Limit %d: ", limit);
        DFS_Limit(start, n, 0, limit);
    }
}

int main() {
    int n, maxDepth;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("Enter max depth: ");
    scanf("%d", &maxDepth);

    IDS(0, n, maxDepth);
    return 0;
}
