#include <stdio.h>
#include <string.h>

int main(){

    struct Estudiante {
        char nombre[50];
        int edad;
        float promedio;
    };
    
    struct Estudiante alumno1;
    
    strcpy(alumno1.nombre, "Juan Perez");
    alumno1.edad = 20;
    alumno1.promedio = 91.5;

    printf("Nombre: %s\n", alumno1.nombre);
    printf("Edad: %d\n", alumno1.edad);
    printf("Promedio: %.2f\n", alumno1.promedio);
    printf("=======================================================``\n");
    


    printf("===EJERCICIO PRACTICO SOBRE ESTRUCTURAS===\n");
    printf("=========================================\n");
    typedef struct {
        char municipio[50];
        char departamento[50];
    } direccion;

    typedef struct{
        char nombre[50];
        int edad;
        direccion direccion;
    }Trabajador;

    Trabajador t1;
    strcpy(t1.nombre, "Maria Lopez");
    t1.edad = 30;

    strcpy(t1.direccion.municipio, "coban");    
    strcpy(t1.direccion.departamento, "Alta Verapaz");

    printf("Nombre: %s\n", t1.nombre);
    printf("Edad: %d\n", t1.edad);
    printf("Municipio: %s\n", t1.direccion.municipio);
    printf("Departamento: %s\n", t1.direccion.departamento);

    return 0;
}
