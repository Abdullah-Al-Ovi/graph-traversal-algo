#include <stdio.h>

#define MAX 100

int adj[MAX][MAX], visited[MAX];

void DFS(int v, int n) {
    printf("%c ", v + 'A');
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i]) {
            DFS(i, n);
        }
    }
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("DFS Traversal: ");
    for (int i = 0; i < n; i++) visited[i] = 0;
    DFS(0, n);
    return 0;
}
