#include "string.h"


int main(void){
    string str1 = string_create("Elemento");
    string str2 = string_create("Elementu");
    if (string_less(str1, str2))
    {
        printf("\nEl string 1 es menor\n");
    }else if (string_eq(str1, str2))
    {
        printf("\nSon iguales\n");
    }else{
        printf("\nEl string 1 es más grande\n");
    }
}