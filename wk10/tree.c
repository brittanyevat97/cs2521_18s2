#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct BSTNode *BSTree;

typedef struct BSTNode {
    int value;
    BSTree left;
    BSTree right;
} BSTNode;

BSTree newNode(int v) {
    BSTree new = malloc(sizeof(BSTNode));
    assert(new != NULL);
    new->value = v;
    new->left = new->right = NULL;
    return new;
}

// insert a new value into a binary search tree
// iteratively
BSTree insert(BSTree t, int v) {
    // if tree is empty, return new node
    BSTree new = newNode(v);
    if (t == NULL) return new;
    // else, we need a parent node to keep track of
    // the previous node
    BSTree curr = t;
    BSTree parent;
    while (curr != NULL) {
        parent = curr;
        if (v < curr->value)
            curr = curr->left;
        else if (v > curr->value)
            curr = curr->right;
        else {
            free(new);
            return t;
        }
    }
    // insert new node either as left or right subtree
    // of parent
    if (v < parent->value)
        parent->left = new;
    else
        parent->right = new;
    return t;
}

// recursive version
BSTree insertR(BSTree t, int v) {
    if (t == NULL) return newNode(v);
    if (v < t->value)
        t->left = insertR(t->left, v);
    else if (v > t->value)
        t->right = insertR(t->right, v);
    return t;
}

// search for a value in a BSTree
// return 1 if found, 0 otherwise
int BSTreeFind(BSTree t, int v) {
    if (t == NULL) return 0;
    if (t->value == v) return 1;
    if (v < t->value) return BSTreeFind(t->left, v);
    if (v > t->value) return BSTreeFind(t->right, v);
}

// compute the maximum branch length of a BSTree
// (number of edges on longest path from root to a leaf)
int BSTreeMaxBranchLen(BSTree t) {
    if (t == NULL) return 0;
    if (t->left == NULLL && t->right == NULL) return 0;
    int l = BSTreeMaxBranchLen(t->left);
    int r = BSTreeMaxBranchLen(t->right);
    return 1 + (l > r ? l : r);
}

// compute width of a BSTree
int BSTWidth(BSTree t) {
    if (t == NULL) return 0;
    if (t->left == NULL && t->right == NULL) return 3;
    return 3 + BSTWidth(t->left) + BSTWidth(t->right);
}

// print out the values of each node in the tree 
// in infix order
void BSTreeInfix(BSTree t) {
    if (t == NULL) return;
    BSTreeInfix(t->left);
    printf("%d ", t->value);
    BSTreeInfix(t->right);
}

// find maximum value in a binary tree
int BTMaxValue(BSTree t) {

}

// return 1 if t is a binary search tree, 0 if not
int isBSTree(BSTree t) {

}

