#include <stdio.h>
#include <stdlib.h>

typedef struct graphRep *Graph;
typedef int Vertex;

struct graphRep {
    int nV;
    int nE;
    int **edegs;
};

// write a function that returns a set of all vertices that
// can be reached by following a path from the starting point
Set reachable(Graph g, Vertex v) {
    // set of all vertices we find which are reachable from v
    Set seen = newSet(g->nV);
    // queue of vertices to visit
    Queue q = newQueue();
    // add our starting vertex to the queue
    QueueJoin(q, v);
    // add our starting vertex to the seen set
    // (since v is reachable from v)
    SetInclude(seen, v);

    // continue until our queue is empty
    while (QueueLength(q) > 0) {
        // x is the next vertex to visit
        Vertex x = QueueLeave(q);
        Vertex y;
        // iterate through neighbours of x
        for (y = 0; y < g->nV; y++) {
            if (!g->edges[x][y]) continue;
            if (!SetHasElem(seen, y)) {
                // y is not in our seen set
                // but it is reachable from x, and therefore from v
                QueueJoin(q, y);
                SetInclude(seen, y);
            }
        }
    }
    return seen;
}

// return 1 if graph is connected
// 0 otherwise
int isConnected(Graph g) {

}
