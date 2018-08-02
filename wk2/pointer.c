#include <stdio.h>
#include <stdlib.h>

// Example of pass by value
void f(int v) {
    v = 5;
}

// Example of pass by reference
void g(int *v) {
    *v = 5;
}

// Example of pass by reference
// How is this different to previous example?
// What are we changing? Is this change seen in main? Why / why not?
void h(int *v) {
    int x = 5;
    v = &x;
}

int main(int argc, char *argv[]) {
    int v = 1;

    f(v);
    printf("After call to f: v has address %p, v has value %d\n", &v, v);

    v = 1;
    g(&v);
    printf("After call to g: v has address %p, v has value %d\n", &v, v);

    v = 1;
    h(&v);
    printf("After call to h: v has address %p, v has value %d\n", &v, v);

    return 0;
}
