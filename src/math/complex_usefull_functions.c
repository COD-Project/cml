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


Complex * complex_add(Complex * self, Complex * z1)
{
  // (a + bi) + (c + di) = (a+c) + (b+d)i
  Real ** x = self->getElements(self);
  Real ** y = z1->getElements(z1);
  Real * re = real_add(x[0], y[0]);
  Real * im = real_add(x[1], y[1]);
  return Complex_new(re->get(re), im->get(im));
}

Complex * complex_prod(Complex * self, Complex * z1)
{
  // (a + bi) · (c + di) = (ac − bd) + (ad + bc)i
  Real ** x = self->getElements(self);
  Real ** y = z1->getElements(z1);
  Real * re = real_sub(real_prod(x[0], y[0]), real_prod(x[1], y[1]));
  Real * im = real_add(real_prod(x[0], y[1]), real_prod(x[1], y[0]));
  return Complex_new(re->get(re), im->get(im));
}

Complex * complex_sub(Complex * self, Complex * z1)
{
  Real ** x = z1->getElements(z1);
  return self->add(self, Complex_new(-x[0]->get(x[0]), -x[1]->get(x[1])));
}

Complex * complex_div(Complex * self, Complex * y)
{
  return complex_prod(self, y->inverse(y));
}

Real * complex_abs(Complex * self)
{
  Real ** x = self->getElements(self);
  Real * y = x[0]->pow(x[0], Real_new(2.0));
  Real * z = x[1]->pow(x[1], Real_new(2.0));
  return real_sqrt(x[0]->add(y, z));
}

Complex * complex_conj(Complex * self)
{
  Real ** x = self->getElements(self);
  return Complex_new(x[0]->get(x[0]), -x[1]->get(x[1]));
}

Complex * complex_inverse(Complex * self)
{
  Complex * self_c = self->conj(self);
  Real ** x = self_c->getElements(self_c);
  Real * self_m = self->abs(self);
  double s_m = self_m->get(self_m);
  return Complex_new(x[0]->get(x[0])/s_m, x[1]->get(x[1])/s_m);
}
