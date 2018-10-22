#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct BSTNode *BSTree;

typedef struct BSTNode {
    int value;
    BSTree left;
    BSTree right;
    // Add a field used to mark nodes as deleted, 
    // rather than physically removing them from the tree
    // 1 if node is deleted from tree, 0 if node exists in tree
    int deleted;
} BSTNode;

BSTree newNode(int v) {
    BSTree new = malloc(sizeof(BSTNode));
    assert(new != NULL);
    new->value = v;
    new->left = new->right = NULL;
    // initialise deleted field to 0
    new->deleted = 0;
    return new;
}

// search for a value in a BSTree
// return 1 if found, 0 otherwise
int BSTreeFind(BSTree t, int v) {
    if (t == NULL) 
        return 0;
    else if (v < t->value)
        return BSTreeFind(t->left, v);
    else if (v > t->value)
        return BSTreeFind(t->right, v);
    else if (t->deleted) // v == t->value
        return 0;
    else // v == t->value && !t->deleted
        return 1;
}

// count #values in BSTree
int BSTreeNumValues(BSTree t) {
    if (t == NULL) 
        return 0;
    // Need to either count or ignore current node
    return (t->deleted ? 0 : 1) + BSTreeNumValues(t->left) + BSTreeNumValues(t->right);
    // OR could do:
    // return !t->deleted + BSTreeNumValues(t->left) + BSTreeNumValues(t->right);
}

// delete a value from a BSTree
BSTree BSTreeDelete(BSTree t, int v) {
    if (t == NULL)
        return t;
    else if (v < t->value)
        t->left = BSTreeDelete(t->left, v);
    else if (v > t->value)
        t->right = BSTreeDelete(t->right, v);
    else // v == t->value
        t->deleted = 1;
    return t;
}

// print infix list of BSTree values
void showBSTreeInfix(BSTree t) {
    if (t == NULL) return;
    showBSTreeInfix(t->left);
    // do not print if node is deleted
    if (t->deleted == 0) printf("%d ", t->value);
    showBSTreeInfix(t->right);
}

// insertion with re-use of deleted nodes

// find maximum element in a tree
int max(BSTree t) {
    if (t == NULL) return INT_MIN;
    while (t->right != NULL) t = t->right;
    return t->value;
}

// find minimum element in a tree
int min(BSTree t) {
    if (t == NULL) return INT_MAX;
    while (t->left != NULL) t = t->left;
    return t->value;
}

BSTree BSTreeInsert(BSTree t, int v) {
    if (t == NULL)
        return newNode(v);
    else if (t->deleted && t->value == v)
        t->deleted = 0;
    // if node is deleted, but can be replaced with v
    // need to check that v is greater than everything in the left subtree
    // (can do this by checking that is greater than the max value of left subtree)
    // and also check that v is less than everything in the right subtree
    // (again, by checking that it is less than the min value of the right subtree)
    else if (t->deleted && v > max(t->left) && v < min(t->right)) {
        t->value = v;
        t->deleted = 0;
    } else if (v < t->value)
        t->left = BSTreeInsert(t->left, v);
    else if (v > t->value)
        t->right = BSTreeInsert(t->right, v);
    // if none of these cases match, then v == t->value && t->deleted == 0
    return t;
    
}
