#include "allvars.h"
#include "initCondFunc.h"

void createParticles(Particles *part, int counter,
                     double x, double y, double vX, double vY,
                     double dx, double dy, double mass, double h,
                     double density, int p_type){

    part[counter].id = counter;
    part[counter].pos[X] = x;
    part[counter].pos[Y] = y;

    part[counter].vel[X] = vX;
    part[counter].vel[Y] = vY;

    part[counter].accel[X] = 0.0;
    part[counter].accel[Y] = 0.0;

    part[counter].rho = density;
    part[counter].mass = mass;
    part[counter].h = h;
    part[counter].p = 0.0;
    part[counter].c = 0.0;
    part[counter].du = 0.0;
    part[counter].u = 357.1;
    part[counter].nn = NULL;
    part[counter].nNeighbors = 0;

    part[counter].dx = NULL;
    part[counter].dy = NULL;
    part[counter].r = NULL;
    part[counter].W = NULL;
    part[counter].dWx = NULL;
    part[counter].dWy = NULL;

    part[counter].type = p_type;
  
}

void realloc_particles_test(int *nPart, int npV) {
    Particles *auxPart = NULL;
    auxPart = (Particles *)realloc(part, (size_t)(*nPart + npV + 1) * sizeof(Particles));

    if (auxPart == NULL) {
        printf("Error en auxPart\n");
        exit(0);
    } else {
        part = auxPart;
        auxPart = NULL;
    }
}

void write_particles(FILE *file, int start_index, int num_particles, char *boundary_type) {
    int end_index;
    fprintf(stdout, "adfasdf %d\n", num_particles);
    if (strcmp(boundary_type, "bottom") == 0 || strcmp(boundary_type, "top") == 0) {
        end_index = start_index + num_particles + 1;  // npV+1
    } else if (strcmp(boundary_type, "right") == 0 || strcmp(boundary_type, "left") == 0) {
        end_index = start_index + num_particles - 1;  // npV-1
    } else if (strcmp(boundary_type, "all") == 0) {
        end_index = num_particles;  // Para "all", nPart
    } else {
        printf("Error: Tipo de frontera no válido\n");
        return;
    }

    for (int i = start_index; i < end_index; i++) {
        fprintf(file, "%d %.10lf %.10lf %.10lf %.10lf %.10lf %.10lf %.10lf %.10lf %.10lf %.10lf %.10lf\n",
            part[i].id,
            part[i].pos[X], part[i].pos[Y],
            part[i].vel[X], part[i].vel[Y],
            part[i].accel[X], part[i].accel[Y],
            part[i].rho, part[i].mass,
            part[i].p, part[i].c, part[i].u);
    }

}