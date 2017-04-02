#ifndef RUSF_H
#define RUSF_H


// ---> Usefull Functions <---
Real * real_sgn(Real *);
Real * real_abs(Real *);

// ---> Basic Functions <---
Real * real_add(Real *, Real *);
Real * real_prod(Real *, Real *);
Real * real_sub(Real *, Real *);
Real * real_div(Real *, Real *);
Real * real_div_e(Real *, Real *);
Real * real_mod(Real *, Real *);
Real * real_ared(Real *);
Real * real_fact(Real *);
Real * real_ceil(Real *);
Real * real_floor(Real *);

#endif

#ifndef RBAF_H
#define RBAF_H

// ---> Euler definitions <---
Real * real_exp(Real *);

// ---> Usefull functions
// Real * __real_ln(Real *);
Real * real_ln(Real *);
Real * real_logE(Real *);
Real * real_logB(Real *, Real *);
Real * real_log(Real *);
Real * real_pow(Real *, Real *);
Real * real_root(Real *, Real *);
Real * real_sqrt(Real *);

#endif
