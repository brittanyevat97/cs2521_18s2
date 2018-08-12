// Implementation of a complex numbers ADT

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Complex.h"

// Data structure

typedef struct ComplexNum {
    float real;
    float im;
} ComplexNum;

// Operations

// Initialise a new complex number
Complex newComplexNum(float real, float im) {
    Complex c = malloc(sizeof(ComplexNum));
    assert(c != NULL);
    c->real = real;
    c->im = im;
    return c;
}

// Return the real part of a complex number
float getRealPart(Complex c) {
    return c->real;
}

// Return the imaginary part of a complex number
float getImPart(Complex c) {
    return c->im;
}

// Add two complex numbers
Complex addComplexNums(Complex a, Complex b) {
    float real = a->real + b->real;
    float im = a->im + b->im;
    return newComplexNum(real, im);
}

// Free a complex number
void freeComplexNum(Complex c) {
    free(c);
}
