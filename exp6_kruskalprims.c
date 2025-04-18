#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MAX 50
#define INF 999

int n; // Number of vertices

// For Kruskal
int cost[MAX][MAX], parent[MAX];
int find(int i)
{
    while (parent[i])
        i = parent[i];
    return i;
}
int uni(int i, int j)
{
    if (i != j)
    {
        parent[j] = i;
        return 1;
    }
    return 0;
}
void kruskal()
{
    int i, j, a, b, u, v, ne = 1, min, mincost = 0;

    printf("\nEnter adjacency matrix for Kruskal's Algorithm:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    printf("\nThe edges of the Minimum Spanning Tree are:\n");
    while (ne < n)
    {
        min = INF;
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if (uni(u, v))
        {
            printf("%d edge (%d,%d) = %d\n", ne++, a, b, min);
            mincost += min;
        }
        cost[a][b] = cost[b][a] = INF;
    }

    printf("Minimum cost = %d\n", mincost);
}

// For Prim
int G[MAX][MAX], selected[MAX], total = 0;
void prim()
{
    int i, j, u = 0, v = 0, k, min_dist;

    printf("\nEnter adjacency matrix for Prim's Algorithm:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &G[i][j]);
        }
    }

    for (i = 0; i < n; i++)
        selected[i] = 0;
    selected[0] = 1;

    printf("\nThe edges of the Minimum Spanning Tree are:\n");

    for (k = 1; k < n; k++)
    {
        min_dist = INF;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (G[i][j] && ((selected[i] && !selected[j]) || (!selected[i] && selected[j])))
                {
                    if (G[i][j] < min_dist)
                    {
                        min_dist = G[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        printf("Edge (%d,%d) and weight = %d\n", u, v, min_dist);
        selected[u] = selected[v] = 1;
        total += min_dist;
    }

    printf("Total path length = %d\n", total);
}

void main()
{
    int choice;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("\nChoose Algorithm to find MST:\n");
    printf("1. Kruskal's Algorithm\n");
    printf("2. Prim's Algorithm\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        kruskal();
        break;
    case 2:
        prim();
        break;
    default:
        printf("Invalid choice.\n");
    }

    getch();
}
