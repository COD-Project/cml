#ifndef RAT_H
#define RAT_H


typedef struct rational
{
  // Parent
  Field * super;
  // Instance variables
  int num;
  int den;
  

  // Functions
} Rational;


// Constructor && destructor
Rational * Rational_new(double, double);
void Rational_destruct(Rational *);

#endif
