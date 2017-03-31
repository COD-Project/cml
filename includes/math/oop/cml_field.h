#ifndef FIELD_H
#define FIELD_H


typedef struct field
{
  // Composition laws
  void (*add)(struct field *, struct field *);
  void (*prod)(struct field *, struct field *);
} Field;

// Composition laws
void field_add();
void field_prod();

// Constructor && destructor
Field * Field_new();
void Field_destruct(Field *);

#endif
