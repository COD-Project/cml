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


// Constructor
Kernel * Kernel_new()
{
  Kernel * self;
  self = malloc(4*sizeof(&cml_core_add));
  self->add = &cml_core_add;
  self->destruct = &cml_core_destruct;
  return self;
}


// Methods
void cml_core_add(void ** array)
{

}

void cml_core_destruct(void ** array)
{

}
