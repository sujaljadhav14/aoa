#include <stdio.h>
#include <stdbool.h>
#define V 4 // Number of vertices (change as needed)
// Function to print the solution
void printSolution(int color[])
{
    printf("Color assigned to vertices:\n");
    for (int i = 0; i < V; i++)
        printf("Vertex %d --> Color %d\n", i, color[i]);
}
// Check if the current color assignment is safe
bool isSafe(int v, bool graph[V][V], int color[], int c)
{
    for (int i = 0; i < V; i++)
        if (graph[v][i] && color[i] == c)
            return false;
    return true;
}
// Utility function to solve the coloring problem
bool graphColoringUtil(bool graph[V][V], int m, int color[], int v)
{
    if (v == V)
        return true;
    for (int c = 1; c <= m; c++)
    {
        if (isSafe(v, graph, color, c))
        {
            color[v] = c;
            if (graphColoringUtil(graph, m, color, v + 1))
                return true;
            color[v] = 0; // Backtrack
        }
    }
    return false;
}
// Main function to solve the graph coloring problem
bool graphColoring(bool graph[V][V], int m)
{
    int color[V] = {0};
    if (!graphColoringUtil(graph, m, color, 0))
    {
        printf("Solution does not exist with %d colors.\n", m);
        return false;
    }
    printSolution(color);
    return true;
}
int main()
{
    // Example graph: change values as needed
    bool graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0},
    };
    int m;
    printf("Enter the number of colors (m): ");
    scanf("%d", &m);
    graphColoring(graph, m);
    return 0;
}