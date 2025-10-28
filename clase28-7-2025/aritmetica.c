#include <stdio.h>

int main (){

    
printf("================================================\n");
    int numero [] = {1, 2, 3, 4, 5};
    int *p = numero; // P esta apuntador al primer elemento del array

    // cuando sumamos puntero +1 estamos sumando el tamaño del tipo de dato al que apunta
    printf("EL valor actual : %d\n", *p);
    p++; // Avanzar al siguiente elemento
    printf("El siguiente valor: %d\n", *p);
    p += 2; // Avanzar dos elementos
    printf("El valor dos posiciones adelante: %d\n", *p);
    p--; // Retroceder un elemento
    printf("El valor un posicion atras: %d\n", *p);

    printf("Valor desconocido : %d\n", numero[10]); // Acceso a un valor fuera del rango del array

    printf("Valor desconocido: %d\n", p + 10); // Acceso a un valor fuera del rango del array usando punteros
    
    for(int i =0; i <10; i++){
        printf("Valor en la posicion %d: %d\n", numero[i]); // Acceso a valores usando punteros
    }


printf("================================================\n");
    // aray de dos mimensiiocn
    int matriz[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    int (*ptr)[3] = matriz; // Puntero a un array de 3 enteros
    
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            printf("Valor en matriz[%d][%d]: %d\n", i, j, ptr[i][j]); // Acceso a valores en la matriz usando punteros
        }
    }


printf("================================================\n");
    // modificar los elementos usando punteros

    int arr2[] = {10, 20, 30, 40, 50};
    int *puntero = arr2;

    for(int i = 0; i < 5; i++){
        *(puntero+i) *= 2; 
        puntero++; // Avanzar al siguiente elemento
    }

    for(int i = 0; i < 5; i++){
        printf("arr2%d] = %d\n", i, *(puntero + i)); // Imprimir valores modificados
    }

    return 0;
}


