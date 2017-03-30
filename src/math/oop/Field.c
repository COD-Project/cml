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


#include "../../../includes/cml.h"


// Constructor
Field * Field_new()
{
  // Parent constructor
  self->super = Field_new(self->super);
  self = malloc(4*sizeof(double) + 3*sizeof(&field_add));
  self->add = &field_add;
  self->prod = &field_prod;
  return self;
}

// Composition laws
void field_add(Field * self, Field * r1)
{
  printf("%s\n", 'This function must be re-implemented in each of the children of the hierarchy');
}

void field_prod(Field * self, Field * r1)
{
  printf("%s\n", 'This function must be re-implemented in each of the children of the hierarchy');
}

// Destructor
void Field_destruct(Field * self)
{
  free(self);
}
