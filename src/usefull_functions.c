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

#define __CML_UF_
#include "includes/cml.h"


/**
  * Basic Functions
  */

double m_sgn(double x)
{
  return (x) < 0 ? -1 : 1;
}

double m_abs(double x)
{
  return (x) < 0 ? -(x) : (x);	/* Integer Absolute value */
}

double m_fabs(double x)
{
  return (x) < 0 ? -(x) : (x);  /* Floating absolute value */
}

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

double m_add(double x, double y)
{
  return x + y;
}

double m_sub(double x, double y)
{
  return m_add(x, -y);
}

double m_prod(double x, double y)
{
  return x * y;
}
double m_div(double x, double y)
{
  return (y == 0) ? NAN : x/y;
}

double m_dive(double x, double y)
{
  return (int) m_div(x, y);
}

double m_fmod(double x, double y)
{
  return x - y*m_dive(x, y);
}

double m_ared(double x)
{
  int z = (int) x/TWOPI;
  return x - z*TWOPI;
}

double m_fact(double x)
{
  return (isinteger(x) && x > -1) ? ((x == 0) ? 1 : x*m_fact(x - 1)) : NAN;
}

// Returns the smallest integer value greater than or equal to x.
double m_ceil(double x)
{
  int z = (int)x;
  return (x - z == 0.0) ? x : z + 1.0;
}

// Returns the largest integer value less than or equal to x.
double m_floor(double x)
{
  return (int)x;
}
