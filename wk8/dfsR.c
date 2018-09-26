#include <stdio.h>
#include <stdlib.h>

// implement DFS recursively
void dfs(Graph g) {
    // visited array of size nV
    int *visited = calloc(g->nV, sizeof(int));
    dfsR(q, visited, 0);
}

void dfsR(Graph g, int *visited, Vertex v) {
    visited[v] = 1; // we have seen v
    printf("%d\n", v);
    Vertex y;
    // iterate through neighbours of v
    for (y = 0; y < g->nV; y++) {
        if (!g->edges[v][y]) continue;
        // if we have already seen y, don't need to visit it again
        if (visited[y]) continue;
        // otherwise, call dfs recursively on y
        // note that we must pass in the visited array each recursive call
        dfsR(g, visited, y);
    }
}
