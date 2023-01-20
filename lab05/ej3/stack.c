#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "stack.h"
#define CAPACITY_INIT 7

struct _s_stack {
    stack_elem *elems;      // Arreglo de elementos
    unsigned int size;      // Cantidad de elementos en la pila
    unsigned int capacity;  // Capacidad actual del arreglo elems
};

bool invrep(stack s){
    
    const bool valid_size = s->size <= s->capacity;

    const bool capacity_is_valid = s->capacity > 0 ;

    bool is_not_null = s != NULL;

    return capacity_is_valid  && valid_size && is_not_null;
}

stack stack_empty(){

    stack p=NULL;

    p=malloc(sizeof(struct _s_stack));

    if(p==NULL){
        printf("No hay espacio suficiente");
        exit(EXIT_FAILURE);
    }
    
    p->capacity = CAPACITY_INIT;
    // p->elems = calloc(p->capacity , sizeof(stack_elem));
   
    // if(p->elems==NULL){
    //     printf("No hay espacio suficiente\n");
    //     exit(EXIT_FAILURE);
    // }

    p->size = 0;
    return p;
}
stack stack_push(stack s, stack_elem e){
    assert(invrep(s));
    if (s->elems ==NULL)
    {
        s->elems = calloc(s->capacity, sizeof(stack_elem));
    }else if(s->capacity == s->size){
        s->elems = realloc(s->elems,2*s->capacity*sizeof(stack_elem));
        if(s->elems==NULL){
            printf("No hay suficiente espacio disponible\n");
            exit(EXIT_FAILURE);
        }
        s->capacity*=2;
    }
    s->elems[s->size]= e;
    s->size ++;
    assert(invrep(s));
    return s;
}

stack stack_pop(stack s){
    assert(invrep(s));
    if (s->size != 0) {
      if (s->size == 1) {
        free(s->elems);
        s->elems = NULL;
      }
      s->size--;
    }
    assert(invrep(s));
    return s;
}
unsigned int stack_size(stack s){
    assert(invrep(s));
    return s->size;
}

stack_elem stack_top(stack s){
    assert(invrep(s));
    assert(s->size !=0);
    return s->elems[s->size-1]; //o s->elems[0] ??
}

bool stack_is_empty(stack s){
    assert(invrep(s));
    return s->size ==0;
}

stack_elem *stack_to_array(stack s){
    assert(invrep(s));
    
    stack_elem *array = NULL;
    array = calloc(s->size, sizeof(stack_elem));
    unsigned int i = 0;

    while(i < s->size){
        array[i] = s->elems[i];
        i++;
    }

    assert(invrep(s));

    return array;
}

stack stack_destroy(stack s){
    assert(invrep(s));
    free(s->elems);
    s->elems = NULL;
    s->size=0;
    free(s);
    s=NULL;
    return s;
}