#ifndef FIELD_H
#define FIELD_H


typedef struct field
{
  // Parent
  Field * super;
  // Composition laws
  struct field * (*add)(struct field *, struct field *);
  struct field * (*prod)(struct field *, struct field *);
} Field;

// Composition laws
Field * field_add(Field *, Field *);
Field * field_prod(Field *, Field *);

// Constructor && destructor
Field * Field_new();
void Field_destruct(Field *);

#endif
