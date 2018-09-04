#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a;
    int b;
} Item;

int isStableSort(Item original[], Item sorted[], int lo, int hi) {
    int i, j, key;
    i = lo;
    // iterate through sorted
    // note that duplicates are all in consecutive order in sorted array
    while (i <= hi) {
        // store key of sorted
        key = sorted[i].a;
        j = lo;
        // iterate through both sorted and original arrays
        // to check relative order of all duplicates of this key
        while (j <= hi) {
            // if we have checked all duplicates of this key, break
            if (sorted[i].a != key) break;
            // find next element containing this key in original array
            while (original[j].a != key) j++;
            // if order of duplicates has been changed, sort was not stable
            if (sorted[i].b != original[j].b) return 0;
            // advance to next position to check
            i++;
            j++;
        }
    }
    return 1;
}
