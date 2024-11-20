La función dentro de initConFun llamada write particles es una función en C que escribe información sobre partículas en un archivo, tomando en cuenta un tipo de frontera (boundary_type) para determinar cuántas partículas procesar. Tiene como parámetros:

1. FILE *file: Apunta al archivo donde se escribirá la información de las partículas.
2. int start_index: Índice inicial de las partículas que se procesarán.
3. int num_particles: Número total de partículas a procesar.
4. char *boundary_type: Tipo de frontera que ajusta cuántas partículas incluir y cómo calcular el índice final.

El condicional tiene como objetivo ajustar end_index dependiendo del tipo de frontera:

- "bottom" o "top": Incrementa el rango en 1 (npV+1).
- "right" o "left": Reduce el rango en 1 (npV-1).
- "all": Usa directamente num_particles como el rango final.

Si no se reconoce el tipo, muestra un mensaje de error y termina la función.