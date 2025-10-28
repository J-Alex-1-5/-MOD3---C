#include <stdio.h>
#include <stdlib.h>

int main() {
    //Asignacion y desasignacion de memoria.
    //malloc, calloc, realloc, free

    //malloc: El contenido es basura, no inicializado. <Memory Allocation> -> Si falla devuelve NULL. Tiene contenido basura.

    //calloc: Similar al anterior pero inicializa todo a 0. <Contiguous Allocation> -> Si falla devuelve NULL. Inicializa todo a 0.

    //realloc: Sirve para redimensioar memoria ya asignada. <Reallocation> -> Si falla devuelve NULL. Si se redimensiona, el contenido se mantiene, si no se redimensiona, se pierde el contenido.

    //free: Liberar la memoria que se pidio en malloc, calloc o realloc.

    int *m = (int *)malloc(5 * sizeof(int)); //Multiplicar la cantidad de un elemento por la cantidad de elementos. Esto asigna memoria para 5 enteros.

    int *c = (int *)calloc(5, sizeof(int)); //Asignar memoria para 5 enteros, inicializados a 0.

    m = (int *)realloc(m, 10 * sizeof(int)); //Redimensionar el bloque de memoria para 10 enteros. Si falla, m será NULL y se perderá la referencia a la memoria original.

    printf("===EJERCICIO PRACTICO SOBRE ASIGNACION DE MEMORIA===\n");
    printf("====================================================\n");

    int n;
    printf("Cuantos numeros desea ingresar? ");
    scanf("%d",&n);
    int *numeros = (int *)malloc(n * sizeof(int));

    if (numeros == NULL) {
        printf("Error al asignar memoria. \n");
        return 1; // Salir del programa si la asignación falla
    }

    for(int i = 0; i < n; i++){
        printf("Ingrese el numero %d: ", i + 1);// Sumamos uno al i? -> Mostrar el numero de iteracion al usuario.
        scanf("%d", &numeros[i]);// Usamos el valor de i sin sumar? -> Guardar el numero en la posicion i del arreglo numeros.
    }

    printf("Los numeros ingresados son: \n");
    for(int i = 0; i < n; i++){
        printf("%d ", numeros[i]);
    }

    free(numeros); // Liberar la memoria asignada a numeros
    numeros = NULL; // Opcional: evitar puntero colgante

    return 0;
}