// getPeaks.c 
// Written by Ashesh Mahidadia, August 2017

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "DLList.h"


/* 
    You will submit only this one file.

    Implement the function "getPeaks" below. Read the exam paper for 
    detailed specification and description of your task.  

    - DO NOT modify code in the file DLList.h . 
    - You can add helper functions in this file.  
    - DO NOT add "main" function in this file. 
    
*/

DLList getPeaks(DLList L){
	DLList peaksL = newDLList();
    if (L->nitems < 3) return peaksL;

    DLListNode *curr = L->first->next;
    while (curr != L->last) {
        if (curr->value > curr->prev->value && curr->value > curr->next->value) {
            DLListNode *new = newDLListNode(curr->value);
            // when adding to new list, need to check two cases
            if (peaksL->nitems == 0) {
                // peaksL is empty
                peaksL->first = peaksL->last = peaksL->curr = new;
            } else {
                // otherwise, append to end
                peaksL->last->next = new;
                new->prev = peaksL->last;
                peaksL->last = new;
            }
            peaksL->nitems++;
        }
        curr = curr->next;
    }

	return peaksL;
}




