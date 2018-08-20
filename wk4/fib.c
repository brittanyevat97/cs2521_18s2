#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// implement a new version of fib which uses a cached array
// in order to only compute fib(i) once for any value i

// recursive function
int fibR(int n, int *knownFib) {
    if (n == 1 || n == 2)
        return 1;
    if (knownFib[n-1] == 0)
        knownFib[n-1] = fibR(n-1, knownFib);
    if (knownFib[n-2] == 0)
        knownFib[n-2] = fibR(n-2, knownFib);
    return knownFib[n-1] + knownFib[n-2];
}

// wrapper function for fibR
int fib(int n) {
    int *knownFib = calloc(n + 1, sizeof(int));
    assert(knownFib != NULL);
    knownFib[1] = knownFib[2] = 1;
    int f = fibR(n, knownFib);
    free(knownFib);
    return f;
}
