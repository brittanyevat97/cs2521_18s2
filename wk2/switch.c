#include <stdio.h>
#include <stdlib.h>

// switch statements
int main (int argc, char *argv[]) {
    char ch;
    printf("Please enter character: ");
    scanf("%c", &ch);

    // version 1
    switch (ch) {
        case 'a': printf("eh? "); break;
        case 'e': printf("eee "); break;
        case 'i': printf("eye "); break;
        case 'o': printf("ohh "); break;
        case 'u': printf("you "); break;
        default: printf("consonant ");
    }
    printf("\n");

    // version 2
    switch (ch) {
        case 'a': printf("eh? ");
        case 'e': printf("eee ");
        case 'i': printf("eye ");
        case 'o': printf("ohh ");
        case 'u': printf("you ");
    }
    printf("\n");

    return 0;
}
