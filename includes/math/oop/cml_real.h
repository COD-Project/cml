#ifndef REAL_H
#define REAL_H


typedef struct _real
{
  // Parent
  Field * super;
  // Instance variables
  double real_part;
  // Methods
  double (*get)(struct _real *);
  void (*set)(struct _real *, double);
  char * (*toString)(struct _real *);

  // Composition laws
  struct _real * (*add)(struct _real *, struct _real *);
  struct _real * (*prod)(struct _real *, struct _real *);
  // ---> Usefull Functions <---
  struct _real * (*sgn)(struct _real *);
  struct _real * (*abs)(struct _real *);

  // ---> Basic Functions <---
  struct _real * (*sub)(struct _real *, struct _real *);
  struct _real * (*div)(struct _real *, struct _real *);
  struct _real * (*divE)(struct _real *, struct _real *);
  struct _real * (*mod)(struct _real *, struct _real *);
  struct _real * (*ared)(struct _real *);
  struct _real * (*fact)(struct _real *);
  struct _real * (*ceil)(struct _real *);
  struct _real * (*floor)(struct _real *);
  // ---> Euler definitions <---
  struct _real * (*exp)(struct _real *);

  // ---> Usefull functions
  struct _real * (*ln)(struct _real *);
  struct _real * (*logE)(struct _real *);
  struct _real * (*logB)(struct _real *, struct _real *);
  struct _real * (*log)(struct _real *);
  struct _real * (*pow)(struct _real *, struct _real *);
  struct _real * (*root)(struct _real *, struct _real *);
  struct _real * (*sqrt)(struct _real *);

  struct _real * (*pit)(struct _real *, struct _real *);

  // ---> Basic trigonometric functions <---
  struct _real * (*sin)(struct _real *);
  struct _real * (*cos)(struct _real *);
  struct _real * (*tan)(struct _real *);
  struct _real * (*sec)(struct _real *);
  struct _real * (*csc)(struct _real *);
  struct _real * (*cot)(struct _real *);
  struct _real * (*atan)(struct _real *);
  struct _real * (*atan2)(struct _real *);
  // ---> Hyperbolic functions
  struct _real * (*sinh)(struct _real *);
  struct _real * (*cosh)(struct _real *);
  struct _real * (*tanh)(struct _real *);
  struct _real * (*sech)(struct _real *);
  struct _real * (*csch)(struct _real *);
  struct _real * (*coth)(struct _real *);
  struct _real * (*atanh)(struct _real *);

  // Destructor
  void (*destruct)(struct _real *);
} Real;

// Methods
double get_real(Real *);
void set_real(Real *, double);

// Constructor && destructor
Real * Real_new(double);
void Real_destruct(Real *);

#endif
