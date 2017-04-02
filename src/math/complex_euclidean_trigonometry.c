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
  * Sin(Z) = (Sin(a) * ((e^b + e^-b) / 2) + Cos(a) * ((e^b - e^-b) / 2)i)
  *
  * @param Complex * self
  *
  * @return Complex * sin(self)
  */
Complex * complex_sin(Complex * self)
{
  Real ** e = self->getElements(self);
  Real * re = real_prod(e[0]->sin(e[0]), e[1]->cosh(e[1]));
  Real * im = real_prod(e[0]->cos(e[0]), e[1]->sinh(e[1]));
  return Complex_new(re->get(re), im->get(im));
}

/**
  * Sinh(Z) = (Cos(b) * ((e^a - e^-a) / 2) + Sin(b) * ((e^a + e^-a) / 2)i)
  *
  * @param Complex * self
  *
  * @return Complex * cos(self)
  */
Complex * complex_cos(Complex * self)
{
  Real ** e = self->getElements(self);
  Real * re = real_prod(e[1]->cos(e[1]), e[0]->sinh(e[0]));
  Real * im = real_prod(e[1]->sin(e[1]), e[0]->cosh(e[0]));
  return Complex_new(re->get(re), im->get(im));
}

/**
  * tan(self)
  *
  * @param Complex * self
  *
  * @return Complex * tan(self)
  */
Complex * complex_tan(Complex * self)
{
  Complex * zsin = self->sin(self);
  Complex * zcos = self->cos(self);
  Real * a = zcos->abs(zcos);
  return (a->get(a) == 0) ? Complex_new(NAN, NAN) : zsin->div(zsin, zcos);
}

/**
  * sec(self) function developed by using trigonometric identities
  *
  * @param Complex * self
  *
  * @return Complex * sec(self)
  */
Complex * complex_sec(Complex * self)
{
  Complex * z = self->cos(self);
  Real * a = z->abs(z);
  return (a->get(a) == 0) ? Complex_new(NAN, NAN) : z->inverse(z);
}

/**
  * csc(self) function developed by using trigonometric identities
  *
  * @param Complex * self
  *
  * @return Complex * csc(self)
  */
Complex * complex_csc(Complex * self)
{
  Complex * z = self->sin(self);
  Real * a = z->abs(z);
  return (a->get(a) == 0) ? Complex_new(NAN, NAN) : z->inverse(z);
}

/**
  * cot(self) function developed by using trigonometric identities
  *
  * @param Complex * self
  *
  * @return Complex * cot(self)
  */
Complex * complex_cot(Complex * self)
{
  Complex * zsin = self->sin(self);
  Complex * zcos = self->cos(self);
  Real * a = zsin->abs(zsin);
  return (a->get(a) == 0) ? Complex_new(NAN, NAN) : zcos->div(zcos, zsin);
}
