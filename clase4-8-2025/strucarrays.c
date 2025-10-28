#include <stdio.h>
#include <string.h>

int main(){
    typedef struct {
        char nombre[50];
        int notas[5];
    } Estudiante;

    Estudiante e1 = {"Carlos", {85, 90, 78, 92, 88}};
    Estudiante ptr1 = &e1; // Asignación de un puntero a la estructura

    printf("Print nota: %d\n", &e1.notas[0]); // Imprime la tercera nota (índice 2)
    printf("Primera nota: %d\n", ptr1 -> notas[0]); // Imprime la primera nota usando el puntero

    printf("Mostrando todas las notas del estudiante:\n");
    for (int i = 0; i < 5; i++){
        printf("Nota %d: %d\n", i + 1, e1.notas[i]); // Imprime cada nota del estudiante
    }

    printf("===EJERCICIO PRACTICO SOBRE ESTRUCTURAS DE DATOS===\n");
    printf("===================================================\n");
    printf("Creacion de un array de estructuras\n");
    Estudiante Programacion[5] = {
        {"Ana", {95, 88, 76, 85, 90}},
        {"Luis", {80, 82, 78, 88, 84}},
        {"Sofia", {92, 91, 89, 95, 93}},
        {"Pedro", {75, 80, 70, 78, 72}},
        {"Laura", {88, 90, 85, 92, 87}}
    };

    for (int i = 0; i < 5; i++)
    {
        printf("Estudiante %d:\n", i + 1, Programacion[i].nombre)  ;

        for (int j = 0; j < 5; j++)
        {
            printf("Nota %d: %d\n", i + 1, Programacion[i].notas[j]);
        }
        
    }
    
    
    return 0;
}