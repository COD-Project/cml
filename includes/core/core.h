#ifndef CORE_H
#define CORE_H
#include "config.h"

#define core Kernel *

typedef struct kernel {
  // Methods
  void (*malloc)(void *, int, int);
  char * (*getRoot)(void);
  void (*include)(char *);
} Kernel;

// Methods
void cml_core_malloc(void *, int, int);
char * cml_core_get_root(void);
void cml_core_include(char *);

// Constructor & destructor
Kernel * Kenerl_new();
void Kernel_destruct(Kernel *);

#endif
