
/* hasPath.c 
   Written by Ashesh Mahidadia, October 2017
*/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "Graph.h"



/* 
    You will submit only this one file.

    Implement the function "hasPath" below. Read the exam paper for 
    detailed specification and description of your task.  

    - You can add helper functions in this file, if required.  

    - DO NOT modify code in the file BSTree.h . 
    - DO NOT add "main" function in this file. 
*/


int *visited;  // array of visited

// We use a helper function to do our DFS recursively
// since we are not provided a Stack ADT
int hasPathHelper(Graph g, Vertex src, Vertex dest) {
    visited[src] = 1; // set current vertex to visited
    if (src == dest) return 1; // need to do this check here in case that dest = src
    Vertex y;
    for (y = 0; y < g->nV; y++) {
        if (!g->edges[src][y] || visited[y] == 1) continue;
        // note that we cannot just return hasPathHelper(g, y, dest)
        // since it may return 0, but there may be a path to dest via
        // a different vertex
        if (hasPathHelper(g, y, dest)) return 1;
    }
    return 0;
}

int hasPath(Graph g, Vertex src, Vertex dest) {
    assert(g != NULL);
    // NOTE that we need a helper function, since this function calls calloc
    // and we would NOT like to do that more than once!
    visited = calloc(g->nV, sizeof(int));
    int ret = hasPathHelper(g, src, dest);
    free(visited);
    return ret;
}


