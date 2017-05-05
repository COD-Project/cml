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

#define RUSF_H
#include "../../includes/cml.h"


/**
  * Basic Functions
  */

// Returns the smallest integer value greater than or equal to x.
Real * real_ceil(Real * x)
{
  int z = (int) x->get(x);
  return (x->get(x) - z == 0.0) ? x : Real_new(z + 1.0);
}

// Returns the largest integer value less than or equal to x.
Real * real_floor(Real * x)
{
  return Real_new((int) x->get(x));
}

Real * real_sgn(Real * x)
{
  return Real_new(x->get(x) < 0 ? -1 : 1);
}

Real * real_abs(Real * x)
{
  return Real_new(x->get(x) < 0 ? -(x->get(x)) : (x->get(x)));
}

Real * real_add(Real * self, Real * r1)
{
  double re = self->get(self) + r1->get(r1);
  Real * z = Real_new(re);
  return z;
}

Real * real_prod(Real * self, Real * r1)
{
  double re = self->get(self)*r1->get(r1);
  Real * z = Real_new(re);
  return z;
}

Real * real_sub(Real * x, Real * y)
{
  Real * z = Real_new(-y->get(y));
  return x->add(x, z);
}

Real * real_div(Real * x, Real * y)
{
  return Real_new((y->get(y) == 0) ? NAN : x->get(x)/y->get(y));
}

Real * real_div_e(Real * x, Real * y)
{
  return real_floor(real_div(x, y));
}

Real * real_mod(Real * x, Real * y)
{
  return real_sub(x, real_prod(y, real_div_e(x, y)));
}

Real * real_ared(Real * x)
{
  return real_sub(x, real_prod(real_div_e(x, Real_new(TWOPI)), Real_new(TWOPI)));
}

Real * real_fact(Real * x)
{
  return x;
}
