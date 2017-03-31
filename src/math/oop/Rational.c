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
Rational * Rational_new()
{
  Rational * self;
  self = malloc(4*sizeof(double) + 8*sizeof(&get_rational));
  // Parent constructor
  self->super = Field_new(self->super);
  self->getNum = &get_rational_num;
  self->getDen = &get_rational_den;
  self->getReal = &get_rational;
  self->add = &rational_add;
  self->prod = &rational_prod;
  self->setNum(self, 0);
  self->setDen(self, 1);
  return self;
}

// Methods
int get_rational_num(Rational * self)
{
  return self->num;
}

void set_rational_num(Rational * self, int num)
{
  self->num = num;
}

int get_rational_den(Rational * self)
{
  return self->den;
}

void set_rational_den(Rational * self, int den)
{
  if (den != 0) self->den = den;
}

Real * get_rational(Rational * self)
{
  Real * r = Real_new();
  r->setRe(r, (self->getNum(self)/self->getDen(self)));
  return r;
}

Rational * rational_add(Rational * self, Rational * r1)
{
  Rational * z = Rational_new();
  int num = self->getNum(self)*r1->getDen(r1) + r1->getNum(r1)*self->getDen(self),
      den = self->getDen(self)*r1->getDen(r1);
  z->setNum(z, num);
  z->setDen(z, den);
  return z;
}

Rational * rational_prod(Rational * self, Rational * r1)
{
  Rational * z = Rational_new();
  z->setNum(z, self->getNum(self)*r1->getNum(r1));
  z->setDen(z, self->getDen(self)*r1->getDen(r1));
  return z;
}

// Destructor
void Rational_destruct(Rational * self)
{
  free(self);
}
