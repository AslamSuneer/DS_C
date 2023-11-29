#include <stdio.h>
#include <stdlib.h>

int source, V, E, visited[20], G[20][20], Q[20], front = -1, rear = -1;

void DFS(int i) {
    int j;
    visited[i] = 1;
    printf(" %d->", i);
    for (j = 1; j <= V; j++) {
        if (G[i][j] == 1 && visited[j] == 0)
            DFS(j);
    }
}

void BFS(int s) {
    int i;
    visited[s] = 1;
    printf(" %d->", s);
    enqueue(s);
    while (front != -1) {
        s = dequeue();
        for (i = 1; i <= V; i++) {
            if (G[s][i] == 1 && visited[i] == 0) {
                printf(" %d->", i);
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

void enqueue(int item) {
    if (front == -1 && rear == -1) {
        front = rear = 0;
        Q[rear] = item;
    } else {
        rear++;
        Q[rear] = item;
    }
}

int dequeue() {
    int item;
    if (front == -1 && rear == -1)
        return -1;
    else if (front == rear) {
        item = Q[front];
        front = rear = -1;
        return item;
    } else {
        return Q[front++];
    }
}

int main() {
    int i, j, v1, v2;
    printf("Enter the number of vertices of the graph: ");
    scanf("%d", &V);

    for (i = 1; i <= V; i++)
        for (j = 1; j <= V; j++)
            G[i][j] = 0;

    printf("Enter the number of edges of the graph: ");
    scanf("%d", &E);

    for (i = 1; i <= E; i++) {
        printf("Enter the edges (V1 V2): ");
        scanf("%d%d", &v1, &v2);
        G[v1][v2] = 1; // For directed graph, only set one side of the edge
    }

    printf("\nThe adjacency matrix:\n");

    for (i = 1; i <= V; i++) {
        for (j = 1; j <= V; j++)
            printf("%d\t", G[i][j]);
        printf("\n");
    }

    for (i = 1; i <= V; i++)
        visited[i] = 0;

    printf("Enter the source: ");
    scanf("%d", &source);

    printf("\nDFS\n");
    DFS(source);

    for (i = 1; i <= V; i++)
        visited[i] = 0;

    printf("\nBFS\n");
    BFS(source);

    return 0;
}
