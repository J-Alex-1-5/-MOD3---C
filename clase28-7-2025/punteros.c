#include <studio.h>

int main(){
    int x = 10;
    int *ptr = &x; // Pointer to x

    printf("Value of x: %d\n", x);
    printf("Address of x: %p\n", (void*)&x);
    return 0;
}