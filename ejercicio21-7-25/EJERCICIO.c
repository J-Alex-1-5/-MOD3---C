#include <stdio.h>

int main () {
    char respuesta;
    int edad, nivel;
    float nota;
    char nombre[50];
    bool aprobado;

    do{
        printf("\n ----REGISTRO DE ESTUDIANTE------\n");

        printf("Ingrese el nombre del estudiante: ");
        scanf(" %[^\n]", nombre);

        printf("Ingrese la edad del estudiante: ");
        scanf("%d", &edad);

        if (edad <= 12) {
            prontf("La edad del estudiante no es mayopr a 12 a;os. \n");
            continue; // Salta al siguiente ciclo del do-while
        }

        printf("Ingrese la nota final del estudiante: ");
        scanf("%f", &nota);

        if(nota < 0.00 || nota > 100.00) {
            printf("La nota no es valida.\n");
            continue; // Salta al siguiente ciclo del do-while
        }

        aprobado = (nota >= 61.00);

        prontf("\n ---DATOS DEL ESTUDIANTE--- \n");
        printf("Nombre: %s\n", nombre);
        printf("Edad: %d\n", edad);
        printf("Nota final: %.2f\n", nota);
        printf("Estado>: %s\n", aprobado ? "Aprobado" : "Reprobado");

        // Operador Ternario: (condición) ? valor_si_verdadero : valor_si_falso

        printf("Niver Academico: ");
        switch (nivel)
        {
        case 1:
            printf("Basico\n");
            break;
        case 2:
            printf("Diversificado\n");
            case 3:
            printf("Universitario\n");
        }


        printf("\n Ddesea ingresar otro estudiante? (S/N): ");
        scanf(" %c", &respuesta);
    }while (respuesta == 'S' || respuesta == 's');
    {
    
    }
    

    return 0;
}