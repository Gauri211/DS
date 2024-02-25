#include<stdio.h>
#include<stdbool.h>
#define MAX 9999

int n;

int minDis(int d[n], bool path[n]) {
    int min = MAX, u;
    for(int i=0; i<n; i++) {
        if(min > d[i] && path[i]==false) {
            min = d[i];
            u = i;
        }
    }
    return u;
}


void main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    int graph[n][n], d[n], pi[n], s=0, vertex = n-1, v;
    bool path[n];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    //Initialize 
    for(int i=0; i<n; i++) {
        d[i] = MAX;
        path[i] = false;
        pi[i] = -1;
    }
    d[s] = 0; //s=>source

    //To find Shortest path and its parent
    while(vertex != 0) {
        int u = minDis(d, path);
        path [u] = true;
        for(v=0; v<n; v++) {
            if(graph[u][v]!=0 && d[u] + graph[u][v]<d[v] && path[v]==false) {
            d[v] = d[u] + graph[u][v];
            pi[v] = u;
    }
        }
        vertex--;
    }

    printf("Vertex\td\tpi\n");
    for(int i=0; i<n; i++) {
        printf("%d\t%d\t%d\n", i, d[i], pi[i]+1);
    }
}
