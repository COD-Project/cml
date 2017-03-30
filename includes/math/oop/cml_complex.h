#ifndef COMPLEX_H
#define COMPLEX_H


typedef struct complex
{
  // Parent
  Field * super;
  double re;
  double im;
  double (*getRe)(struct complex *);
  void (*setRe)(struct complex *, double);
  double (*getIm)(struct complex *);
  void (*setIm)(struct complex *, double);
  double (*getMod)(struct complex *);
  void (*setMod)(struct complex *, double);
  double (*getArg)(struct complex *);
  void (*setArg)(struct complex *, double);
  // Composition laws
  struct complex * (*add)(struct complex *, struct complex *);
  struct complex * (*prod)(struct complex *, struct complex *);
} Complex;

// Methods
double get_complex_real(Complex *);
void set_complex_real(Complex *, double);
double get_complex_im(Complex *);
void set_complex_im(Complex *, double);
double get_complex_module(Complex *);
double get_complex_argument(Complex *);

// Composition laws
Complex * complex_add(Complex *, Complex *);
Complex * complex_prod(Complex *, Complex *);

// Constructor && destructor
Complex * Complex_new();
void Complex_destruct(Complex *);

#endif
