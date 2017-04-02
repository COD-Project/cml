#ifndef CUSF_H
#define CUSF_H


// ---> Usefull Functions <---
Real * complex_sgn(Complex *);
Real * complex_abs(Complex *);


// ---> Basic Functions <---
Complex * complex_add(Complex *, Complex *);
Complex * complex_prod(Complex *, Complex *);
Complex * complex_sub(Complex *, Complex *);
Complex * complex_div(Complex *, Complex *);

#endif

#ifndef CBAF_H
#define CBAF_H

// ---> Euler definitions <---
Complex * complex_exp(Complex *);

// ---> Usefull functions
// Complex * __complex_ln(Complex *);
Complex * complex_ln(Complex *);
Complex * complex_logE(Complex *);
Complex * complex_logB(Complex *, Real *);
Complex * complex_log(Complex *);
Complex * complex_pow(Complex *, Real *);
Complex * complex_root(Complex *, Real *);
Complex * complex_sqrt(Complex *);
Complex * complex_conj(Complex *);
Complex * complex_inverse(Complex *);
void complex_rotate(Complex *, Real *);

#endif
