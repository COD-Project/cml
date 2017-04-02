/* Copyright (C) 2017 COD-Project

This file is part of CML.

CML is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

CML is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with CML. If not, see <http://www.gnu.org/licenses/>.     */

#define RBAF_H
#include "../../includes/cml.h"


/**
  * Functions developed by using math definitions
  */

/**
  * ln(x) function developed by using hyperbolic definition of Taylor Series
  * where ln(x) = arctanh((x^2 - 1)/(x^2 - 1)) (this is not the best way to do this!)
  *
  * @param Real * x
  *
  * @return Real * log(x)
  */
Real * real_ln(Real * x)
{
  Real * z = x->prod(x, x);
  Real * z_1 = z->sub(z, Real_new(1));
  Real * z2 = z->add(z, Real_new(1));
  Real * z1 = z_1->div(z_1, z2);
  return (x->get(x) > 0) ? z1->atanh(z1) : Real_new(NAN);
}

Real * real_logE(Real * x)
{
  return x->ln(x);		/* Natural log */
}

/**
  * The logarithm logb(x) can be computed from the logarithms of x and b with respect to an arbitrary base k using the following formula:
  * log_b{x} = log_k{x} / log_k(b)
  *
  * @param Real * x
  *
  * @return Real * log_b(x)
  */

Real * real_logB(Real * x, Real * y)
{
  Real * z = y->ln(y);
  Real * z1 = x->ln(x);
  return (y->get(y) == 0) ? Real_new(NAN) : z1->div(z1, z);
}

Real * real_log(Real * x)
{
  return x->logB(x, Real_new(10.0));
}

/**
  * Development of the Taylor series of the function e^x
  *
  * @param Real * x: Exponent of the function
  *
  * @return Real * e^x
  */
Real * real_exp(Real * x)
{
  int i;
  double ai = 1.0,
      ex = ai;
  for (i = 1; i <= TOPL; i++) {
    ai = ai*(x->get(x))/i;
    ex = ex + ai;
  }
  return Real_new(ex);
}

/**
  * pow(f, g) function developed by using the exponentiation process
  * where pow(f, g) = sgn(f)e^(glog(|f|))
  *
  * @param Real * x
  *
  * @return Real * pow(f, g)
  */
Real * real_pow(Real * f, Real * g)
{
  Real * z = f->abs(f);
  Real * z_1 = z->ln(z);
  Real * z_2 = z_1->prod(z_1, g);
  Real * z1 = z_2->exp(z_2);
  return (f->get(f) == 0) ? ((g->get(g) == 0) ? Real_new(NAN) : Real_new(0)) : z1->prod(z1, f->sgn(f));
}

/**
  * root(f, g) function developed by using the exponentiation process
  *
  * @param Real * x
  *
  * @return Real * root(f, g)
  */
Real * real_root(Real * f, Real * g)
{
  return (isnat(g->get(g)) == 1) ? f->pow(f, g->pow(g, Real_new(-1))) : Real_new(NAN);
}

/**
  * square root(f, g) function developed by using the exponentiation process
  *
  * @param Real * x
  *
  * @return Real * sqrt(f, g)
  */
Real * real_sqrt(Real * f)
{
  return (f->get(f) >= 0) ? f->root(f, Real_new(2.0)) : Real_new(NAN);
}
