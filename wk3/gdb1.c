// Read numbers from stdin; print their sum on stdout

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int n;   // current value
    // int sum; // OLD LINE - was not initialising sum
    int sum = 0; // sum of values

    while (scanf("%d",&n) == 1)
        sum += n;
    printf("%d\n", sum);
    return EXIT_SUCCESS;
}
