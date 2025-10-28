#include <stdio.h>
#include <stdarg.h>

// Función auxiliar recursiva que encuentra el máximo en un arreglo
int maximo_interno(int cantidad, int arr[]) {
    if (cantidad == 1) {
        return arr[0]; // Caso base: solo un elemento
    }

    int max_restante = maximo_interno(cantidad - 1, arr + 1); // Avanza en el arreglo
    return (arr[0] > max_restante) ? arr[0] : max_restante;   // Compara actual con el resto
}

// Función principal que recibe parámetros variables
int maximo_recursivo(int cantidad, ...) {
    va_list args;
    va_start(args, cantidad);

    int valores[cantidad]; // Arreglo temporal para guardar los argumentos
    for (int i = 0; i < cantidad; i++) {
        valores[i] = va_arg(args, int); // Extrae cada entero
    }

    va_end(args);
    return maximo_interno(cantidad, valores); // Llama a la función recursiva auxiliar
}

// Función principal para probar el código
int main() {
    printf("Maximo de 3 numeros: %d\n", maximo_recursivo(3, 10, 25, 15));
    printf("Maximo de 5 numeros: %d\n", maximo_recursivo(5, 10, 25, 15, 35, 5));
    printf("Maximo de 2 numeros: %d\n", maximo_recursivo(2, 10, 25));
    return 0;
}