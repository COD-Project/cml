#ifndef RATN_H
#define RATN_H


typedef struct rational
{
  int num;
  int den;
  int (*getNum)(struct rational *);
  void (*setNum)(struct rational *, int);
  int (*getDen)(struct rational *);
  void (*setDen)(struct rational *, int);
  Real * (*getReal)(struct rational *);
  // Composition laws
  struct rational * (*add)(struct rational *, struct rational *);
  struct rational * (*prod)(struct rational *, struct rational *);
} Rational;

// Methods
int get_rational_num(Rational *);
void set_rational_num(Rational *, int);
int get_rational_den(Rational *);
void set_rational_den(Rational *, int);
Real * get_rational(Rational *);

// Composition laws
Rational * rational_add(Rational *, Rational *);
Rational * rational_prod(Rational *, Rational *);

// Constructor && destructor
Rational * Rational_new();
void Rational_destruct(Rational *);

#endif
