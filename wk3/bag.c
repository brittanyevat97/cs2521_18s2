#include <stdio.h>
#include <stdlib.h>

typedef struct BagRep *Bag;

typedef struct Node *Link;

typedef struct Node {
    int value;
    Link next;
} Node;

typedef struct BagRep {
    Node *list;
} BagRep;

// Count number of distinct values (assuming no counter)
// Time complexity ??
int BagNumUniq(Bag b) {
    int a[MAX_BAG];
    int n = 0;
    int i;
    Node *curr;

    for (curr = b->list; curr != NULL; curr = curr->next) {
        for (i = 0; i < n; i++) {
            if (curr->value == a[i]) break;
        }
        if (i == n) {
            a[n++] = curr->value;
        }
    }
    return n;
}
