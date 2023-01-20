#include <stdlib.h>
#include <assert.h>
#include "stack.h"
#include <stdio.h> 
typedef struct _s_stack
{
    stack_elem elem;
    struct _s_stack *next;
    unsigned int size;
} _s_stack;

stack stack_empty(void){
    stack p = NULL;
    return p;
}

stack stack_push(stack s, stack_elem e){
    stack q = (stack)malloc(sizeof (_s_stack));
    q->elem = e;
    q->next = s;
    q->size = s ? s->size + 1 : 1;
    return q;
}

stack stack_pop(stack s){
    s = s->next;
    if (s) s->size--;
    return s;
}

unsigned int stack_size(stack s){
    return s? s->size:0;
}

stack_elem stack_top(stack s){
    stack_elem elem = s->elem;
    return elem;
}

bool stack_is_empty(stack s){
    return s ==NULL;
}

stack_elem *stack_to_array(stack s){
    unsigned int length = stack_size(s);
    stack_elem *array;
    array= (stack_elem *)malloc(length * sizeof(stack_elem));
    for (unsigned int i = 0; i < length; i++)
    {
        array[length-1-i]= stack_top(s);
        
        s = stack_pop(s);
    }
    return array;
}

stack stack_destroy(stack s){
    free(s);
    return s;
}