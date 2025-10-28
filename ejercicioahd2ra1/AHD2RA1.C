#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMBRE 50

typedef struct {
    char nombre[MAX_NOMBRE];
    int cantidad;
    float precio;
} Producto;

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    FILE *archivoEntrada = fopen("productos.txt", "r");
    if (!archivoEntrada) {
        printf("Error al abrir 'productos.txt'.\n");
        return 1;
    }

    Producto *inventario = NULL;
    int totalProductos = 0;
    char linea[100];

    printf("=== Sistema de Inventario ===\nLeyendo datos desde 'productos.txt'...\n");

    while (fgets(linea, sizeof(linea), archivoEntrada)) {
        inventario = realloc(inventario, (totalProductos + 1) * sizeof(Producto));
        if (!inventario) {
            printf("Error de memoria.\n");
            fclose(archivoEntrada);
            return 1;
        }

        char *token = strtok(linea, ",");
        strncpy(inventario[totalProductos].nombre, token, MAX_NOMBRE);

        token = strtok(NULL, ",");
        inventario[totalProductos].cantidad = atoi(token);

        token = strtok(NULL, ",");
        inventario[totalProductos].precio = atof(token);

        totalProductos++;
    }
    fclose(archivoEntrada);

    printf("Se leyeron %d productos exitosamente.\n", totalProductos);
    printf("Lista de productos:\n");
    for (int i = 0; i < totalProductos; i++) {
        printf("%d. Nombre: %s | Cantidad: %d | Precio: %.2f\n",
            i + 1, inventario[i].nombre, inventario[i].cantidad, inventario[i].precio);
    }

    Producto nuevo;
    printf("\nIngrese un nuevo producto:\nNombre: ");
    fgets(nuevo.nombre, MAX_NOMBRE, stdin);
    nuevo.nombre[strcspn(nuevo.nombre, "\n")] = '\0';

    printf("Cantidad: ");
    scanf("%d", &nuevo.cantidad);
    limpiarBuffer();

    printf("Precio: ");
    scanf("%f", &nuevo.precio);
    limpiarBuffer();

        float valorTotal = 0;
    for (int i = 0; i < totalProductos; i++) {
        valorTotal += inventario[i].cantidad * inventario[i].precio;
    }
    printf("\nValor total del inventario: %.2f\n", valorTotal);


    FILE *archivoSalida = fopen("productos_salida.txt", "w");
    if (!archivoSalida) {
        printf("Error al crear 'productos_salida.txt'.\n");
        free(inventario);
        return 1;
    }

    inventario = realloc(inventario, (totalProductos + 1) * sizeof(Producto));
    if (!inventario) {
        printf("Error de memoria al agregar producto.\n");
        return 1;
    }
    inventario[totalProductos] = nuevo;
    totalProductos++;

    printf("Producto agregado exitosamente con realloc.\n");



    for (int i = 0; i < totalProductos; i++) {
        fprintf(archivoSalida, "%s,%d,%.2f\n",
                inventario[i].nombre,
                inventario[i].cantidad,
                inventario[i].precio);
    }
    fclose(archivoSalida);

    printf("Guardando datos actualizados en 'productos_salida.txt'... Archivo generado correctamente.\n");

    free(inventario);
    return 0;
}