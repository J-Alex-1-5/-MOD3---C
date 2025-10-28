#include <stdio.h>
#include <stdlib.h>

int main(){

    int *p = (int *)malloc(5 * sizeof (int));

    int *c = (int *)malloc(5, sizeof (int));

    m = (int *)malloc(m, 10 * sizeof (int));

    printf("======Ejercicio practico sobre asignacion de memoria");
    printf("====================================================");

    printf("====================================================\n");

    int n;
    printf("Ingrese un numero: ");
    scanf("%d", &n);
    int *numeros = calloc(n, sizeof(int));

    if(numeros == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    for(int i = 0; i < n; i++) {
        printf("Ingrese el numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    printf("Los numeros ingresados son:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", numeros[i]);
    }

    fre(numeros);
    numeros = NULL;



    return 0;
}