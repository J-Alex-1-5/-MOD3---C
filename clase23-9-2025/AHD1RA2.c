#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

// --- Definición de estructuras ---
typedef struct {
    char nombre[50];
    char curso[30];
    float nota;
} Estudiante;

// --- 1.2 Manejo de parámetros variables ---
// Por Hacer: Crear una función que reciba un número variable de cadenas y las imprima
void registrarMensaje(const char *formato, int n, ...) {
    // Pista: usar va_list, va_start, va_arg, va_end
    va_list args;
    va_start(args,n);
    for(int i = 0; i < n; i++){
        const char *msg = va_arg(args,const char*);
        printf(formato,msg);
    }
    va_end(args);
}

// --- 1.2.4 Recursividad ---
// Por Hacer: Crear función recursiva que busque un estudiante por nombre
int buscarRecursivo(Estudiante *arr, int n, const char *nombre, int index) {
    // Pista: caso base (si no lo encuentra) y caso recursivo (avanzar en el arreglo)
    if(index >= n) return -1; //Caso base
    if(strcmp(arr[index].nombre, nombre) == 0) return index;
    return buscarRecursivo(arr,n,nombre,index+1);
}

// --- 1.3 E/S de bajo nivel ---
// Por Hacer: Crear función para guardar datos en archivo binario con open/write/close
void guardarArchivo(const char *filename, Estudiante *arr, int n) {
    // Pista: usar O_WRONLY | O_CREAT | O_APPEND
}

// Por Hacer: Crear función que muestre metadatos de un archivo con stat
void mostrarMetadatos(const char *filename) {
    // Pista: imprimir tamaño, permisos y última modificación
}

// --- 1.4 Memoria y cadenas ---
// Por Hacer: Crear función para agregar estudiante dinámicamente usando realloc
Estudiante *agregarEstudiante(Estudiante *arr, int *n, const char *nombre, const char *curso, float nota) {
    // Pista: aumentar tamaño del arreglo, copiar nombre y curso con strcpy
    return arr;
}

// --- Función principal ---
int main() {
    Estudiante *lista = NULL;
    int n = 0;

    // Por Hacer: Llamar a registrarMensaje con parámetros variables
    // Ejemplo esperado: "Bienvenido al sistema", "Ingrese estudiantes"
    registrarMensaje("Mensaje: %s\n",2,"Bienvenido al sistema","Ingrese estudiantes");

    // Por Hacer: Agregar algunos estudiantes con agregarEstudiante

    // Por Hacer: Guardar lista de estudiantes en archivo binario

    // Por Hacer: Buscar estudiante por nombre usando recursividad
    int pos = buscarRecursivo(lista,n,"Mario",0);
    if(pos != -1){
        printf("\nEstudiante encontrado: %s con nota %.2f\n",lista[pos].nombre,lista[pos].nota);
    } else{
        printf("\nEstudiante no encontrado\n");
    }

    // Por Hacer: Mostrar metadatos del archivo

    // Por Hacer: Liberar memoria dinámica

    return 0;
}