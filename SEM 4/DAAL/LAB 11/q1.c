#include <stdio.h>
#include <stdlib.h>

int i, j, a, b, u, v, n, ne = 1;
int min, mincost = 0, **cost, *parent;

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
void main()
{
    printf("\nNo. of vertices: ");
    scanf("%d", &n);
    parent=(int*)malloc(n*sizeof(int));
    printf("\nCost adjacency matrix: \n");
    cost=(int**)calloc(n,sizeof(int*));
    for (i = 1; i <= n; i++)
    {
        cost[i]=(int*)calloc(n,sizeof(int));
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
            {
                cost[i][j] = 999;
            }
        }
    }
    printf("Minimum spanning tree: \n");
    while (ne < n)
    {
        for (i = 1, min = 999; i <= n; i++)
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
        cost[a][b] = cost[b][a] = 999;
    }
    printf("\nMinimum cost = %d\n", mincost);
}
