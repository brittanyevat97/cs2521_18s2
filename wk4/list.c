#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct ListNode *Link;

typedef struct ListNode {
    int value;
    Link next;
} ListNode;

typedef Link List;

#define head(L)  (empty(L) ? -1 : (L)->value)
#define tail(L)  (empty(L) ? NULL : (L)->next)
#define empty(L) ((L) == NULL)

// display the value contained in a ListNode
#define show(V) { printf("%d",(V)); }

// create a new ListNode containing supplied value
// prints error and exit()s if can't create a ListNode
Link newNode(int val) {
    Link new = malloc(sizeof(struct ListNode));
    assert(new != NULL);
    new->value = val;
    new->next = NULL;
    return new;
}

// write a recursive function to remove a list
void drop(List L) {
    if (empty(L)) return;
    drop(tail(L));
    free(L);
}

// write a recursive function to make a copy of a list
List copy(List L) {
    if (empty(L)) return NULL;
    List new = newNode(head(L));
    new->next = copy(tail(L));
    return new;
}
