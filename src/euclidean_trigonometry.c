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

#define __CML_ET_
#include "includes/cml.h"


/**
  * Basic trigonometric functions
  */

// reducir angulo a 2PI

/**
  * sin(x) function developed by using Taylor Series
  *
  * @param double x
  *
  * @return double sin(x)
  */
double m_sin(double x)
{
  int i;
  double s = m_sgn(x);
         x = m_ared(m_fabs(x));
  double ai_n = x,
         p = ai_n;
  for (i = 1; i <= TOPL; ++i) {
    ai_n = -ai_n*x*x/(2*i*(2*i+1));
    p = p + ai_n;
  }
  return (ismult(x, PI)) ? !ismult(x, PI) : p*s;
}

/**
  * cos(x) function developed by using Taylor Series
  *
  * @param double x
  *
  * @return double cos(x)
  */
double m_cos(double x)
{
  x = m_fabs(x);
  return m_sin(x + HALFPI);
}

/**
  * tan(x) function developed by using trigonometric identities
  *
  * @param double x
  *
  * @return double tan(x)
  */
double m_tan(double x)
{
  return (m_cos(x) == 0) ? NAN : m_sin(x)/m_cos(x);
}

/**
  * sec(x) function developed by using trigonometric identities
  *
  * @param double x
  *
  * @return double sec(x)
  */
double m_sec(double x)
{
  return (m_cos(x) == 0) ? NAN : 1/m_cos(x);
}

/**
  * csc(x) function developed by using trigonometric identities
  *
  * @param double x
  *
  * @return double csc(x)
  */
double m_csc(double x)
{
  return (m_sin(x) == 0) ? NAN : 1/m_sin(x);
}

/**
  * cot(x) function developed by using trigonometric identities
  *
  * @param double x
  *
  * @return double cot(x)
  */
double m_cot(double x)
{
  return (m_sin(x) == 0) ? NAN : m_cos(x)/m_sin(x);
}

/**
  * arctan(x) function developed by using Taylor Series
  *
  * @param double x
  *
  * @return double arctan(x)
  */
double m_atan(double x)
{
  int i;
  double ai_n = x, p = ai_n;
  for (i = 1; i <= TOPL; i += 2) {
    ai_n = -ai_n*x*x;
    p = p + ai_n/(i+2);
  }
  return p;
}
