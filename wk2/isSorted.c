#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Pre:
// - a[] is a valid pointer to the start of an array of ints
// - n is a positive int indicating how many elements in a[]
// Post:
// - return value = forall i ∈ {0..n-2} ( a[i] ≤ a[i+1] ) (sorted)
//                  AND set (no duplicates)
//                  AND all positive
bool isSorted(int *a, int n) {
    if (a[0] < 0) return false;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] >= a[i+1]) return false;
    }
    return true;
}

