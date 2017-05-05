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
Complex * Complex_new(double re, double im)
{
  Complex * self;
  self = malloc(4*sizeof(double) + 45*sizeof(void *));
  // Parent constructor
  self->super = Field_new(self->super);
  // Methods
  self->getRe = &complex_get_real_part;
  self->setRe = &complex_set_real_part;
  self->getIm = &complex_get_imaginary_part;
  self->setIm = &complex_set_imaginary_part;
  self->getElements = &complex_get_elements;
  // self->toString = &complex_to_string;
  // Functions
  self->abs = &complex_abs;
  self->add = &complex_add;
  self->prod = &complex_prod;
  self->sub = &complex_sub;
  self->div = &complex_div;
  self->exp = &complex_exp;
  /*
  self->ln = &complex_ln;
  self->logE = &complex_logE;
  self->logB = &complex_logB;
  self->log = &complex_log;
  self->pow = &complex_pow;
  self->root = &complex_root;
  self->sqrt = &complex_sqrt;
  */
  self->inverse = &complex_inverse;
  self->conj = &complex_conj;
  // self->rotate = &complex_rotate;
  self->sin = &complex_sin;
  self->cos = &complex_cos;
  self->tan = &complex_tan;
  self->sec = &complex_sec;
  self->csc = &complex_csc;
  self->cot = &complex_cot;
  // self->atan = &complex_atan;
  // self->atan2 = &complex_atan2;
  self->sinh = &complex_sinh;
  self->cosh = &complex_cosh;
  self->tanh = &complex_tanh;
  self->sech = &complex_sech;
  self->csch = &complex_csch;
  self->coth = &complex_coth;
  // self->atanh = &complex_atanh;
  self->setRe(self, re);
  self->setIm(self, im);

  return self;
}


// Methods
Real * complex_get_real_part(Complex * self)
{
  return self->real_part;
}

void complex_set_real_part(Complex * self, double real_part)
{
  self->real_part = Real_new(real_part);
}

Real * complex_get_imaginary_part(Complex * self)
{
  return self->imaginary_part;
}

void complex_set_imaginary_part(Complex * self, double imaginary_part)
{
  self->imaginary_part = Real_new(imaginary_part);
}

Real ** complex_get_elements(Complex * self)
{
  Real ** elements = malloc(sizeof(* elements));
  elements[0] = self->getRe(self);
  elements[1] = self->getIm(self);
  return elements;
}

// Destructor
void Complex_destruct(Complex * self)
{
  free(self);
}
