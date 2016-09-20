#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <seplib.h>

#include "slotnick.h"
#include "virieux.h"

int verb;

int main(int argc, char *argv[])
{
    float  xs, ys, ox, oy, oz, dx, dy, dz, osx, osy, dsx, dsy;
    float  kx, ky, kz, fv0, k0, *ft;
    double v0, k, t, v, vs, x, y, z, r2, z2, rr, zz;
    int	   ix, iy, iz, isx, isy, nx, ny, nz, nsx, nsy, esize, isu, ivx;
    char   data_format[20];

    initpar(argc, argv);

    fetch("verb", "d", &verb);

    if (!fetch("esize", "d", &esize)) esize = sizeof(float);
    if (!fetch("data_format", "s", data_format))
        strcpy(data_format,"xdr_float");

    /* definition of traveltime table for one shot */
    if (!fetch ("n_z_tt",     "d", &nz)) nz = 1;
    if (!fetch ("n_iline_tt", "d", &nx)) nx = 1;
    if (!fetch ("n_xline_tt", "d", &ny)) ny = 1;
    if (!fetch ("d_z_tt",     "f", &dz)) dz = 1.0;
    if (!fetch ("d_iline_tt", "f", &dx)) dx = 1.0;
    if (!fetch ("d_xline_tt", "f", &dy)) dy = 1.0;
    if (!fetch ("o_z_tt",     "f", &oz)) oz = 0.0;
    if (!fetch ("o_iline_tt", "f", &ox)) ox = -(nx/2) * dx;
    if (!fetch ("o_xline_tt", "f", &oy)) oy = -(ny/2) * dy;

    /* definition of shot grid */
    if (!fetch ("ns_iline_tt", "d", &nsx)) nsx = 1;
    if (!fetch ("ns_xline_tt", "d", &nsy)) nsy = 1;
    if (!fetch ("ds_iline_tt", "f", &dsx)) dsx = 1.0;
    if (!fetch ("ds_xline_tt", "f", &dsy)) dsy = 1.0;
    if (!fetch ("os_iline_tt", "f", &osx)) osx = 0.0;
    if (!fetch ("os_xline_tt", "f", &osy)) osy = 0.0;

    if (!getch ("su",      "d", &isu)) isu = 0;
    if (!getch ("virieux", "d", &ivx)) ivx = 0;

    putch ("esize", "d", &esize);
    putch ("n1",    "d", &nz);
    putch ("n2",    "d", &nx);
    putch ("n3",    "d", &ny);
    putch ("n4",    "d", &nsx);
    putch ("n5",    "d", &nsy);
    putch ("d1",    "f", &dz);
    putch ("d2",    "f", &dx);
    putch ("d3",    "f", &dy);
    putch ("d4",    "f", &dsx);
    putch ("d5",    "f", &dsy);
    putch ("o1",    "f", &oz);
    putch ("o2",    "f", &ox);
    putch ("o3",    "f", &oy);
    putch ("o4",    "f", &osx);
    putch ("o5",    "f", &osy);
    putch ("su",    "d", &isu);

    /* definition of velocity function */
    if (!fetch ("v0", "f", &fv0)) fv0 = 1.0;
    if (!fetch ("kx", "f", &kx))   kx = 0.0;
    if (!fetch ("ky", "f", &ky))   ky = 0.0;
    if (!fetch ("kz", "f", &kz))   kz = 0.0;

    /* determine velocity gradient */
    k = sqrt(kx*kx + ky*ky + kz*kz);
    if (ivx) k = -k;
    if (verb > 0) {
        if (ivx) fprintf(stderr, "slowness^2 gradient = %g\n", k);
        else     fprintf(stderr, "velocity gradient = %g\n",   k);
    }

    putch ("v0", "f", &fv0);
    putch ("kx", "f", &kx);
    putch ("ky", "f", &ky);
    putch ("kz", "f", &kz);

    hclose (); /* close history file before writing output data */

    ft = (float *)malloc(nz * esize);
    v0 = (double)fv0;
    if (ivx) {
        if (v0 < 1.0) {
            fprintf(stderr, "v0 must be > 1.0\n");
            exit(1);
        }
        k0 = 1.0 / (v0 * v0);
        if (verb > 0) fprintf(stderr, "S0^2 = %g\n", k0);
    }

    /* fill travel time tables */
    for (isy = 0; isy < nsy; isy++) {
        ys = osy + isy * dsy;
        for (isx = 0; isx < nsx; isx++) {
            xs = osx + isx * dsx;
            if (verb > 0) fprintf(stderr, "xs = %g, ys = %g\n", xs, ys);
            for (iy = 0; iy < ny; iy++) {
                y = (double)(oy + iy * dy);
                if (isu) y -= ys;
                for (ix = 0; ix < nx; ix++) {
                    x = (double)(ox + ix * dx);
                    if (isu) x -= xs;
                    vs = v0 + kx * xs + ky * ys;
                    for (iz = 0; iz < nz; iz++) {
                        z = (double)(oz + iz * dz);
                        r2 = x*x + y*y + z*z;
                        v = kx*x + ky*y + kz*z;
                        if (k > 0.0) zz = v / k;
                        else         zz = 0.0;
                        z2 = zz * zz;
                        if (r2 > z2) rr = sqrt(r2  - zz*zz);
                        else         rr = 0.0;
                        if (ivx) {
                            t = virieux(rr, zz, k0, k);
                        }
                        else {
                            if (vs > 0.0) {
                                if (k > 0.0) t = slotnick(rr, zz, vs, k);
                                else         t = rr / vs;
                            }
                            else t = -1.0;
                        }
                        ft[iz] = (float)t;
                    }
                    srite("out", ft, nz*esize);
                }
            }
        }
    }

    free(ft);

    return 0;
}
