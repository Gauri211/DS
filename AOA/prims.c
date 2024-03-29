#include <stdio.h>
#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int key[MAX_VERTICES];
int parent[MAX_VERTICES];
int visited[MAX_VERTICES];

int minKey(int n)
{
    int min = -1, min_index;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && (min == -1 || key[i] < min))
        {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}
void primMST(int n)
{
    for (int i = 0; i < n; i++)
    {
        key[i] = MAX_VERTICES;
        // initialize all keys to a largevalue
        visited[i]=0;
        // markallverticesas unvisited
    }
        key[0] = 0;
        //  set the key of the first vertex to 0
        parent[0]=-1;
        // settheparentofthefirstvertexto-1
        for (int i = 0; i < n - 1; i++)
        {
            int u = minKey(n);
            // findthevertexwiththeminimumkeyvalue
            visited[u]=1;
            // mark the vertex as visited
            for(int v=0; v < n; v++) {
                if (graph[u][v] && !visited[v] && graph[u][v] < key[v])
                {
                    parent[v] = u;
                    // updatetheparentofthevertex
                    key[v]=graph[u][v];
                    // updatethekeyvalueofthevertex
                }
            }
        }
        printf("Edge Weight\n");
            for (int i = 1; i < n; i++)
            {
                printf("%d-%d\t%d\n", parent[i], i, graph[i][parent[i]]);
            }
    }

    int main()
    {
        int n;
        printf("Enter the number of vertices: ");
        scanf("%d", &n);
        printf("Enter the graph in matrix form:\n");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &graph[i][j]);
            }
        }
        primMST(n);
        return 0;
    }