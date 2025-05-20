#include <stdio.h>
#define MAX 20

int adjacency_matrix[MAX][MAX];
int visited_vertex[MAX];
int number_of_vertex;

void dfs(int current_vertex)
{
    visited_vertex[current_vertex] = 1;
    for(int i = 1; i<= number_of_vertex; i++){
        if(adjacency_matrix[current_vertex][i] && !visited_vertex[i]){
            printf("%d --> %d", current_vertex, i);
            dfs(i);
        }
    }
}
int main()
{
    int i, j;

    printf("Enter the number of vertex: ");
    scanf("%d", &number_of_vertex);

    for (int i = 1; i <= number_of_vertex; i++)
    {
        visited_vertex[i] = 0;
    }

    printf("Enter the adjacency matrix: ");
    for (int i = 1; i <= number_of_vertex; i++)
    {
        for (int j = 1; j <= number_of_vertex; j++)
        {
            scanf("%d", &adjacency_matrix[i][j]);
        }
    }

    dfs(1);

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