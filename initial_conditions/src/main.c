#include "allvars.h"
#include "initCondFunc.h"

void organizeIcsFluid(double x_i, double y_i, int nx, int ny,
                      double dx, double dy,
                      double mass, double h, double density);
//void organizeIcsBorders();
double parse_double_default(char *str, double def);

int main(int argc, char *argv[]){
    // Para el fluido
    double xf_init, yf_init, Lx_fluid, Ly_fluid;    
    double dx_fluid, dy_fluid, mean_dxdy;
    double h, density, mass_i;
    double Lx_border, Ly_border;
    int nx_fluid, ny_fluid,nFluid;
    
    /* xf_init = parse_double_default(argv[1], 0.0);
    yf_init = parse_double_default(argv[2], 0.0);
    Lx_fluid = parse_double_default(argv[3], 1e-3);
    Ly_fluid = parse_double_default(argv[4], 1e-3);
    nx_fluid = atoi(argv[5]);
    ny_fluid = atoi(argv[6]); */

    xf_init = atof(argv[1]);
    yf_init = atof(argv[2]);
    Lx_fluid = atof(argv[3]);
    Ly_fluid = atof(argv[4]);
    nx_fluid = atoi(argv[5]);
    ny_fluid = atoi(argv[6]);
    density = atof(argv[7]);
    h = atof(argv[8]);
    Lx_border = atof(argv[9]);
    Ly_border = atof(argv[10]);
    
    dx_fluid = Lx_fluid/nx_fluid;
    dy_fluid = Ly_fluid/ny_fluid;
    mean_dxdy = 0.5*(dx_fluid + dy_fluid);
    mass_i = density*dx_fluid*dy_fluid;

    // Para los bordes
    
    
    nFluid = nx_fluid*ny_fluid;



   // printf("Número de partículas de fluido %d con largo %f y un alto %f",
   //         nFluid, Lx_fluid, Ly_fluid);
    
    part = (Particles *)malloc((size_t)(nFluid)*sizeof(Particles));

    fprintf(stdout,"%f %f %f %f %d %d %f %f %f %f %d\n",
            xf_init, yf_init, Lx_fluid, Ly_fluid, nx_fluid, ny_fluid,
            density, h, Lx_border, Ly_border, nFluid);
    
    if (part == NULL){
        printf("Error en el espacio para las part\n");
        exit(0);
    }
    
    organizeIcsFluid(xf_init, yf_init, nx_fluid, ny_fluid,
                     dx_fluid, dy_fluid, mass_i, h, density);

    free(part);
    return 0;
}

void organizeIcsFluid(double x_i, double y_i, int nx, int ny,
                      double dx, double dy,
                      double mass, double h, double density){

    int i, j, counter, nFluid;

    nFluid = nx*ny;

    FILE *fFluidIcs;
    fprintf(stdout, "nx: %d, ny: %d\n", nx, ny);
    fFluidIcs = fopen("data/borders_ics/fluid_ics.output","w");
    counter = 0;
    fprintf(stdout, "nFluid %d\n", nFluid);

    for (i = x_i; i < nx; i++){ // x axis
        for (j = y_i; j < ny; j++){ // y axis
            createParticles(part, counter,
                            i*dx, j*dy, //x, y
                            0.0, 0.0, //vX, vY
                            dx, dy,
                            mass, h, density,
                            0); //dx, dy, p_type = 0 para fluido
            counter++;
        }
    }
    //void write_particles(FILE *file, int start_index, int num_particles, char *boundary_type)
    write_particles(fFluidIcs, 0, nFluid, "all");
     exit(0);
}
   
double parse_double_default(char *str, double def){
    char *endptr;
    double val = strtod(str, &endptr);
    return endptr == str ? def : val;
}

/* void organizeIcsBorders(){
    
} */