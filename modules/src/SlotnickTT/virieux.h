#ifndef __VIRIEUX_H__
#define __VIRIEUX_H__

int e3solver(double a0, double a1, double a2, double a3,
             double *x1r, double *x1i,
             double *x2r, double *x2i,
             double *x3r, double *x3i);

int e2solver(double a0, double a1, double a2,
             double *x1r, double *x1i, double *x2r, double *x2i);

double virieux(double x, double z, double k0, double k);

#endif /* __VIRIEUX_H__ */

