// Read lines of text from stdin; display them in reverse order
// Assumes no more than 1000 lines; lines longer than 100 are truncated

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int  n=0;           // counter/index
    char thisline[100]; // current line
    char *lines[1000];  // array of lines

    // read lines into array of strings
    while (fgets(thisline,100,stdin) != NULL)
        // lines[n++] = thisline; // OLD LINE
        // The variable thisline is a pointer to the first element
        // of the array. By setting each element in the array lines
        // to hold the value of thisline, they will all be storing
        // the same address. We need to instead create a copy of the
        // string, i.e. store it in a new memory location.
        lines[n++] = strdup(thisline);

    // print lines in reverse order
    while (n-- > 0)
        fputs(lines[n],stdout);

    return EXIT_SUCCESS;
}
