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
  * Exp(Z) = e^Z = (e^a * Cos(b) + e^a * Sin(b)i)
  *
  * @param Complex * x: Exponent of the function
  *
  * @return Complex * e^z
  */
Complex * complex_exp(Complex * self)
{
  Real ** x = self->getElements(self);
  Real * a = real_prod(x[0]->exp(x[0]), x[1]->cos(x[1]));
  Real * b = real_prod(x[0]->exp(x[0]), x[1]->sin(x[1]));
  return Complex_new(a->get(a), b->get(b));
}
