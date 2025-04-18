#include <stdio.h>
#include <limits.h>
#define MAX 10
int tsp_greedy(int graph[MAX][MAX], int n, int start)
{
    int visited[MAX] = {0};
    int cost = 0;
    int count = 0;
    int i, j, min, next_city;
    int current_city = start;
    visited[start] = 1;
    printf("Path: %c", start + 'A');
    while (count < n - 1)
    {
        min = INT_MAX;
        next_city = -1;
        for (j = 0; j < n; j++)
        {
            if (!visited[j] && graph[current_city][j] && graph[current_city][j] < min)
            {
                min = graph[current_city][j];
                next_city = j;
            }
        }
        if (next_city == -1)
        {
            printf("\nNo path available\n");
            return -1;
        }
        visited[next_city] = 1;
        cost += graph[current_city][next_city];
        current_city = next_city;
        printf(" -> %c", current_city + 'A');
        count++;
    }
    cost += graph[current_city][start]; // returning to start
    printf(" -> %c", start + 'A');
    printf("\nTotal cost: %d\n", cost);
    return cost;
}
int main()
{
    int graph[MAX][MAX];
    int n, i, j, start;
    printf("Enter the number of cities: ");
    scanf("%d", &n);
    printf("Enter the distance matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter starting city index (0 for A, 1 for B, ...): ");
    scanf("%d", &start);
    tsp_greedy(graph, n, start);
    return 0;
}