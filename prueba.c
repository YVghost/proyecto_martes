#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int id[7] = {1111, 2222, 3333, 4444, 5555, 0, 0};
    int cantidad[7] = {10, 1, 8, 14, 2, 0, 0};
    int precio[7] = {5, 3, 8, 16, 5, 0, 0};
    char nombre[7][20] = {"Pelota", "Peluche", "Carro", "Lego", "Barbie", "Vacio", "Vacio"};

    int menus = 1;
    do {
        menu();
        char opcion;
        scanf(" %c", &opcion);

        switch (opcion) {
            case 'a':
                mostrar(cantidad, id, nombre, precio);
                break;

            case 'b':
                ingreso(cantidad, id, nombre, precio);
                break;
            case 'c':
                modificar(cantidad,id, nombre, precio);
                break;
            case 'd':
                eliminar(cantidad,id, nombre, precio);
                break;

            default:
                menus = 0;
                break;
        }
    } while (menus == 1);

    return 0;
}






