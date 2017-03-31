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
  double n = 0; // For testing you should use a number between -HALFPI and HALFPI
  printf("%s%g\n\n", "The following tests are performed with x = ", n);

  // Basic trigonometric identities
  printf("%s\n", "The following trigonometric identities are verified:");
  printf("%s%g\n","   |--> cos^2(x)+sin^2(x) = ", m_pow(m_cos(n), 2.0) + m_pow(m_sin(n), 2.0));
  printf("%s%g%s%g\n","   |--> sin(x) = ", m_sin(n), " <==> sin(x + 2pi) = ", m_sin(n + TWOPI));
  printf("%s%g%s%g\n","   |--> cos(x) = ", m_cos(n), " <==> cos(x + 2pi) = ", m_cos(n + TWOPI));
  printf("%s%g%s%g\n","   |--> tan(x) = ", m_tan(n), " <==> tan(x + pi) = ", m_tan(n + PI));
  printf("%s%g%s%g\n","   |--> sin(-x) = ", m_sin(-n), " <==> sin(x + pi) = ", m_sin(n + PI));
  printf("%s%g%s%g\n","   |--> cos(-x) = ", m_cos(-n), " <==> -cos(x + pi) = ", -m_cos(n + PI));
  printf("%s%g%s%g\n","   |--> tan(-x) = ", m_tan(-n), " <==> -tan(x) = ", -m_tan(n));
  printf("%s%g%s%g\n","   |--> cot(-x) = ", m_cot(-n), " <==> -cot(x) = ", -m_cot(n));
  printf("%s%g%s%g\n","   |--> sin(x) = ", m_sin(n), " <==> cos(PI/2 - x) = ", m_cos(HALFPI - n));
  printf("%s%g%s%g\n","   |--> cos(x) = ", m_cos(n), " <==> sin(PI/2 - x) = ", m_sin(HALFPI - n));
  printf("%s%g%s%g\n","   |--> tan(x) = ", m_tan(n), " <==> cot(PI/2 - x) = ", m_cot(HALFPI - n));

  // Hyperbolic trigonometric identities
  printf("\n");
  printf("%s\n", "The following hyperbolic trigonometric identities are verified:");
  printf("%s%g\n","   |--> cosh^2(x)-sinh^2(x) = ", m_pow(m_cosh(n), 2.0) - m_pow(m_sinh(n), 2.0));

  printf("%g\n", m_atan(PI));
}

int main(int argc, char const *argv[]) {
  test();
  return 0;
}
