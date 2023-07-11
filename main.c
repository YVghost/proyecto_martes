
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int main()
{

    char nombres[5][4][50] = {{"1111", "Pelota", "5.00", "1"},
                              {"2222", "Peluche", "3.00", "1"},
                              {"3333", "Carro", "8.00", "1"},
                              {"4444", "Lego", "16.00", "1"},
                              {"5555", "Barbie", "5.000", "1"}};

    char nombreArchivo[20] = "Bodega.txt";
    long posicion;
    FILE *archivo;

    archivo = fopen(nombreArchivo, "w+");
    int co = 5;

    if (archivo == NULL)
    {
        crearArchivo(nombreArchivo);
        guardarJuguetes(nombreArchivo, nombres);
   
    }
    else
    {
        guardarJuguetes(nombreArchivo, nombres);
        int menus = 1;
        do
        {
            menu();
            char opcion;
            scanf(" %c", &opcion);

            switch (opcion)
            {
            case 'a':
                leerJuguetes(nombreArchivo, co);
                break;

            case 'b':
                ingresarJuguete(nombreArchivo);
                co++;
                break;

            case 'c':
                posicion = buscarJuguetePorId(nombreArchivo);
                if (posicion != -1)
                {
                    cambiarEstado(nombreArchivo, posicion);
                }
                else
                {
                    printf("No se encontró un juguete con el ID especificado.\n");
                }
                break;

            case 'd':
                posicion = buscarJuguetePorId(nombreArchivo);
                if (posicion != -1)
                {
                    eliminar(nombreArchivo, posicion);
                    printf("El juguete ha sido eliminado.\n");
                }
                else
                {
                    printf("No se encontró un juguete con el ID especificado.\n");
                }
                break;

            default:
                menus = 0;
                break;
            }
        } while (menus == 1);

        return 0;
    }

    return 0;
}
