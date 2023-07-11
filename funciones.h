void menu();
int crearArchivo(char nombreArchivo[]);
void guardarJuguetes(char nombreArchivo[], char nombres[5][4][50]);
void ingresarJuguete(char nombreArchivo[]);
void cambiarEstado(char nombreArchivo[],long posicion);
void eliminar(char nombreArchivo[],long posicion);
long buscarJuguetePorId(char nombreArchivo[]);