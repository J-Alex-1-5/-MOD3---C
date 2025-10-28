#include <stdio.h>
#include <stdarg.h>

//va_list -> Un tipo de dato usado para recorrer una lista de argumentos
//va_start -> inicializa el va_list
//va_arg -> Obtener el siguiente argumento valido de tipo definido
//va_end -> Libera el objeto va_start

void miPrintf(const char *formato, ...){
    va_list args;
    va_start(args, formato);
    vprintf(formato, args);
    va_end(args);
}

void mostrar_emteros(int cantidad, ...){
    va_list args;
    va_start(args,cantidad);

    for(int i = 0; i < cantidad; i++){
        int valor = va_arg(args,int);
        printf("%d ",valor);
    }

    va_end(args);
    printf("\n");
}

double promedio(int cantidad, ...){
    va_list args;
    va_start(args, cantidad);

    int suma = 0;
    for(int i = 0;i < cantidad;i++){
        int valor = va_arg(args,int);
        suma += valor;
    }

    va_end(args);
    return (double)suma/cantidad;
}

//Crear una funcion que lea una cantidad de numeros y muestre cual es el menor y cual es el mayor
//Usar una funcion con argumentos variables.

int main(){
    printf("FUNCIONES CON ARGUMENTOS VARIABLES IMITANDO printf\n");
    miPrintf("Hola %s tienes %d mensajes\n","Mario",10);
    printf("==================================\n");
    printf("FUNCIONES CON ARGUMENTOS VARIABLES - MOSTRAR ENTEROS\n");
    mostrar_emteros(10,1,2,3,4,5,6,7,8,9,10);
    printf("==================================\n");
    printf("FUNCIONES CON ARGUMENTOS VARIABLES - PROMEDIO\n");
    printf("Promedio de 3,5,6,7,8,9: %.2f\n",promedio(6,3,5,6,7,8,9));
    printf("Promedio de 12,65,43,45,67,87,65,23: %.2f\n",promedio(8,12,65,43,45,67,87,65,23));
    printf("Promedio de 98,87,99,100,95: %.2f\n",promedio(5,98,87,99,100,95));

    return 0;
}

//REGLAS DE USO
//1.- Debe existir un parametro fijo -> void funcion(...) 
//2.- EL programador debe saber con antelacion cuantos paremetros se enviaran(usar un contador o terminar con null)
//3.- Los argumentos se promocionan de forma automatica
    // float -> double || char/short -> int

//Riesgos
//va_args no valida tipos, solo asume. SI no es el correcto provoca fallas
//Vamos a tener errores si no manejamos la cantidad de argumentos.
//mostrar_emteros(5,2,3);

//Alternativas
//Si necesito enviar una cantidad de parametros variab les puedo usar arrays o estructuras

/*
PILA en parametros variables.

mostrar_emteros(3,10,20,30); -> Esta es la ejecucion de la funcion con parametros variables
|....|
| 30 | 4 <---    Ultimo argumento
| 20 | 4
| 10 | 4
| 03 | 4 <---    Ultimo parametro fijo
|....|

va_start -> Usa la posicion del Ultimo Parametro fijo (cantidad) y lo usa como referencia, luego ajusta un puntero interno (va_list) y avanza hacia la siguiente posicion.

Cada que llamamos a va_args(args,tipo) eL puntero avanza la cantidad de bytes del tipo y devuelve el siguiente valor.

El problema radica cuando no tenemos la cantidad de argumentos segun la cantidad enviada:
mostrar_emteros(2,10)
Si le indicamos que son dos argumentos, y solo enviamos 1 el puede leer datos basura de la pila, datos de otras variables o terminar el programa


*/