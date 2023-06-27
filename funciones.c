#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu() {
    printf("-*-*-*-*-*-*-*-*-*-MENU-*-*-*-*-*-*-*-*-*-\n");
    printf("a) VER PRODUCTOS\n");
    printf("b) INGRESO DE PRODUCTOS\n");
    printf("c) MODIFICACION DE PRODUCTO\n");
    printf("d) ELIMINAR PRODUCTOS\n");
}

void mostrar(int cantidad[7], int id[7], char nombre[7][20], int precio[7]) {
    printf("Codigo\t\tNombre\t\tCantidad\t\tPrecio\n");
    for (int i = 0; i < 7; i++) {
        printf("%d\t\t%s\t\t%d\t\t%d\n", id[i], nombre[i], cantidad[i], precio[i]);
    }
}

void ingreso(int cantidad[7], int id[7], char nombre[7][20], int precio[7]) {
    for (int i = 0; i < 7; i++) {
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

void modificar(int cantidad[7], int id[7], char nombre[7][20], int precio[7]) {
    int codigo;
    printf("Codigo producto a modificar\n");
    scanf("%d",&codigo);
    for (int i = 0; i < 7; i++) {
        if (id[i] == codigo) {
            printf("Ingrese la cantidad: ");
            scanf("%d", &cantidad[i]);
            printf("Ingrese la precio: ");
            scanf("%d", &precio[i]);
            break;
        }
    }
}

void eliminar(int cantidad[7], int id[7], char nombre[7][20], int precio[7]) {
    int codigo;
    printf("Codigo producto a eliminar\n");
    scanf("%d",&codigo);

    for (int i = 0; i < 7; i++) {
        if (id[i] == codigo) {
            id[i]=0;
            strcpy(nombre[i],"Vacio");
            cantidad[i]=0;
            precio[i]=0;
            break;
        }
    }
}
