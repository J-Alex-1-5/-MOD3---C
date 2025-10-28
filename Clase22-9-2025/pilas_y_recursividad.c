//Numero indefinido de argumentos
//va_list, va_start, va_arg, va_end
#include <stdio.h>
#include <stdarg.h>

//Enfocado a las Pilas
//stack frame -> Marco de activacion
//Direccion de retorno - Parametros - Variables Locales
//El Stack frame debe poder ajustarse dinamicamente segun la cantidad de argumentos pasados.

//Enfocamos a la recursividad
//Cuando una funcion es recursiva, cada llamada genera un Stack Frame
//Cada llamado guarda sus propios parametros y variables locales
//Cada llamada puede recibir un numero distito de argumentos.
//Cuando la funcion retorna, se elemina el marco y se libera la pila}

int suma(int cantidad, ...){
    //Funcion que suma una cantidad variable de parametros
    va_list args;
    va_start(args,cantidad);
    int total = 0;

    for(int i = 0;i < cantidad; i++){
        total += va_arg(args, int); //lee cada entero de la pila
    }

    va_end(args);
    return total;

}

int suma_recursiva(int cantidad, ...){
    //Funcion recursiva que suma una cantidad variable de parametros
    va_list args;
    va_start(args,cantidad);

    //Validemos que la cantidad no sea = 0
    if(cantidad == 0){
        va_end(args);
        return 0;
    }

    int numero = va_arg(args, int); //Tomamos el primer argumento/numero

    int resto = 0;
    if(cantidad > 1){
        //Crear un arreglo temporal con los argumentos restantes
        int valores[cantidad - 1]; //Le restamos 1 porque ya se tomo el primer numero
        for(int i = 0; i < cantidad - 1; i++){
            valores[i] = va_arg(args,int);
        }
        va_end(args);

        //Limitamos la cantidad de valores a 3
        resto = suma_recursiva(cantidad - 1, valores[0],valores[1],valores[2]);
    } else{
        va_end(args);
    }
    
    return numero + resto;
}

int suma_recursiva_dos_auxiliar(int n, int arr[]){
    if(n == 0){
        return 0;
    }

    return arr[0] + suma_recursiva_dos_auxiliar(n - 1, arr + 1); //Avanzar en el arreglo.
}

int suma_recursiva_dos(int cantidad, ...){
    va_list args;
    va_start(args,cantidad);

    int valores[cantidad];
    for(int i = 0; i < cantidad - 1; i++){
        valores[i] = va_arg(args,int);
    }

    va_end(args);

    return suma_recursiva_dos_auxiliar(cantidad,valores);
}

int main(){
    printf("Suma de cantidades: %d\n",suma(5,5,15,25,35,45));
    printf("Suma de cantidades recursiva: %d\n",suma_recursiva(5,5,15,25,35,45));
    printf("Suma de cantidades recursiva con funcion auxiliar: %d\n",suma_recursiva_dos(20,5,15,25,35,45,55,65,75,85,95,105,115,125,135,145,155,165,175,185,195));
    return 0;
}

