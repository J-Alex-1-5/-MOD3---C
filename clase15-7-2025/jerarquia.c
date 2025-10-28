#include <stdio.h>
/*
Jerarquía de archivos en C
nivel           operadores                         tipo
1               ()                                 agrupacion
2                ++, --, +, -, ! sizeof           aritméticos
3                * / %                            aritméticos
4                 + -                               aritméticos
5                < > <= >= == !=                   igualdad y relación
6                   && ||                           lógicos
7                 ? :                                ternario
8              = += -= *= /= %= &= |= ^= <<= >>=    asignación

*/

int main() {

    int resultado = 5 + 2 * 3;
    printf("Resultado de 5 + 2 * 3: %d\n", resultado);
    return 0;
}