#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 7

void menu();
void mostrar(int cantidad[TAM], int id[TAM], char nombre[TAM][20], int precio[TAM]);
void ingreso(int cantidad[TAM], int id[TAM], char nombre[TAM][20], int precio[TAM]);
void eliminar(int cantidad[TAM], int id[TAM], char nombre[TAM][20], int precio[TAM]);

int main() {
    int id[TAM] = {1111, 2222, 3333, 4444, 5555, 0, 0};
    int cantidad[TAM] = {10, 1, 8, 14, 2, 0, 0};
    int precio[TAM] = {5, 3, 8, 16, 5, 0, 0};
    char nombre[TAM][20] = {"Pelota", "Peluche", "Carro", "Lego", "Barbie", "Vacio", "Vacio"};

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

void menu() {
    printf("-*-*-*-*-*-*-*-*-*-MENU-*-*-*-*-*-*-*-*-*-\n");
    printf("a) VER PRODUCTOS\n");
    printf("b) INGRESO DE PRODUCTOS\n");
    printf("c) MODIFICACION DE PRODUCTO\n");
    printf("d) ELIMINAR PRODUCTOS\n");
}

void mostrar(int cantidad[TAM], int id[TAM], char nombre[TAM][20], int precio[TAM]) {
    printf("Codigo\t\tNombre\t\tCantidad\t\tPrecio\n");
    for (int i = 0; i < TAM; i++) {
        printf("%d\t\t%s\t\t%d\t\t%d\n", id[i], nombre[i], cantidad[i], precio[i]);
    }
}

void ingreso(int cantidad[TAM], int id[TAM], char nombre[TAM][20], int precio[TAM]) {
    for (int i = 0; i < TAM; i++) {
        if (id[i] == 0) {
            printf("Ingrese el id: ");
            scanf("%d", &id[i]);
            printf("Ingrese el nombre: ");
            scanf(" %[^\n]", nombre[i]);
            printf("Ingrese la cantidad: ");
            scanf("%d", &cantidad[i]);
            printf("Ingrese la precio: ");
            scanf("%d", &precio[i]);            
            break;
        }
    }
}

void modificar(int cantidad[TAM], int id[TAM], char nombre[TAM][20], int precio[TAM]) {
    int codigo;
    printf("Codigo producto a modificar\n");
    scanf("%d",&codigo);
    for (int i = 0; i < TAM; i++) {
        if (id[i] == codigo) {
            printf("Ingrese la cantidad: ");
            scanf("%d", &cantidad[i]);
            printf("Ingrese la precio: ");
            scanf("%d", &precio[i]);
            break;
        }
    }
}

void eliminar(int cantidad[TAM], int id[TAM], char nombre[TAM][20], int precio[TAM]) {
    int codigo;
    printf("Codigo producto a eliminar\n");
    scanf("%d",&codigo);

    for (int i = 0; i < TAM; i++) {
        if (id[i] == codigo) {
            id[i]=0;
            strcpy(nombre[i],"Vacio");
            cantidad[i]=0;
            precio[i]=0;
            break;
        }
    }
}






