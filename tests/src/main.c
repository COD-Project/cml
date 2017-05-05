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

void test()
{
  real x = Real_new(1.0);
  real y = x->sinh(x);
  complex z = Complex_new(1.0, 2.0);
  complex zsin = z->sin(z);
  real * x1 = zsin->getElements(zsin);
  printf("%g\n", y->get(y));
  printf("%g%s%g%c\n", x1[0]->get(x1[0]), " + ", x1[1]->get(x1[1]), 'i');
}

int main(int argc, char const *argv[]) {
  /* main cml function */
  __cml_init__();
  test();
  return 0;
}
