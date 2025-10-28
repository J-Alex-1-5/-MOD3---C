#include <stdio.h>

typedef struct {
    char nombre[50];
    int edad;
} Persona; 

void mostrarInfo(Persona p) {
    printf("Nombre: %s\n", p.nombre);
    printf("Edad: %d\n", p.edad);
}

void crecer(Persona *p) {
    p->edad += 1; // Incrementa la edad de la persona
}


int main() {
    Persona p = {"Mario",35};
    mostrarInfo(p);
    crecer(&p);
    mostrarInfo(p);
    printf("====================================\n");
    
    return 0;
}