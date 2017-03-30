#ifndef REALN_H
#define REALN_H


typedef struct real
{
  double re;
  double (*getRe)(struct real *);
  void (*setRe)(struct real *, double);
  // Composition laws
  struct real * (*add)(struct real *, struct real *);
  struct real * (*prod)(struct real *, struct real *);
} Real;

// Methods
double get_real(Real *);
void set_real(Real *, double);

// Composition laws
Real * real_add(Real *, Real *);
Real * real_prod(Real *, Real *);

// Constructor && destructor
Real * Real_new();
void Real_destruct(Real *);

#endif
