// removeValue.c 
// Written by Ashesh Mahidadia, August 2017

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "DLList.h"


/* 
    You will submit only this one file.

    Implement the function "removeValue" below. Read the exam paper for 
    detailed specification and description of your task.  

    - DO NOT modify code in the file DLList.h . 
    - You can add helper functions in this file.  
    - DO NOT add "main" function in this file. 
    
*/


void removeValue(DLList L, int value) {
    DLListNode *curr = L->first;
    while (curr != NULL) {
        if (curr->value == value) {
            DLListNode *tmp = curr;
            // if we are the beginning, we must advance L->first
            // otherwise, the prev node exists, and we can set its
            // next pointer to curr->next
            if (curr == L->first)
                L->first = curr->next;
            else
                curr->prev->next = curr->next;

            // similar if we are at the end
            if (curr == L->last)
                L->last = curr->prev;
            else
                curr->next->prev = curr->prev;

            // in all cases, we must free the node and advance curr
            curr = curr->next;
            free(tmp);
            L->nitems--;
        } else {
            curr = curr->next;
        }
    }
    L->curr = L->first;
}
