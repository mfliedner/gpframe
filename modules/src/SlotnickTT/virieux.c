#include <math.h>
#include "virieux.h"

int e3solver(double a0, double a1, double a2, double a3,
             double *x1r, double *x1i,
             double *x2r, double *x2i,
             double *x3r, double *x3i)
{
    return 1;
}

int e2solver(double a0, double a1, double a2,
             double *x1r, double *x1i, double *x2r, double *x2i)
{
    double D, R, eps = 1.0e-20;

    if ( fabs(a2) > eps ) {
        D = a1*a1 - 4.0*a2*a0;
        if ( fabs(D) > eps ) R = sqrt(fabs(D));
        else                 R = 0.0;
        if ( D < 0.0 ) {
            *x1r = -0.5 * a1 / a2;
            *x1i =  0.5 * R  / a2;
            *x2r = -0.5 * a1 / a2;
            *x2i = -0.5 * R  / a2;
        }
        else {
            *x1r =  0.5 * (R - a1) / a2;
            *x1i =  0.0;
            *x2r = -0.5 * (R + a1) / a2;
            *x2i =  0.0;
        }
    }
    else if ( fabs(a1) > eps ) {
        *x1r = -a0 / a1;
        *x1i = 0.0;
        *x2r = *x1r;
        *x2i = 0.0;
    }
    else {
        *x1r = 0.0;
        *x1i = 0.0;
        *x2r = 0.0;
        *x2i = 0.0;
    }

    return 0;
}

double virieux(double x, double z, double k0, double k)
{
    double a0, a1, a2, r, s, t, t2, s2, s3, q = 0.0, p;
    double x1r, x1i, x2r, x2i, eps = 1.0e-20;
    int    ierr, iroot = 0;

    r  = x * x;
    a2 = z*z + r;
    a1 = -r * (0.5*k*z + k0);
    a0 = 0.0625*k*k * r*r;

    ierr = e2solver(a0, a1, a2, &x1r, &x1i, &x2r, &x2i);
    if ( (fabs(x1i) < eps) && x1r > 0.0 ) {
        q = x1r;
        ++iroot;
    }
    if ( (fabs(x2i) < eps) && x2r > 0.0 ) ++iroot;

    if (!iroot) return -1.0;

    p  = k0 - q;
    s  = x / sqrt(q);
    s2 = s * s;
    s3 = s * s2;
    t  = k0 * s + 0.5*k*p * s2 + k*k/12.0 * s3;

    if (iroot > 1) {
        q = x2r;
        s  = x / sqrt(q);
        s2 = s * s;
        s3 = s * s2;
        t2 = k0 * s + 0.5*k*p * s2 + k*k/12.0 * s3;
        if (t2 < t && t2 > 0.0) t = t2;
    }

    return t;
}
