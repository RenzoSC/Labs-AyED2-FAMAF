#ifndef _LIST_H
#define _LIST_H
#include <stdbool.h>
typedef int list_elem;

typedef struct Node
{
    list_elem elem;
    struct Node *next;
} Node;

typedef Node *list;

list empty(void);
/*crea lista vacia*/

bool is_empty(list l);
/*Verifica que esté vacía*/

list add_left(list l, list_elem elem);
/*Agrega elemento al comienzo*/

list_elem head(list l);
/*Retorna el primer elemento de la lista*/

list tail(list l);
/*Elimina el primer elemento de la lista*/

list add_right(list l, list_elem elem);
/*Agrega elemento al final de la lista*/

int length(list l);
/*Devuelve la longitud de la lista*/

list concat(list lista1, list lista2);
/*Concatena 2 listas*/

list_elem index(list l, int index);
/*devuelve el enesimo elemento de la lista*/

list take(list l, int n);
/*Devuelve una lista con los n primeros elementos*/

list drop(list l, int n);
/*Elimina los n priemros elementos*/

list copy(list l);
/*Copia la lista*/

void destroy(list l);
/*Borra la memoria*/
#endif