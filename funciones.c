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
int crearArchivo(char nombreArchivo[])
{
    FILE *archivo;
    archivo = fopen(nombreArchivo, "w+");
    if (archivo == NULL)
    {
        printf("No se puede crear el archivo\n");
        return 0;
    }else
    {
        printf("Se ha creado el archivo, %s\n",nombreArchivo);
        fclose(archivo);
    }   
    return 1;
}

void guardarJuguetes(char nombreArchivo[], char juguetes[5][4][50])
{
    FILE *archivo;
    archivo = fopen(nombreArchivo, "w+");
    if (archivo == NULL)
    {
        printf("No se puede guardar en el archivo\n");
    }
    else
    {
        for (int i = 0; i < 5; i++)
        {
            fprintf(archivo, "%s %s %s %s\n", juguetes[i][0], juguetes[i][1], juguetes[i][2], juguetes[i][3]);
        }
        fclose(archivo);
    }
}

void ingresarJuguete(char nombreArchivo[])
{
    char id[50];
    char nombre[50];
    float precio;
    int cantidad;
    FILE *archivo;
    archivo = fopen(nombreArchivo, "a");
    if (archivo == NULL)
    {
        printf("No se puede escribir en el archivo\n");
    }
    else
    {
        printf("ID: ");
        scanf("%s", id);
        printf("Nombre: ");
        scanf("%s", nombre);
        printf("Precio: ");
        scanf("%f", &precio);
        printf("Cantidad: ");
        scanf("%d", &cantidad);

        fprintf(archivo, "%s %s %.2f %d\n", id, nombre, precio, cantidad);
        fclose(archivo);
    }
}

void cambiarEstado(char nombreArchivo[], long posicion)
{
    FILE *archivo;
    char id[50];
    char nombre[50];
    float precio;
    int cantidad;
    int nuevoEstado;
    
    printf("Indique el nuevo estado: ");
    scanf("%d", &nuevoEstado);
    
    archivo = fopen(nombreArchivo, "r+");
    if (archivo == NULL)
    {
        printf("No se puede leer el archivo\n");
    }
    else
    {
        fseek(archivo, posicion, 0);
        fscanf(archivo, "%s %s %f %d", id, nombre, &precio, &cantidad);
        fseek(archivo, posicion, 0);
        fprintf(archivo, "\n%s %s %.2f %d", id, nombre, precio, nuevoEstado);
        fclose(archivo);
    }
}

void eliminar(char nombreArchivo[], long posicion)
{
    FILE *archivo;
    char id[50];
    char nombre[50];
    float precio;
    int cantidad;

    char idn[50] = {"0000"};
    char nombren[50] = {"ELIMINADO"};
    float precion = 0;
    int cantidadn = 0;

    archivo = fopen(nombreArchivo, "r+");
    if (archivo == NULL)
    {
        printf("No se puede leer el archivo\n");
    }
    else
    {
        fseek(archivo, posicion, 0);
        fscanf(archivo, "%s %s %f %d", id, nombre, &precio, &cantidad);
        fseek(archivo, posicion, 0);
        fprintf(archivo, "\n%s %s %.2f %d", idn, nombren, precion, cantidadn);
        fclose(archivo);
    }
}

long buscarJuguetePorId(char nombreArchivo[])
{
    FILE *archivo;
    char idBuscado[50];
    char nombreEncontrado[50];
    float precio;
    int cantidad;
    long posicion;
    char id[50];

    printf("Ingrese el ID a buscar: ");
    scanf("%s", id);

    archivo = fopen(nombreArchivo, "r+");
    if (archivo == NULL)
    {
        printf("No se puede leer el archivo\n");
    }
    else
    {
        while (!feof(archivo))
        {
            posicion = ftell(archivo);
            fscanf(archivo, "%s %s %f %d", idBuscado, nombreEncontrado, &precio, &cantidad);
            if (strcmp(idBuscado, id) == 0)
            {
                printf("Se encontró el juguete con el ID %s y nombre %s\n", idBuscado, nombreEncontrado);
                break;
            }
        }
        fclose(archivo);
    }
    return posicion;
}

void leerJuguetes(char nombreArchivo[]){
    FILE *archivo;
    char id[50];
    char nombre[50];
    float precio;
    int cantidad;
    archivo=fopen(nombreArchivo,"r+");
    if (archivo==NULL)
    {
        printf("no se pudo abrir el archivo");
    }
    for (int i = 0; i < 5; i++)
    {
         fscanf(archivo,"%s %s %f %d",&id,&nombre,&precio,&cantidad);
         printf("%s %s %f %d\n",id,nombre,precio,cantidad);
    }
    fclose(archivo);
}