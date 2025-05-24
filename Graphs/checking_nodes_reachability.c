#include <stdio.h>

#define MAX 20

int array[MAX + 1][MAX + 1]; /* adjacency matrix a[i][j] == 1 if edge i→j */
int visited[MAX + 1]; /* visited[i] == 1 after vertex i is processed */
int queue[MAX + 1];
int front = 0, rear = -1; /* queue pointers */
int n; /* number of vertices (1 … n) */

void enqueue(int v) { queue[++rear] = v; }

int dequeue(void) { return queue[front++]; }

int empty(void) { return front > rear; }

void bfs(int start)
{
    enqueue(start);
    visited[start] = 1;

    while (!empty()) {
        int current_node = dequeue();
        /* visit all out‑neighbors of current_node */
        for (int i = 1; i <= n; ++i)
            if (array[current_node][i] && !visited[i]) {
                printf("%d → %d\n", current_node, i);
                visited[i] = 1;
                enqueue(i);
            }
    }
}

int main(void)
{
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the %d × %d adjacency matrix:\n", n, n);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            scanf("%d", &array[i][j]);

    int start;
    printf("Enter starting vertex: ");
    scanf("%d", &start);

    bfs(start);

    printf("Nodes reachable from %d:", start);
    for (int i = 1; i <= n; ++i)
        if (visited[i]) printf(" %d\t", i);
    putchar('\n');

    return 0;
}
