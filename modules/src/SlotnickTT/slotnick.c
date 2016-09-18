#include <math.h>

static double arcosh(double x)
{
    double arg;

    arg = x + sqrt(x*x - 1.0);

    return log(arg);
}


/** 
    traveltime in v(z) = v0 + kz from (0,0) to (x,z):
    t = 1/k * arcosh(1 + k^2*(x^2+z^2)/2/v0/(v0+kz)) [Slotnick, 1936] 
*/
double slotnick(double x, double z, double v0, double k)
{

    double arg, t;

    if (k > 0) {
        arg = 1.0 + k*k * (x*x+z*z) / 2.0 / v0 / (v0 + k*z);
        t   = arcosh(arg) / k;
    }
    else t = sqrt(x*x+z*z) / v0;

    return t;
}
