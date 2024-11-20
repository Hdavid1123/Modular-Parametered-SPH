#ifndef INITCONFUNC_H
#define INITCONFUNC_H

void createParticles(Particles *part, int counter,
                     double x, double y, double vX, double vY,
                     double dx, double dy, double mass, double h,
                     double density, int p_type);

void realloc_particles_test(int *nPart, int npV);

void write_particles(FILE *file, int start_index, int num_particles, char *boundary_type);


#endif

