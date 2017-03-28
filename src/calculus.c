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

#define CALC_H
#include "includes/cml.h"


/** f is the function to be integrated into the Riemann sum function
  *
  * @param double x
  *
  * @return double f(x)
  */
double m_f(double x)
{
  return 1.0/x;
}

/** This function performs Riemann sums with regular partitions in the interval [li, ls] for the function f(x)
  *
  * @param double li
  * @param double ls
  *
  * @return double riemann_sum(li, ls)
  */
double m_rs(double li, double ls, double (*f)(double, ...), double z)
{
  int partitions = TOPL;
  double sum = 0.0,
         x = 0.0,
         mediumPoint,
         deltaX,
         deltaT;

  deltaT = ls - li;
  deltaX = deltaT/partitions;
  x = li;

  while (x < ls) {
    mediumPoint = (x + (x + deltaX))/2.0;
    sum = sum + (*f)(mediumPoint, z)*deltaX;
    x = x + deltaX;
  }

  return sum;
}


/** Gamma Function
  *
  * @param double x
  *
  * @return double gamma(x)
  */
double m_gf(double t, double z)
{
  return m_pow(t, z + 1)*m_pow(E, -t);
}

double m_gamma(double z)
{
  return z;
}
