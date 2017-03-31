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

#define NEUT_H
#include "../../includes/cml.h"

/**
  * Hyperbolic Functions using Euler relationships and Taylor Series
  */

/**
  * Hyperbolic sine "m_sinh(x)" function developed by using Euler relationships
  *
  * @param double x
  *
  * @return double m_sinh(x)
  */
double m_sinh(double x)
{
  int s = m_sgn(x);
  x = m_fabs(x);
  return s*(m_exp(x) - m_exp(-x))/2;
}

/**
  * Hyperbolic cosine "m_cosh(x)" function developed by using Euler relationships
  *
  * @param double x
  *
  * @return double m_cosh(x)
  */
double m_cosh(double x)
{
  x = m_fabs(x);
  return (m_exp(x) + m_exp(-x))/2;
}

/**
  * Hyperbolic tangent "tanh(x)" function developed by using Euler relationships
  *
  * @param double x
  *
  * @return double tanh(x)
  */
double m_tanh(double x)
{
  return (m_cosh(x) == 0) ? NAN : m_sinh(x)/m_cosh(x);
}

/**
  * sech(x) function developed by using Euler relationships
  *
  * @param double x
  *
  * @return double sech(x)
  */
double m_sech(double x)
{
  return (m_cosh(x) == 0) ? NAN : 1/m_cosh(x);
}

/**
  * csch(x) function developed by using Euler relationships
  *
  * @param double x
  *
  * @return double csch(x)
  */
double m_csch(double x)
{
  return (m_sinh(x) == 0) ? NAN : 1/m_sinh(x);
}

/**
  * coth(x) function developed by using Euler relationships
  *
  * @param double x
  *
  * @return double coth(x)
  */
double m_coth(double x)
{
  return (m_sinh(x) == 0) ? NAN : m_cosh(x)/m_sinh(x);
}

/**
  * arctanh(x) function developed by using Taylor Series
  *
  * @param double x
  *
  * @return double arctanh(x)
  */
double m_atanh(double x)
{
  int i;
  if (m_fabs(x) >= 1) {
    return NAN;
  }
  double ai_n = x, p = ai_n;
  for (i = 1; i <= TOPL; i += 2) {
    ai_n = ai_n*x*x;
    p = p + ai_n/(i+2);
  }
  return p;
}
