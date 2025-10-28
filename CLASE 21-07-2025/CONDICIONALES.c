#include <stdio.h>

int main () {
    int verdadero = 1; // verdadero
    int falso = 0; // falso

    bool esVerdero = true;
    bool esFalso = false;

    printf("Verdadero: %d, Falso: %d\n", verdadero, falso);
    printf("Es verdadero: %d, Es falso: %d\n", esVerdero, esFalso);

    /*
    Operadores DE COMPRACION
    == (igual a), != (diferente de), < (menor que), > (mayor que),  <= (menor o igual que), >= (mayor o igual que)
    */

    /*
    OPERADORES LOGICOS
    && (AND), || (OR), ! (NOT)
    */

    /*
    CONDICIONALES
    if 
    if-else
    ELSE IF
    */

    int edad = 20;
    if (edad >= 18) {
        printf("Eres mayor de edad.\n");
    } 

    int  nota =80;
    if(nota>=60) {
        printf("Aprobado\n");
    } else {
        printf("Reprobado\n");
    }

    /*
    Switch (case)
    Es una estructura de control que permite seleccionar una de varias opciones basadas en el valor de una variable.
    Se utiliza principalmente cuando se tiene una variable que puede tomar varios valores discretos y se desea
    */
    int opcion = 2;
    printf("menu\n");
    printf("1. Opción 1\n");    
    printf("2. Opción 2\n");
    printf("Seleccione una opción: ");


    switch (opcion) {
        case 1:
            printf("Opción 1 seleccionada.\n");
            break;
        case 2:
            printf("Opción 2 seleccionada.\n");
            break;
        default:
            printf("Opción no válida.\n");
            break;
    default:
            printf("Opción no válida.\n");
            break;
    }
    return 0;
}