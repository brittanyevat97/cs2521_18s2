#include "q2.h"
#include <string.h>


static void wrong(char* msg);
static void right(char* msg);

static void right(char* msg) {
    printf("    \x1B[32m");
    printf("%s",msg);
    printf("\x1B[0m\n");
}
static void wrong(char* msg) {
    printf("    \x1B[31m");
    printf("%s",msg);
    printf("\x1B[0m\n");
}
static Link newNode(char c) {
    Link new = malloc(sizeof(node));
    new->next = new->prev = NULL;
    new->value = c;
    return new;
}
static int checkList(List l, Link* nodes, int size) {
    if (size == 0 && l->head != NULL) return FALSE;
    if (size == 0 && l->tail != NULL) return FALSE;
    if (size == 0 && l->head == NULL && l->tail == NULL) return TRUE;
    int i = 0;
    int ok = TRUE;
    Link curr = l->head;
    for (i=0; curr != NULL;i++,curr=curr->next)
        ok = ok && (curr == nodes[i]) && (curr->value == nodes[i]->value);
    ok = ok && (i == size) && (l->tail == nodes[size-1]);
    return ok;
}

static int runTest(char* in, int result, char* msg) {
    printf("%s",msg);
    int passed = TRUE;
    int len = strlen(in);
    List l = malloc(sizeof(struct _list));
    l->head = NULL;
    l->tail = NULL;
    Link *nodes = NULL;

    if (len != 0) nodes = malloc(sizeof(Link)*len);
    int i = 0;
    for(i=0;i < len; i++) nodes[i] = newNode(in[i]);
    for(i=0;i < len-1; i++){ 
        nodes[i]->next = nodes[i+1];
        nodes[i+1]->prev = nodes[i];
    }
    if (len != 0){
        l->head = nodes[0];
        l->tail = nodes[len-1];
    }
    if (isPalindrome(l) != result) {
        wrong("Incorrect Answer");
        passed = FALSE;
    }
    if (!checkList(l,nodes,len)) {
        wrong("Original List Altered");
        Link curr = NULL;
        printf("\x1B[31m");
        char h = 'X';
        char t = 'X';
        if (l->head != NULL) h = l->head->value;
        if (l->tail != NULL) h = l->tail->value;

        printf("    Your l: [head %c  | tail %c] ",h,t);
        for(curr=l->head;curr!=NULL;curr=curr->next)
            printf("%c->",curr->value);
        printf("X\x1B[0m\n");

        passed = FALSE;
    }
    for(i=0;i < len; i++) free(nodes[i]);
    if (nodes != NULL) free(nodes);
    free(l);
    if (passed) right("[PASSED]");
    else wrong("[FAILED]");
    return passed;
}

static void runAutotests() {
    int p = 0;
    p += runTest("",TRUE,"Test 1: ''\n");
    p += runTest("a",TRUE,"Test 2: 'a'\n");
    p += runTest("b",TRUE,"Test 3: 'b'\n");
    p += runTest("ab",FALSE,"Test 4: 'ab'\n");
    p += runTest("aba",TRUE,"Test 5: 'aba'\n");
    p += runTest("abb",FALSE,"Test 6: 'abb'\n");
    p += runTest("bbb",TRUE,"Test 7: 'bbb'\n");
    p += runTest("ababa",TRUE,"Test 8: 'ababa'\n");
    p += runTest("aaabbbaaa",TRUE,"Test 9: 'aaabbbaaa'\n");
    p += runTest("peterpiperrepipretep",TRUE,"Test 10: 'peterpiperrepipretep'\n");
    p += runTest("peterpiperrepipreteo",FALSE,"Test 11: 'peterpiperrepipreteo'\n");
    p += runTest("abcdefedcba",TRUE,"Test 12: 'abcdefedcba'\n");
    p += runTest("abccba",TRUE,"Test 13: 'abccba'\n");
    p += runTest("abccza",FALSE,"Test 14: 'abccza'\n");
    p += runTest("aaabbbb",FALSE,"Test 15: 'aaabbbb'\n");
    p += runTest("aaaabbb",FALSE,"Test 16: 'aaaabbb'\n");
    p += runTest("aa",TRUE,"Test 17: 'aa'\n");
    if (p == 17) right("\n============[ALL TESTS PASSED]============");
}

int main (int argc, char * argv[]){
    // comment this line out and write your own code 
    // if you wish to debug or test
    runAutotests();

    return EXIT_SUCCESS;
}
