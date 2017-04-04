#ifndef __CML_CORE_H
#define __CML_CORE_H

#include "config.h"

extern const void *objects[];

typedef struct _kernel {
  // Methods
  void (*add)(void **);
  void (*destruct)(void **);
} Kernel;

// Methods
void cml_core_add(void **);
char * cml_core_get_root(void);
void cml_core_include(char *);
void cml_core_destruct(void **);

// Constructor & destructor
Kernel * Kernel_new();
void Kernel_destruct(Kernel *);

#endif
