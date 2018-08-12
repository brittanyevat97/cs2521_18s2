// Read numbers from stdin and build a linked list of these numbers. 

#include <stdio.h>
#include <stdlib.h>

typedef struct n { int data; struct n * next; } Node;
typedef Node *List;

int main(int argc, char *argv[])
{
    int  n;           // current input number
    Node *new, *p;    // new=new Node, p=cursor
    List nums = NULL; // linked list

    // for each number
    while (scanf("%d",&n) == 1) {
        // build node for number
        if ((new = malloc(sizeof(Node))) == NULL) {
            fprintf(stderr, "Out of memory\n"); exit(1);
        }
        new->data = n;
        new->next = NULL;

        // ADDED these 4 lines. Old code was giving a seg fault in the
        // following for loop, since nums is NULL on the first iteration
        // of the while loop.
        // NOTE that we cannot rely on using printf statements to debug
        // seg faults because of the way IO buffering works, as we
        // discussed in the tute. Use "\n" to flush buffer.
        if (nums == NULL) {
            nums = new;
            continue;
        }

        // find last node and append new node onto list
        for (p = nums; p->next != NULL; p = p->next)
            /* scan */ ;
        p->next = new;
    }

    // display contents of list
    printf("nums");
    for (p = nums; p != NULL; p = p->next)
        printf("->%d",p->data);
    printf("\n");

    return EXIT_SUCCESS;
}
