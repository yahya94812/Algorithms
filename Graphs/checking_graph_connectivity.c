//works for undirected graphs, assuming the adjacency matrix is symmetric.
#include <stdio.h>
#define MAX 20

int adjacency_matrix[MAX + 1][MAX + 1];
int visited_vertex[MAX + 1];
int number_of_vertex;

void dfs(int current_vertex)
{
    visited_vertex[current_vertex] = 1;
    for (int i = 1; i <= number_of_vertex; i++)
    {
        if (adjacency_matrix[current_vertex][i] && !visited_vertex[i])
        {
            printf("%d --> %d\n", current_vertex, i);
            dfs(i);
        }
    }
}

int main()
{
    printf("Enter the number of vertex: ");
    scanf("%d", &number_of_vertex);

    printf("Enter the adjacency matrix: ");
    for (int i = 1; i <= number_of_vertex; i++)
    {
        for (int j = 1; j <= number_of_vertex; j++)
        {
            scanf("%d", &adjacency_matrix[i][j]);
        }
    }

    for (int i = 1; i <= number_of_vertex; i++)
    {
        visited_vertex[i] = 0;
    }

    dfs(1); // start dfs from first node

    int count = 0;
    for (int i = 1; i <= number_of_vertex; i++)
    {
        if (visited_vertex[i])
        {
            count++;
        }
    }

    if (count == number_of_vertex)
    {
        printf("the given graph is connected\n");
    }
    else
    {
        printf("the given graph is not connected\n");
    }

    return 0;
}