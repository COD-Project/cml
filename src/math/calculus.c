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

#define RCALC_H
#include "../../includes/cml.h"


/** f is the function to be integrated into the Riemann sum function
  *
  * @param Real * x
  *
  * @return Real * f(x)
  */
/*Real * real_f(Real * x)
{
  // you should define your own integrable function
  return x;
}*/

/** This function performs Riemann sums with regular partitions in the interval [li, ls] for the function f(x)
  *
  * @param Real * li
  * @param Real * ls
  *
  * @return Real * riemann_sum(li, ls)
  */
/*Real * real_rs(Real * li, Real * ls, Real * (*f)(Real *, ...), Real * z)
{
  int partitions = TOPL;
  double sum = 0.0,
         x = 0.0,
         mediumPoint,
         deltaX,
         deltaT;

  deltaT = ls->get(ls) - li->get(li);
  deltaX = deltaT/partitions;
  x = li;

  while (x < ls) {
    mediumPoint = (x + (x + deltaX))/2.0;
    sum = sum + (*f)(mediumPoint, z)*deltaX;
    x = x + deltaX;
  }

  return sum;
}*/


/** Gamma Function
  *
  * @param Real * x
  *
  * @return Real * gamma(x)
  */
/*Real * real_gf(Real * t, Real * z)
{
  return real_pow(t, z + 1)*real_pow(E, -t);
}

Real * real_gamma(Real * z)
{
  return z;
}*/
