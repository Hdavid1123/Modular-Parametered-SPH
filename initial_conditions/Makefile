# Variables de configuración del compilador y archivos
CC = gcc
CFLAGS = -Wall -g -Iinclude
LFLAGS = -lm
SRC = src/main.c src/allvars.c src/initCondFunc.c
OBJ = $(SRC:.c=.o)
EXEC = SPH_InitCond.output

# Parámetros de las condiciones iniciales
XF = 0.0
YF = 0.0
LXF = 1.0
LYF = 1.0
NX = 100
NY = 100
RHO = 1000.0
H = 0.0001
LXB = 1.2
LYB = 1.2

# Regla principal: compila el ejecutable
all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ)

# Regla para ejecutar el programa pasando los 10 parámetros
run: $(EXEC)
	
	./$(EXEC) $(XF) $(YF) $(LXF) $(LYF) $(NX) $(NY) $(RHO) $(H) $(LXB) $(LYB)

# Limpieza de los archivos generados
clean:
	rm -f $(OBJ) $(EXEC)