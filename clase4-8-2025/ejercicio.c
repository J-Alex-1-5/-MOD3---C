// vamos a realizar un ejercicico

//definir una estructura llamada producto
// nombre
// precio
// promedio

// vamos a solicitarle que ingrese 2 propductos 
// al recibir los productos vamos a calcular el promedio de los precios de los productos ingresados
// camos a imprimir los datops de forma ordenada


#include <stdio.h>
#include <string.h>


typedef struct {
    char nombre[30];
    float precios[3];
    float promedio;
} producto;

void Producto(producto *p) {
    printf("Ingrese el nombre del producto: ");
    fgets(p->nombre, sizeof(p->nombre), stdin);
    size_t len = strlen(p->nombre);
    if (len > 0 && p->nombre[len - 1] == '\n') {
        p->nombre[len - 1] = '\0';
    }

    printf("Ingrese los precios de los últimos 3 meses:\n");
    for (int i = 0; i < 3; i++) {
        printf("Mes %d: Q", i + 1);
        scanf("%f", &p->precios[i]);
    }
    getchar();
}

void calcularPromedio(producto *p) {
    float suma = 0;
    for (int i = 0; i < 3; i++) {
        suma += p->precios[i];
    }
    p->promedio = suma / 3;
}

void imprimirProducto(const producto *p) {
    printf("\nProducto: %s\n", p->nombre);
    printf("Precios: Q%.2f Q%.2f Q%.2f\n",
        p->precios[0], p->precios[1], p->precios[2]);
    printf("Promedio: Q%.2f\n", p->promedio);
}

typedef float (*Operacion)(float); 


float aumentar10Porciento(float precio) {
    return precio * 1.10f;
}


void aplicarOperacion(producto *p, Operacion op) {
    for (int i = 0; i < 3; i++) {
        p->precios[i] = op(p->precios[i]);
    }
}

int main() {
    producto productos[2];

    for (int i = 0; i < 2; i++) {
        printf("\nProducto %d:\n", i + 1);
        Producto(&productos[i]);
        calcularPromedio(&productos[i]);
    }
    printf("\nDatos de productos (originales):\n");
    for (int i = 0; i < 2; i++) {
        imprimirProducto(&productos[i]);
    }

    for (int i = 0; i < 2; i++) {
        aplicarOperacion(&productos[i], aumentar10Porciento);
        calcularPromedio(&productos[i]); 
    }

    printf("\nDatos de productos (con aumento del 10%%):\n");
    for (int i = 0; i < 2; i++) {
        imprimirProducto(&productos[i]);
    }

    return 0;
}