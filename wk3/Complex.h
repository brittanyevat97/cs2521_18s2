// Interface to a complex numbers ADT

// Data structure - this is from the user's point of view
// (A pointer to the data structure itself - note that anyone
// using this ADT does not have access to the fields of the
// data structure)

typedef struct ComplexNum* Complex;

// Operations (add others as necessary..)

Complex newComplexNum(float real, float im);

float getRealPart(Complex c);

float getImPart(Complex c);

Complex addComplexNums(Complex a, Complex b);

void freeComplexNum(Complex c);
