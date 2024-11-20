#include "allvars.h"
#include "initCondFunc.h"

void organizeIcsFluid(double x_i, double y_i, int nx, int ny,
                      double dx, double dy,
                      double mass, double h, double density);
//void organizeIcsBorders();
double parse_double_default(char *str, double def);

int main(int argc, char *argv[]){
    // Para el fluido
    double xf_init, yf_init, Lx_fluid, Ly_fluid, nx_fluid, ny_fluid;
    
    xf_init = parse_double_default(argv[1], 0.0);
    yf_init = parse_double_default(argv[2], 0.0);
    Lx_fluid = parse_double_default(argv[3], 1e-3);
    Ly_fluid = parse_double_default(argv[4], 1e-3);
    nx_fluid = atoi(argv[5]);
    ny_fluid = atoi(argv[6]);
    
    double dx_fluid, dy_fluid, mean_dxdy;

    dx_fluid = Lx_fluid/nx_fluid;
    dy_fluid = Ly_fluid/ny_fluid;
    mean_dxdy = 0.5*(dx_fluid + dy_fluid);

    double h, density, mass_i;
    density = parse_double_default(argv[7], 1000.0);
    h = parse_double_default(argv[8], mean_dxdy);
    mass_i = density*dx_fluid*dy_fluid;

    // Para los bordes
    double Lx_border, Ly_border;
    Lx_border = parse_double_default(argv[9], 1e-3);
    Ly_border = parse_double_default(argv[10], 1e-3);

    nFluid = nx_fluid*ny_fluid;

    printf("Número de partículas de fluido %d con largo %f y un alto %f",
            nFluid, Lx_fluid, Ly_fluid);
    
    part = (Particles *)malloc((size_t)(nFluid)*sizeof(Particles));

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

    int i, j, counter;

    FILE *fFluidIcs;

    fFluidIcs = fopen("../data/borders_ics/fluid_ics.output","w");
    counter = 0;

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
}

double parse_double_default(char *str, double def){
    char *endptr;
    double val = strtod(str, &endptr);
    return endptr == str ? def : val;
}

/* void organizeIcsBorders(){
    
} */