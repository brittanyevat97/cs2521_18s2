#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define TRUE 1
#define FALSE 0

/*
 * Question 2
 * by Zain Afzal 11/08/2018
 * cs2521 2018 s2
 */

typedef struct _node *Link;
 
typedef struct _node {
    char value;
	Link next;
	Link prev;
} node;
 
// a list is represented by a pointer to a struct which contains 
// a pointer to the first node of the list called the "head"
// and the last node called "tail"
typedef struct _list {
    Link head;
    Link tail;
} *List;

int isPalindrome(List l);


