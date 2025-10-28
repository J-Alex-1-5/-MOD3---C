/*
variables : Son un espacio reservado en mermoria. Tiene un dato y tiene un identificador
Nombre: Letras, Numeros o guiones bajo.
No pueden empezar con numeros.

int edad = 20; // Declaracion de variable
float peso = 70.5; // Declaracion de variable
char inicial = 'A'; // Declaracion de variable

entero          int          2 o 4 bytes    int edad = 20;
decimal         float        4 bytes        float peso = 70.5;
decimal + pr    double       8 bytes        double altura = 1.75;
caracter        char         1 byte         char inicial = 'A';
texto           char[]       depende        char nombre[] = "Alejandro";

MOSTRAR VALORES DE VARIABLES CON printf

printf("El valor de la edad es: %d\n", edad);
i

int     %d          print("edad: %d", edad);
float   %f          print("peso: %.2f", peso);
char    %c          print("inicial: %c", inicial);
string  %s          print("nombre: %s", nombre);
*/


#include <stdio.h>
int main() {
    
    int edad = 20; 
    float peso = 70.5;
    char inicial = 'A';
    char nombre[] = "Alejandro";

    printf("Nombre: %s", nombre);
    printf("Salario: %.2f",peso);
    printf("Edad: %d", edad);
    printf("Inicial: %c", inicial);
    printf("\n\n");
        printf("Nombre: %s\n", nombre);
    printf("Salario: %.2f\n",peso);
    printf("Edad: %d\n", edad);
    printf("Inicial: %c\n", inicial);

    print("DECLARACIONES DE OPERACIONES DE OPERADORES LOGICOS\n");

    int A= 8, B = 4;
    int suma = A + B ;
    int modulo = A % B;

    print ("Suma: %d\n", suma);
    print ("Modulo: %d\n", modulo);
    printf("%d es mayor (>) que %d: %d\n", A, B, A > B);

    return 0;
}