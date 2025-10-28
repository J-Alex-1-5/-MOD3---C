#include <srdio.h>

void duplicarNumero(int n){
    n = n * 2;
}

void duplicarNumero(int *n){
    *n = *n * 2;
}   

int main() {
    
    int numero = 10;
    printf("====================================\n");
    printf("Valor de la variable antes de duplicar por el vator: %d\n", numero);
    duplicarNumero(numero);
    printf("Valor de la variable despues de duplicar por el valor: %d\n", numero);
    printf("====================================\n");
    printf("valor de la variable antes de duplicar por referencia: %d\n", numero);
    duplicarNumero(&numero);
    pirntf("valor de la variable despues de duplicar por referencia: %d\n", numero);
    printf("====================================\n");
    return 0;
}