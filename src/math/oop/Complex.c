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
Complex * Complex_new()
{
  Complex * self;
  self = malloc(4*sizeof(double) + 8*sizeof(&get_complex_argument));
  // Parent constructor
  self->super = Field_new(self->super);
  self->getRe = &get_complex_real;
  self->setRe = &set_complex_real;
  self->getIm = &get_complex_im;
  self->setIm = &set_complex_im;
  self->getArg = &get_complex_argument;
  self->getMod = &get_complex_module;
  self->add = &complex_add;
  self->prod = &complex_prod;
  self->setRe(self, 0.0);
  self->setIm(self, 0.0);
  return self;
}


// Methods
double get_complex_real(Complex * self)
{
  return self->re;
}

void set_complex_real(Complex * self, double re)
{
  self->re = re;
}

double get_complex_im(Complex * self)
{
  return self->im;
}

void set_complex_im(Complex * self, double im)
{
  self->im = im;
}

double get_complex_module(Complex * self)
{
  return m_pit(self->getRe(self), self->getIm(self));
}

double get_complex_argument(Complex * self)
{
  return m_atan2(self->getIm(self), self->getRe(self));
}


// Composition laws
Complex * complex_add(Complex * self, Complex * z1)
{
  Complex * z = Complex_new();
  z->setRe(z, self->getRe(self) + z1->getRe(z1));
  z->setIm(z, self->getIm(self) + z1->getIm(z1));
  return z;
}

Complex * complex_prod(Complex * self, Complex * z1)
{
  Complex * z = Complex_new();
  z->setMod(z, self->getMod(self)*z1->getMod(z1));
  z->setArg(z, self->getArg(self)*z1->getMod(z1));
  return z;
}


// Destructor
void Complex_destruct(Complex * self)
{
  free(self);
}
