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

#define CMLFUNC_H
#include "../../includes/cml.h"

double isgreater(double x, double y)
{
  return x > y;
}

double isless(double x, double y)
{
  return x < y;
}

double isinteger(double x)
{
  int x_int = (int) x;
  return ((x - x_int) == 0);
}

double isnat(double x)
{
  return (isinteger(x) && x > 0);
}

double ismult(double x, double y)
{
  double z = x/y;
  int z_int = (int) z;
  return ((z - z_int) == 0);
}
