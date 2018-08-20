#include "q1.h"


static void wrong(char* msg);
static void right(char* msg);

static Link newNode(int val) {
    Link n = malloc(sizeof(node));
    n->next = NULL;
    n->value = val;
    return n;
}
static int checkList(List l, Link* nodes, int size, char* msg) {
    if (size == 0 && l->head != NULL) {
        wrong("Invalid head");
        return FALSE;
    }
    int i = 0;
    int ok = TRUE;
    Link curr = l->head;
    for (i=0; curr != NULL;i++,curr=curr->next)
        ok = ok && (curr == nodes[i]) && (curr->value == nodes[i]->value);
    ok = ok && (i == size);
    if (!ok) {
        printf("\x1B[31m");
        printf("    %s: ",msg);
        for(curr=l->head;curr!=NULL;curr=curr->next)
            printf("%d->",curr->value);
        printf("X\x1B[0m\n");
    }
    return ok;
}
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
static int runTest(int size,int *arr, int split, char* msg) {
    printf("%s",msg);
    int i = 0;
    List l = malloc(sizeof(struct _list));
    Link *nodes = NULL;
    Link random = newNode(1);
    int passed = TRUE;
    // set up 
    if (size > 0) {
        nodes = malloc(sizeof(Link)*size);
        for(i=0;i<size;i++) 
            nodes[i] = newNode(arr[i]);
        for(i=0;i<size-1;i++) 
            nodes[i]->next = nodes[i+1];
        l->head = nodes[0];
    } else {
        l->head = NULL;
    }

    // run 
    if (split == -2) splitAtNode(l,random);
    else if (split == -1) splitAtNode(l,NULL);
    else splitAtNode(l,nodes[split]);

    // check
    if (split < 0 && !checkList(l,nodes,size,"your l")) {
        wrong("[FAILED]\n");
        passed = FALSE;
    }
    if (split >= 0){
        if(!checkList(l,nodes,split,"your l")) {
            wrong("[FAILED]\n");
            passed = FALSE;
        } else {
            l->head = nodes[split];
            if(!checkList(l,nodes+split,size-split,"your n")) {
                wrong("[FAILED]\n");
                passed = FALSE;
            }
        }
    }
    if (passed) right("[PASSED]");
    
    // free
    for(i=0;i<size;i++) 
        free(nodes[i]);
    if (nodes != NULL) free(nodes);
    free(l);
    free(random);
    return passed;
}

static void runAutotests() {
    int p = 0;
    p += runTest(0,NULL,-1,"Test 1: l = X | n = NULL\n");
    p += runTest(0,NULL,-2,"Test 2: l = X | n = pointer to node not in list\n");
    int a[1] = {1};
    p += runTest(1,a,-1,"Test 3: l = 1->X | n = NULL\n");
    p += runTest(1,a,-2,"Test 4: l = 1->X | n = pointer to node not in list\n");
    p += runTest(1,a,0, "Test 5: l = 1->X | n = l->head\n");
    int b[3] = {1,2,3};
    p += runTest(3,b,-1,"Test 6: l = 1->2->3->X | n = NULL\n");
    p += runTest(3,b,-2,"Test 7: l = 1->2->3->X | n = pointer to node not in list\n");
    p += runTest(3,b,0, "Test 8: l = 1->2->3->X | n = l->head\n");
    p += runTest(3,b,1, "Test 9: l = 1->2->3->X | n = 2\n");
    p += runTest(3,b,2, "Test 10: l = 1->2->3->X | n = 3\n");
    int c[3] = {1,1,1};
    p += runTest(3,c,-1,"Test 11: l = 1->1->1->X | n = NULL\n");
    p += runTest(3,c,-2,"Test 12: l = 1->1->1->X | n = pointer to node not in list\n");
    p += runTest(3,c,0, "Test 13: l = 1->1->1->X | n = l->head\n");
    p += runTest(3,c,1, "Test 14: l = 1->1->1->X | n = 2nd 1\n");
    p += runTest(3,c,2, "Test 15: l = 1->1->1->X | n = 3rd 1\n");
    int d[2] = {1,5};
    p += runTest(2,d,-1,"Test 16: l = 1->5->X | n = NULL\n");
    p += runTest(2,d,-2,"Test 17: l = 1->5->X | n = pointer to node not in list\n");
    p += runTest(2,d,0, "Test 18: l = 1->5->X | n = l->head\n");
    p += runTest(2,d,1, "Test 19: l = 1->5->X | n = 5\n");
    int e[5] = {1,2,3,4,5};
    p += runTest(5,e,0, "Test 20: l = 1->2->3->4->5->X | n = l->head\n");
    p += runTest(5,e,4, "Test 21: l = 1->2->3->4->5->X | n = 5\n");
    p += runTest(5,e,2, "Test 22: l = 1->2->3->4->5->X | n = 3\n");
    if (p == 22) right("\n============[ALL TESTS PASSED]============");
}

int main (int argc, char * argv[]){
    // comment this line out and write your own code 
    // if you wish to debug or test
    runAutotests();

    return EXIT_SUCCESS;
}
