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

#define RNEUT_H
#include "../../includes/cml.h"

/**
  * Hyperbolic Functions using Euler relationships and Taylor Series
  */

/**
  * Hyperbolic sine "real_sinh(x)" function developed by using Euler relationships
  *
  * @param Real * x
  *
  * @return Real * real_sinh(x)
  */
Real * real_sinh(Real * x)
{
  return real_prod(x->sgn(x), real_div(real_sub(real_exp(x->sgn(x)), real_exp(real_prod(real_abs(x), Real_new(-1.0)))), Real_new(2.0)));
}

/**
  * Hyperbolic cosine "real_cosh(x)" function developed by using Euler relationships
  *
  * @param Real * x
  *
  * @return Real * real_cosh(x)
  */
Real * real_cosh(Real * x)
{
  Real * y = x->abs(x);
  Real * z1 = y->exp(y);
  Real * z_2 = Real_new(-y->get(y));
  Real * z2 = z_2->exp(z_2);
  Real * e = z1->add(z1, z2);
  return Real_new(e->get(e)/2);
}

/**
  * Hyperbolic tangent "tanh(x)" function developed by using Euler relationships
  *
  * @param Real * x
  *
  * @return Real * tanh(x)
  */
Real * real_tanh(Real * x)
{
  Real * y = x->sinh(x);
  Real * z = x->cosh(x);
  return (z->get(z) == 0) ? Real_new(NAN) : Real_new(y->get(y) / z->get(z));
}

/**
  * sech(x) function developed by using Euler relationships
  *
  * @param Real * x
  *
  * @return Real * sech(x)
  */
Real * real_sech(Real * x)
{
  Real * z = x->cosh(x);
  return (z->get(z) == 0) ? Real_new(NAN) : Real_new(1 / z->get(z));
}

/**
  * csch(x) function developed by using Euler relationships
  *
  * @param Real * x
  *
  * @return Real * csch(x)
  */
Real * real_csch(Real * x)
{
  Real * z = x->sinh(x);
  return (z->get(z) == 0) ? Real_new(NAN) : Real_new(1 / z->get(z));
}

/**
  * coth(x) function developed by using Euler relationships
  *
  * @param Real * x
  *
  * @return Real * coth(x)
  */
Real * real_coth(Real * x)
{
  Real * y = x->sinh(x);
  Real * z = x->cosh(x);
  return (y->get(y) == 0) ? Real_new(NAN) : Real_new(z->get(z) / y->get(y));
}

/**
  * arctanh(x) function developed by using Taylor Series
  *
  * @param Real * x
  *
  * @return Real * arctanh(x)
  */
Real * real_atanh(Real * x)
{
  int i;
  Real * z = x->abs(x);
  if (z->get(z) >= 1) {
    return Real_new(NAN);
  }
  double y = x->get(x),
         ai_n = y,
         p = ai_n;
  for (i = 1; i <= TOPL; i += 2) {
    ai_n = ai_n*y*y;
    p = p + ai_n/(i+2);
  }
  return Real_new(p);
}
