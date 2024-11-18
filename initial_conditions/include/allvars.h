#ifndef ALLVARS_H
#define ALLVARS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <malloc.h>

#define X 0
#define Y 1
#define epsilon_X 1E-8

#define _USE_MATH_DEFINES

typedef struct
{
    int id;
    double pos[2];
    double vel[2];
    double accel[2];
    double mass;
    double rho;
    double h;
    double p;
    double c;
    double du;
    double u;
    int *nn;
    int nNeighbors;
    double *dx;
    double *dy;
    double *dz;
    double *r;
    double *W;
    double *dWx;
    double *dWy;
    double *dWz;
    int type;
} Particles;

extern Particles *part, *auxPart;
extern int nFluid, nPart;

#endif // ALLVARS_Hs