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


#include "../../../includes/cml.h"


// Constructor
Real * Real_new()
{
  // Parent constructor
  self->super = Field_new(self->super);
  self = malloc(4*sizeof(double) + 8*sizeof(&get_real));
  self->getRe = &get_real;
  self->setRe = &set_real;
  self->add = &real_add;
  self->prod = &real_prod;
  self->setRe(self, 0.0);
  return self;
}

// Methods
double get_real(Real * self)
{
  return self->re;
}

void set_real(Real * self, double re)
{
  self->re = re;
}

Real * real_add(Real * self, Real * r1)
{
  Real * z = Real_new();
  z->setRe(z, self->getRe(self) + r1->getRe(r1));
  return z;
}

Real * real_prod(Real * self, Real * r1)
{
  Real * z = Real_new();
  z->setRe(z, self->getRe(self)*r1->getRe(r1));
  return z;
}

// Destructor
void Real_destruct(Real * self)
{
  free(self);
}
