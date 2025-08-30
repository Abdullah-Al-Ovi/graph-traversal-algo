#include <stdio.h>
#include <stdlib.h>
#define INF 9999
#define MAX 100

int cost[MAX][MAX], dist[MAX], visited[MAX];

int extractMin(int n) {
    int min = INF, u = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            u = i;
        }
    }
    return u;
}

void UCS(int start, int n) {
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[start] = 0;

    for (int count = 0; count < n; count++) {
        int u = extractMin(n);
        if (u == -1) break;
        visited[u] = 1;
        printf("%c ", u + 'A');

        for (int v = 0; v < n; v++) {
            if (cost[u][v] && !visited[v]) {
                if (dist[u] + cost[u][v] < dist[v]) {
                    dist[v] = dist[u] + cost[u][v];
                }
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter cost matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    printf("UCS Traversal: ");
    UCS(0, n);
    return 0;
}
