#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

// --- Definición de estructuras ---
typedef struct {
    char nombre[50];
    char curso[30];
    float nota;
} Estudiante;

// --- 1.2 Manejo de parámetros variables ---
void registrarMensaje(const char *formato, int n, ...) {
    va_list args;
    va_start(args,n);
    for(int i = 0; i < n; i++){
        const char *msg = va_arg(args,const char*);
        printf(formato,msg);
    }
    va_end(args);
}

// --- 1.2.4 Recursividad ---
int buscarRecursivo(Estudiante *arr, int n, const char *nombre, int index) {
    if(index >= n) return -1; //Caso base
    if(strcmp(arr[index].nombre, nombre) == 0) return index;
    return buscarRecursivo(arr,n,nombre,index+1);
}

// --- 1.3 E/S de bajo nivel ---
void guardarArchivo(const char *filename, Estudiante *arr, int n) {
    int fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if(fd < 0){
        perror("Error al abrir archivo");
        exit(1);
    }
    write(fd, arr, sizeof(Estudiante) * n);
    close(fd);
}

// Por Hacer: Crear función que muestre metadatos de un archivo con stat
void mostrarMetadatos(const char *filename) {
    struct stat info;
    if(stat(filename, &info) == -1){
        perror("Error al obtener metadatos");
        return;
    }
    printf("\n--- Metadatos del archivo ---\n");
    printf("Tamaño: %ld bytes\n", info.st_size);
    printf("Permisos: %o\n", info.st_mode & 0777);
    printf("Última modificación: %s", ctime(&info.st_mtime));
}

// --- 1.4 Memoria y cadenas ---
Estudiante *agregarEstudiante(Estudiante *arr, int *n, const char *nombre, const char *curso, float nota) {
    Estudiante *nuevo = realloc(arr, sizeof(Estudiante) * (*n + 1));
    if(!nuevo){
        perror("Error al asignar memoria");
        return arr;
    }
    strcpy(nuevo[*n].nombre, nombre);
    strcpy(nuevo[*n].curso, curso);
    nuevo[*n].nota = nota;
    (*n)++;
    return nuevo;
}

int main() {
    Estudiante *lista = NULL;
    int n = 0;

    registrarMensaje("Mensaje: %s\n",2,"Bienvenido al sistema","Ingrese estudiantes");

    // Agregar algunos estudiantes con agregarEstudiante
    lista = agregarEstudiante(lista, &n, "Ana", "Matemáticas", 85.5);
    lista = agregarEstudiante(lista, &n, "Luis", "Física", 90.0);
    lista = agregarEstudiante(lista, &n, "Mario", "Química", 78.2);

    // Guardar lista de estudiantes en archivo binario
    guardarArchivo("estudiantes.dat", lista, n);

    // Buscar estudiante por nombre usando recursividad
    int pos = buscarRecursivo(lista,n,"Mario",0);
    if(pos != -1){
        printf("\nEstudiante encontrado: %s con nota %.2f\n",lista[pos].nombre,lista[pos].nota);
    } else{
        printf("\nEstudiante no encontrado\n");
    }

    // Mostrar metadatos del archivo
    mostrarMetadatos("estudiantes.dat");

    // Liberar memoria dinámica
    free(lista);

    return 0;
}