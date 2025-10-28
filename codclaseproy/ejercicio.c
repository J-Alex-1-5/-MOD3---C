#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nombre[50];
    int cantidad;
    float precio;
} Producto;

void cargarProductos(const char *filename, Producto **productos, int *n) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Archivo no encontrado. Se iniciará con inventario vacío.\n");
        *productos = NULL;
        *n = 0;
        return;
    }

    *n = 0;
    *productos = NULL;
    Producto temp;

    while (fscanf(file, "%49[^,],%d,%f\n", temp.nombre, &temp.cantidad, &temp.precio) == 3) {
        Producto *tempArray = realloc(*productos, (*n + 1) * sizeof(Producto));
        if (!tempArray) {
            printf("Error de memoria al cargar productos.\n");
            fclose(file);
            return;
        }
        *productos = tempArray;
        (*productos)[*n] = temp;
        (*n)++;
    }
    fclose(file);
}

void guardarProductos(const char *filename, Producto *productos, int n) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error al guardar los productos.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(file, "%s,%d,%.2f\n", productos[i].nombre, productos[i].cantidad, productos[i].precio);
    }
    fclose(file);
}

void mostrarProductos(Producto *productos, int n) {
    printf("\nInventario actual:\n");
    for (int i = 0; i < n; i++) {
        printf("%d) %s - Cantidad: %d - Precio: Q%.2f\n", i + 1, productos[i].nombre, productos[i].cantidad, productos[i].precio);
    }
    if (n == 0) {
        fprintf("No hay productos en el inventario.\n");
    }
}

void agregarProducto(Producto *productos, int *n) {
    Producto nuevo;
    printf("Nombre del producto: ");
    getchar(); 
    fgets(nuevo.nombre, sizeof(nuevo.nombre), stdin);
    nuevo.nombre[strcspn(nuevo.nombre, "\n")] = '\0'; 

    printf("Cantidad: ");
    scanf("%d", &nuevo.cantidad);
    printf("Precio: ");
    scanf("%f", &nuevo.precio);

    Producto *tempArray = realloc(*productos, (*n + 1) * sizeof(Producto));
    if (!tempArray) {
        printf("Error de memoria al agregar producto.\n");
        return;
    }
    *productos = tempArray;
    (*productos)[*n] = nuevo;
    (*n)++;
    printf("Producto agregado.\n");
}

void modificarProducto(Producto *productos, int n) {
    if (n == 0) {
        printf("No hay productos para modificar.\n");
        return;
    }

    mostrarProductos(productos, n);
    int index;
    printf("Ingrese el número del producto a modificar: ");
    scanf("%d", &index);
    if (index < 1 || index > n) {
        printf("Índice inválido.\n");
        return;
    }

    index--;
    printf("Nuevo nombre (%s): ", productos[index].nombre);
    getchar();
    fgets(productos[index].nombre, sizeof(productos[index].nombre), stdin);
    productos[index].nombre[strcspn(productos[index].nombre, "\n")] = '\0';

    printf("Nueva cantidad (%d): ", productos[index].cantidad);
    scanf("%d", &productos[index].cantidad);
    printf("Nuevo precio (Q%.2f): ", productos[index].precio);
    scanf("%f", &productos[index].precio);
    printf("Producto modificado.\n");
}

void eliminarProducto(Producto **productos, int *n) {
    if (*n == 0) {
        printf("No hay productos para eliminar.\n");
        return;
    }

    mostrarProductos(*productos, *n);
    int index;
    printf("Ingrese el número del producto a eliminar: ");
    scanf("%d", &index);
    if (index < 1 || index > *n) {
        printf("Índice inválido.\n");
        return;
    }

    index--;
    for (int i = index; i < *n - 1; i++) {
        (*productos)[i] = (*productos)[i + 1];
    }

    Producto *tempArray = realloc(*productos, (*n - 1) * sizeof(Producto));
    if (!tempArray && *n - 1 > 0) {
        printf("Error de memoria al eliminar producto.\n");
        return;
    }
    *productos = tempArray;
    (*n)--;
    printf("Producto eliminado.\n");
}

int main() {
    Producto *productos = NULL;
    int n = 0;
    int opcion;
    const char *archivoEntrada = "productos.txt";
    const char *archivoSalida = "inventario_final.txt";

    cargarProductos(archivoEntrada, &productos, &n);

    do {
        printf("\nMenú de Inventario:\n");
        printf("1. Mostrar productos\n");
        printf("2. Agregar producto\n");
        printf("3. Modificar producto\n");
        printf("4. Eliminar producto\n");
        printf("5. Guardar y salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: mostrarProductos(productos, n); break;
            case 2: agregarProducto(&productos, &n); break;
            case 3: modificarProducto(productos, n); break;
            case 4: eliminarProducto(&productos, &n); break;
            case 5:
                guardarProductos(archivoSalida, productos, n);
                printf("Cambios guardados en '%s'.\n", archivoSalida);
                break;
            default:
                printf("Opción inválida.\n");
        }
    } while (opcion != 5);

    free(productos);
    return 0;
}