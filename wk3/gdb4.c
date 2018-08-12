// Read numbers from stdin; write sorted numbers on stdout

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i, n;       // i=index, n=counter
    int vec[1000];  // array of integers
    int icompare(const void *, const void *);

    n = 0;
    while (scanf("%d",&vec[n]) == 1)
        n++;
    qsort(vec, n, sizeof(int), icompare);
    for (i = 0; i < n; i++)
        printf("%d ",vec[i]);
    printf("\n");
    return EXIT_SUCCESS;
}

int icompare(const void *a, const void *b)
{
    // return (a-b); // OLD LINE

    // a and b are void* pointers. We need to cast them to
    // int* pointers and then dereference them to get the 
    // values of the integers they are pointing to rather than
    // the addresses themselves
    int aNum = *(int *)a;
    int bNum = *(int *)b;
    return (aNum - bNum);
}
