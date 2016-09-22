/*<
seploc

USAGE
int seploc(x)

INPUT PARAMETERS
x - void location

RETURN VALUES
n= integer memory location

DESCRIPTION
If the system fortran library has a routine that gets an integer location
 * given an address then we use that. If not we use integer conversions.
 * This is very dangerous and gross! it assumes that ponters
 * are exactly the same as ints ( won't work on a CRAY) 

CATEGORY
Lib:Sep:Fortran

>*/
#include <sitedef.h>

#include <sep_main_external.h>

#ifdef SUN4 
#define SYS_LOC loc_
#endif

#ifdef CRAY 
#define SYS_LOC LOC
#endif

#ifdef CONVEX
#define SYS_LOC loc_
#endif


#if NeedFunctionPrototypes
_XFUNCPROTOBEGIN
int seploc(void *x)
_XFUNCPROTOEND
#else
int seploc(x)
char* x;
#endif
{
int a;

#ifdef SYS_LOC
a = SYS_LOC(x);
#else
a = (int) x;
#endif

return a;
}

