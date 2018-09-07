#include <stdio.h>
#include <stdlib.h>

// vertices denoted by integers 0..N-1 
typedef struct graphRep * Graph;
typedef int Vertex; 
typedef struct edge Edge;
typedef struct vNode *List;

// edges are pairs of vertices (end-points) 
struct edge { Vertex v; Vertex w; };

// representation of a node used in adjacency list representation
struct vNode {
    Vertex v;
    struct vNode *next;
};

///// Array of edges representation

struct graphRep { 
    int nV;       // #vertices 
    int nE;       // #edges 
    Edge *edges;  // array of Edges
}; 

///// Adjacency matrix graph representation

struct graphRep { 
    int nV;       // #vertices 
    int nE;       // #edges 
    int **edges;  // matrix of booleans (0 or 1)
}; 

///// Adjacency list graph representation

struct graphRep { 
    int nV;       // #vertices 
    int nE;       // #edges
    List *edges;  // array of Vertex lists 
};

// return array of edges for an adjacency matrix representation
// set *nE to be the number of edges in return array
Edge *edges(Graph g, int *nE) {
    Edge *e = malloc(g->nE * sizeof(Edge));
    *nE = g->nE;
    int n = 0;
    int v, w;
    // iterate through all vertices in graph
    for (v = 0; v < g->nV; v++) {
        // iterate through all vertices in top right half of matrix
        // (to avoid adding an edge twice, since our graph is undirected)
        for (w = v+1; w < g->nV; w++) {
            if (g->edges[v][w] == 1) {
                // add edge to edges array
                e[n++] = {v, w};
            }
        }
    }
    return e;
}

// return array of edges for an adjacency list representation
Edge *edges(Graph g, int *nE) {
    Edge *e = malloc(g->nE * sizeof(Edge));
    *nE = g->nE;
    int n = 0;
    int v, w;
    // iterate through all vertices in graph
    for (v = 0; v < g->nV; v++) {
        // note that g->edges[v] is a list of all its adjacent vertices
        // thus, each node corresponds to an edge
        struct vNode *curr = g->edges[v];
        while (curr != NULL) {
            w = curr->v;
            // avoid adding an edge twice, since our graph is undirected
            if (v < w) {
                e[n++] = {v, w};
            }
            curr = curr->next;
        }
    }
    return e;
}
