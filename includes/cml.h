#ifndef CML_H
#define CML_H


/* Core */
#include "core/core.h"

extern const Kernel * cml;

/* ------------------- */
#include "math/cml_types.h"
#include "math/cml_consts.h"
#include "math/cml_functions.h"
// Real functions
#include "math/cml_real_functions.h"
#include "math/cml_real_geometry.h"
#include "math/cml_real_trigonometry.h"
// Complex functions
#include "math/cml_complex_functions.h"
#include "math/cml_complex_trigonometry.h"
// Calculus
#include "math/cml_calculus.h"

void cml__init__();

#endif
