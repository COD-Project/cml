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
Real * Real_new(double re)
{
  Real * self;
  self = malloc(4*sizeof(double) + 50*sizeof(&get_real));
  // Parent constructor
  self->super = Field_new(self->super);
  self->get = &get_real;
  self->set = &set_real;
  // Functions
  self->sgn = &real_sgn;
  self->abs = &real_abs;
  self->add = &real_add;
  self->prod = &real_prod;
  self->sub = &real_sub;
  self->div = &real_div;
  self->divE = &real_div_e;
  self->mod = &real_mod;
  self->ared = &real_ared;
  self->fact = &real_fact;
  self->ceil = &real_ceil;
  self->floor = &real_floor;
  self->exp = &real_exp;
  self->ln = &real_ln;
  self->logE = &real_logE;
  self->logB = &real_logB;
  self->log = &real_log;
  self->pow = &real_pow;
  self->root = &real_root;
  self->sqrt = &real_sqrt;
  self->pit = &real_pit;
  self->sin = &real_sin;
  self->cos = &real_cos;
  self->tan = &real_tan;
  self->sec = &real_sec;
  self->csc = &real_csc;
  self->cot = &real_cot;
  /*
  self->atan = &real_atan;
  self->atan2 = &real_atan2;
  */
  self->sinh = &real_sinh;
  self->cosh = &real_cosh;
  self->tanh = &real_tanh;
  self->sech = &real_sech;
  self->csch = &real_csch;
  self->coth = &real_coth;
  self->atanh = &real_atanh;
  self->destruct = & Real_destruct;
  self->set(self, re);
  return self;
}

// Methods
double get_real(Real * self)
{
  return self->real_part;
}

void set_real(Real * self, double re)
{
  self->real_part = re;
}

// Destructor
void Real_destruct(Real * self)
{
  free(self);
}
