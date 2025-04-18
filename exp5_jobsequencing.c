#include <stdio.h>
#include <conio.h> // For getch()
#define INFINITY 9999
#define MAX 10
void Dijkstra(int Graph[MAX][MAX], int n, int start);
int main()
{
    int Graph[MAX][MAX], n, edges, u, v, w, start;
    // Input: Number of vertices
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    // Initialize Graph with 0
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            Graph[i][j] = 0;
    // Input: Number of edges
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    // Input: Graph edges
    for (int i = 0; i < edges; i++)
    {
        printf("Enter edge (start vertex, end vertex, weight): ");
        scanf("%d %d %d", &u, &v, &w);
        Graph[u][v] = w;
        Graph[v][u] = w; // Assuming an undirected graph
    }
    // Input: Starting node for Dijkstra
    printf("Enter starting node: ");
    scanf("%d", &start);
    // Run Dijkstra's Algorithm
    Dijkstra(Graph, n, start);
    getch(); // Keeps CMD open until a key is pressed
    return 0;
}
// Dijkstra’s Algorithm
void Dijkstra(int Graph[MAX][MAX], int n, int start)
{
    int cost[MAX][MAX], distance[MAX], pred[MAX];
    int visited[MAX], count, mindistance, nextnode, i, j;
    // Initialize cost matrix
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (Graph[i][j] == 0)
                cost[i][j] = INFINITY;
            else
                cost[i][j] = Graph[i][j];
        }
    }
    // Initialize distances and visited array
    for (i = 0; i < n; i++)
    {
        distance[i] = cost[start][i];
        pred[i] = start;
        visited[i] = 0;
    }
    distance[start] = 0;
    visited[start] = 1;
    count = 1;
    while (count < n - 1)
    {
        mindistance = INFINITY;
        // Find the next closest node
        for (i = 0; i < n; i++)
            if (distance[i] < mindistance && !visited[i])
            {
                mindistance = distance[i];
                nextnode = i;
            }
        visited[nextnode] = 1;
        // Update distances of adjacent nodes
        for (i = 0; i < n; i++)
            if (!visited[i] && cost[nextnode][i] != INFINITY)
                if (mindistance + cost[nextnode][i] < distance[i])
                {
                    distance[i] = mindistance + cost[nextnode][i];
                    pred[i] = nextnode;
                }
        count++;
    }
    // Print the shortest path from the source node
    printf("\nVertex\tDistance from Source\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\n", i, distance[i]);
    }
}