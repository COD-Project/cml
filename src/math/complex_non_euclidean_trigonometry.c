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

#include "../../includes/cml.h"


/**
  * Hyperbolic Functions using Euler relationships
  */

/**
  * Hyperbolic sine "complex_sinh(z)"
  *
  * @param Complex * self
  *
  * @return Complex * complex_sinh(z)
  */
Complex * complex_sinh(Complex * self)
{
  Real ** e = self->getElements(self);
  Complex * z1 = Complex_new(-e[0]->get(e[0]), -e[1]->get(e[1]));
  Complex * z = complex_sub(complex_exp(self), complex_exp(z1));
  return z->div(z, Complex_new(2.0, 0.0));
}

/**
  * Hyperbolic cosine "complex_cosh(z)"
  *
  * @param Complex * self
  *
  * @return Complex * complex_cosh(z)
  */
Complex * complex_cosh(Complex * self)
{
  Real ** e = self->getElements(self);
  Complex * z1 = Complex_new(-e[0]->get(e[0]), -e[1]->get(e[1]));
  Complex * z = complex_add(complex_exp(self), complex_exp(z1));
  return z->div(z, Complex_new(2.0, 0.0));
}

/**
  * Hyperbolic tangent "tanh(z)"
  *
  * @param Complex * self
  *
  * @return Complex * tanh(z)
  */
Complex * complex_tanh(Complex * self)
{
  Complex * zsinh = self->sinh(self);
  Complex * zcosh = self->cosh(self);
  Real * a = zcosh->abs(zcosh);
  return (a->get(a) == 0) ? Complex_new(NAN, NAN) : zsinh->div(zsinh, zcosh);
}

/**
  * sech(z)
  *
  * @param Complex * self
  *
  * @return Complex * sech(z)
  */
Complex * complex_sech(Complex * self)
{
  Complex * zcosh = self->cosh(self);
  Real * a = zcosh->abs(zcosh);
  return (a->get(a) == 0) ? Complex_new(NAN, NAN) : zcosh->inverse(zcosh);
}

/**
  * csch(z)
  *
  * @param Complex * self
  *
  * @return Complex * csch(z)
  */
Complex * complex_csch(Complex * self)
{
  Complex * zsinh = self->sinh(self);
  Real * a = zsinh->abs(zsinh);
  return (a->get(a) == 0) ? Complex_new(NAN, NAN) : zsinh->inverse(zsinh);
}

/**
  * coth(z)
  *
  * @param Complex * self
  *
  * @return Complex * coth(z)
  */
Complex * complex_coth(Complex * self)
{
  Complex * zsinh = self->sinh(self);
  Complex * zcosh = self->cosh(self);
  Real * a = zsinh->abs(zsinh);
  return (a->get(a) == 0) ? Complex_new(NAN, NAN) : zcosh->div(zcosh, zsinh);
}
