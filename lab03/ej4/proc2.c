#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int *y) {
    // Completar aqui
    if (x>=0)
    {
        *y=x;
    }else{
        *y=-x;
    }
    
}

int main(void) {
    // Completar aqui
    int a, *res,d;
    res  =&d;
    a=-98;
    d=a;
    absolute(d,res);
    printf("%i\n", *res);
    res=0;
    return EXIT_SUCCESS;
}