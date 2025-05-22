#include <stdio.h>

#define MAX 20                 /* adjust as needed */

int a[MAX + 1][MAX + 1];       /* adjacency matrix a[i][j] == 1 if edge i→j */
int visited[MAX + 1];          /* visited[i] == 1 after vertex i is processed */
int q[MAX + 1];                /* circular queue for BFS */
int front = 0, rear = -1;      /* queue pointers */
int n;                         /* number of vertices (1 … n) */

/* enqueue one vertex */
void enqueue(int v) { q[++rear] = v; }

/* dequeue and return one vertex; caller must ensure queue is non‑empty */
int dequeue(void) { return q[front++]; }

/* return 1 if queue is empty */
int empty(void) { return front > rear; }

void bfs(int start)
{
    enqueue(start);          /* Rule 1: insert start node in queue */
    visited[start] = 1;

    while (!empty()) {       /* continue until queue empty  (Rule 3) */
        int v = dequeue();   /* Rule 2: remove next vertex */
        /* visit all out‑neighbors of v */
        for (int i = 1; i <= n; ++i)
            if (a[v][i] && !visited[i]) {
                printf("%d → %d\n", v, i);   /* optional traversal edge */
                visited[i] = 1;              /* mark visited  (Rule 1) */
                enqueue(i);                  /* insert in queue (Rule 1) */
            }
    }
}

int main(void)
{
    int start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the %d × %d adjacency matrix:\n", n, n);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            scanf("%d", &a[i][j]);

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    bfs(start);

    printf("\nNodes reachable from %d:", start);
    for (int i = 1; i <= n; ++i)
        if (visited[i]) printf(" %d", i);
    putchar('\n');

    return 0;
}
