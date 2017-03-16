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

#ifndef __CML_UF_
#define __CML_UF_

// ---> Usefull Functions <---
double m_sgn(double, ...);
double m_abs(double, ...);
double m_fabs(double, ...);
double isgreater(double, ...);
double isless(double, ...);
double isinteger(double, ...);
double isnat(double, ...);
double ismult(double, ...);

// ---> Basic Functions <---
double m_add(double, ...);
double m_sub(double, ...);
double m_prod(double, ...);
double m_div(double, ...);
double m_dive(double, ...);
double m_fmod(double, ...);
double m_ared(double, ...);
double m_fact(double, ...);
double m_ceil(double, ...);
double m_floor(double, ...);

#endif

#ifndef __CML_BF_
#define __CML_BF_

// ---> Euler definitions <---
double m_exp(double, ...);

// ---> Usefull functions
// double __m_ln(double, ...);
double m_ln(double, ...);
double m_logE(double, ...);
double m_logB(double, ...);
double m_log10(double, ...);
double m_pow(double, ...);
double m_root(double, ...);
double m_sqrt(double, ...);

#endif
