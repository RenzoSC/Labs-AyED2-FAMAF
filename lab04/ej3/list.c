#include "list.h"
#include <stdlib.h>
#include <stdio.h>



list empty(void){
    list l= NULL;
    return l;
}

bool is_empty(list l){
    return l==NULL;
}

list add_left(list l, list_elem elem){
    list q = (list)malloc(sizeof(list));
    q->elem= elem;
    q->next= l;
    return q;
}

list_elem head(list l){
    list_elem x = l->elem;
    return x;
}

list tail(list l){
    list q = (list)malloc(sizeof(list));
    q =l;
    l =l->next;
    free(q);
    
    return l;
}

list add_right(list l, list_elem elem){
    list p,q;
    q = (list)malloc(sizeof(list));
    q->elem = elem;
    q->next = NULL;
    if (!is_empty(l))
    {
        p=l;
        while (p->next !=NULL)
        {
            p= p->next;
        }
        p->next = q;
    }
    destroy(q);
    return p;
}

int length(list l){
    int n=0;
    list q;
    q = (list)malloc(sizeof(list));
    q=l;
    while (q != NULL)
    {
        q= q->next;
        n++;
    }
    destroy(q);
    return n;
}

list concat(list lista1, list lista2){
    list q = empty();
    list p = empty();
    q = lista1;
    while (q->next !=NULL)
    {
        p->elem = q->elem;
        p->next = q->next;
        q = q->next;
    }
    p->next = lista2;
    destroy(q);
    return p;
}

list_elem index(list l, int index){
    list q = empty();
    q = l;
    while (index>0)
    {
        q = q->next;
        index --;
    }
    return q->elem;
}

list take(list l, int n){
    list q = empty();
    list p = empty();
    q = l;
    while (n>0)
    {
        p->elem = q->elem;
        p->next = q->next;
        q = q->next;
        n--;
    }
    p->next = NULL;
    destroy(q);
    return p;
}

list drop(list l, int n){
    list q = empty();
    list p = empty();
    q=l;
    while (n>0)
    {
        p= q->next;
        n--;
    }
    destroy(q);
    return p;
}
list copy(list l){
    list q=empty();
    q = l;
    return q;
}

void destroy(list l){
    free(l);
}
