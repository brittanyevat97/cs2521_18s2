#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// conditional expressions
int main (int argc, char *argv[]) {
    char ch;
    char *type;

    ch = getchar();
    if (isdigit(ch))
        type = "digit";
    else
        type = "non-digit";
    printf("'%c' is a %s\n", ch, type);

    // Example use of ternary operator
    type = isdigit(ch) ? "digit" : "non-digit";

    return 0;
}
