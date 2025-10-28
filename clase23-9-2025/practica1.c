#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
//Practica #1: Vamos a leer un documento de forma recursiva sin conocer previamente cuantos registros tiene.
//Metadatos con stat() -> Conocer el tamaño del archivo
//Calculo dinamico de cuantos registros tiene
//Lectura recursiva de todos los registros de un archivo binario

typedef struct{
    int id;
    char nombre[20];
    float promedio;
} Estudiantes;

//Funcion recrusvia para leer registros
void leer_registros(int fd, int total, int index){
    //Caso base: no hay/no mas registros
    if(index >= total){
        return;
    }

    Estudiantes e;
    if(read(fd, &e, sizeof(Estudiantes)) == sizeof(Estudiantes)){
        printf("Registros %d: ID: %d, Nombre: %s, Promedio: %.2f\n",index + 1, e.id, e.nombre, e.promedio);
    }

    //Llamada recursiva: Leer el siguiente estudiante
    leer_registros(fd, total, index + 1);
}

int main(){
    const char *archivo = "estudiantes.bin";
    struct stat info;

    Estudiantes nuevo;
    nuevo.id = 7;
    strcpy(nuevo.nombre, "Daniel Lopez");
    nuevo.promedio = 9.4;

    //Abrir el archivo en modo escritura al final (append binario)
    int fdw = open(archivo, O_WRONLY | O_APPEND | O_CREAT, 0644);
    if(fdw == -1){
        perror("OPEN ESCRITURA");
        return 1;
    }

    //Escribir el registro al final
    ssize_t bytes = write(fdw, &nuevo, sizeof(Estudiantes));
    if(bytes == -1){
        perror("write");
        close(fdw);
        return 1;
    } else {
        printf("Se agrego un nuevo registro (%ld bytes excritos)\n",(long)bytes);
        close(fdw);
    }

    //Obtener los metadatos
    if(stat(archivo,&info) == -1){
        perror("stat");
        return 1;
    }

    int total_registros = info.st_size / sizeof(Estudiantes);
    printf("El archivo tiene %d registros (%lld bytes)\n",total_registros,(long long)info.st_size);

    //Abrir el archivo binario
    int fd = open(archivo, O_RDONLY);

    if(fd == -1){
        perror("open");
        close(fd);
        return 1;
    }

    //Leer de forma recursiva los registros
    leer_registros(fd,total_registros,0);

    close(fd);
    return 0;
}