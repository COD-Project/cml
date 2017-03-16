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

#define __CML_BF_
#include "includes/cml.h"


/**
  * Functions developed by using math definitions
  */

/**
  * ln(x) function developed by using hyperbolic definition of Taylor Series
  * where ln(x) = arctanh((x^2 - 1)/(x^2 - 1)) (this is not the best way to do this!)
  *
  * @param double x
  *
  * @return double log(x)
  */
double m_ln(double x)
{
  return (x > 0) ? m_atanh((x*x - 1)/(x*x + 1)) : NAN;
}



/**
  * ln(x) function developed by using Riemman Sum Function
  *
  * @param double x
  *
  * @return double ln(x)

double m_ln(double t)
{
  if (t <= 0) {
    return NAN;
  }
  int partitions = TOPL;
  double sum = 0.0,
         x = 0.0,
         ls = t,
         li = 1.0,
         mediumPoint,
         deltaX,
         deltaT;

  deltaT = ls - li;
  deltaX = deltaT/partitions;
  x = li;

  while (x < ls) {
    mediumPoint = (x + (x + deltaX))/2.0;
    sum = sum + deltaX/mediumPoint;
    x = x + deltaX;
  }

  return sum;
}
*/

double m_logE(double x)
{
  return m_ln(x);		/* Natural log */
}

/**
  * The logarithm logb(x) can be computed from the logarithms of x and b with respect to an arbitrary base k using the following formula:
  * log_b{x} = log_k{x} / log_k(b)
  *
  * @param double x
  *
  * @return double log_b(x)
  */

double m_logB(double x, double y)
{
  return (m_ln(y) == 0) ? NAN : m_ln(x)/m_ln(y);
}

double m_log(double x)
{
  return m_logB(x, 10.0);
}

/**
  * Development of the Taylor series of the function e^x
  *
  * @param double x: Exponent of the function
  *
  * @return double e^x
  */
double m_exp(double x)
{
  int i;
  double ai = 1.0,
         ex = ai;
  for (i = 1; i <= TOPL; i++) {
    ai = ai*x/i;
    ex = ex + ai;
  }
  return ex;
}

/**
  * pow(f, g) function developed by using the exponentiation process
  * where pow(f, g) = sgn(f)e^(glog(|f|))
  *
  * @param double x
  *
  * @return double pow(f, g)
  */
double m_pow(double f, double g)
{
  return (f == 0) ? ((g == 0) ? NAN : 0) : m_exp(g*m_ln(m_fabs(f)))*m_sgn(f);
}

/**
  * root(f, g) function developed by using the exponentiation process
  *
  * @param double x
  *
  * @return double root(f, g)
  */
double m_root(double f, int g)
{
  return (isnat(g) == 1) ? m_pow(f, m_pow(g, -1)) : NAN;
}

/**
  * square root(f, g) function developed by using the exponentiation process
  *
  * @param double x
  *
  * @return double sqrt(f, g)
  */
double m_sqrt(double f)
{
  return (f >= 0) ? m_root(f, 2) : NAN;
}
