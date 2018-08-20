#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define TRUE 1
#define FALSE 0

/*
 * Question 1
 * By Matthew Di Meglio 31/05/2018
 * Modified by Zain Afzal 09/08/2018
 * cs2521 2018 s2
 */

typedef struct _node *Link;    // a link points to a node
 
typedef struct _node {
    int value;
	Link next;
} node;
 
// a list is represented by a pointer to a struct which contains 
// a pointer to the first node of the list called the "head"
typedef struct _list {
    Link head;
} *List; 

void splitAtNode(List l, Link n);


