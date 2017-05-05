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

#define REUT_H
#include "../../includes/cml.h"


/**
  * sin(x) function developed by using Taylor Series
  *
  * @param Real * x
  *
  * @return Real * sin(x)
  */
Real * real_sin(Real * x)
{
  Real * s = x->sgn(x);
  Real * y = real_ared(x->abs(x));
  double ai_n = y->get(y);
  double p = ai_n;
  int i;
  for (i = 1; i <= TOPL; ++i) {
    ai_n = -ai_n*(y->get(y))*(y->get(y))/(2*i*(2*i+1));
    p = p + ai_n;
  }
  return Real_new(ismult(y->get(y), PI) ? !ismult(y->get(y), PI) : p*s->get(s));
}

/**
  * cos(x) function developed by using Taylor Series
  *
  * @param Real * x
  *
  * @return Real * cos(x)
  */
Real * real_cos(Real * x)
{
  Real * y = x->abs(x);
  Real * z = y->add(y, Real_new(HALFPI));
  return z->sin(z);
}

/**
  * tan(x) function developed by using trigonometric identities
  *
  * @param Real * x
  *
  * @return Real * tan(x)
  */
Real * real_tan(Real * x)
{
  Real * z = x->cos(x);
  Real * z1 = x->sin(x);
  return (z->get(z) == 0) ? Real_new(NAN) : z1->div(z1, z);
}

/**
  * sec(x) function developed by using trigonometric identities
  *
  * @param Real * x
  *
  * @return Real * sec(x)
  */
Real * real_sec(Real * x)
{
  Real * z = x->cos(x);
  return (z->get(z) == 0) ? Real_new(NAN) : real_div(Real_new(1.0), z);
}

/**
  * csc(x) function developed by using trigonometric identities
  *
  * @param Real * x
  *
  * @return Real * csc(x)
  */
Real * real_csc(Real * x)
{
  Real * z = x->sin(x);
  return (z->get(z) == 0) ? Real_new(NAN) : real_div(Real_new(1.0), z);
}

/**
  * cot(x) function developed by using trigonometric identities
  *
  * @param Real * x
  *
  * @return Real * cot(x)
  */
Real * real_cot(Real * x)
{
  Real * z = x->cos(x);
  Real * z1 = x->sin(x);
  return (z1->get(z1) == 0) ? Real_new(NAN) : z->div(z, z1);
}

/**
  * arctan(x) function developed by using Taylor Series
  *
  * @param Real * x
  *
  * @return Real * arctan(x)
  */
/*
Real * real_atan(Real * x)
{

  int i;
  Real * ai_n = x;
  Real * p = ai_n;
  int top = 500;
  for (i = 1; i <= top; i += 2) {
    ai_n = -ai_n*x*x;
    p = p + ai_n/((Real *)i+2.0);
  }
  return p;

  return NAN;
}

Real * real_atan2(Real * y, Real * x)
{
  return (y == 0 && x == 0) ? Real_new(NAN) : HALFPI*real_sgn(y) - real_atan(y/x);
}
*/
