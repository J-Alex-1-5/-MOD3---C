#include <stdio.h>  
#include <stdbool.h>

int main (){
    // for: se usa cuando se conoce cuantas veces se repetirea
    for (int i = 0; i < 5; i++) {
        printf("Iteración %d\n", i);
    }

    // for _ in range(5): # pyton
    //for (int i = 0; i < 5; i++) # C

    int i = 0, j = 0;
    while(i < 5) {
        printf("Iteración %d\n", i);
        i++;
    }   

    //whuile j < 5: # python
    //while (j < 5) # C

    int k = 0;
    do {
        printf("Iteración %d\n", k);
        k++;
    } while (k < 5);

    return 0;
}