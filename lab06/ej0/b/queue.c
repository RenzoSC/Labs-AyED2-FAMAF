#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include "queue.h"

struct s_queue {
    /*
     * COMPLETAR para el apartado b)
     */
    struct s_node *last;
    unsigned int length;
    struct s_node *first;
};

struct s_node {
    queue_elem elem;
    struct s_node *next;
};

static struct s_node *
create_node(queue_elem e) {
    struct s_node *new_node=malloc(sizeof(struct s_node));
    assert(new_node!=NULL);
    new_node->elem = e;
    new_node->next = NULL;
    return new_node;
}

static struct s_node *
destroy_node(struct s_node *node) {
    node->next=NULL;
    free(node);
    node=NULL;
    return node;
}


static bool
invrep(queue q) {
    return q != NULL;
}

queue queue_empty(void) {
    queue q=NULL;
    /*
     * COMPLETAR
     *
     */
    q = malloc(sizeof(struct s_queue));
    if(q==NULL){
        printf("No hay espacio suficiente");
        exit(EXIT_FAILURE);
    }
    q->first=NULL;
    q->length =0;
    q->last=NULL;
    assert(invrep(q) && queue_is_empty(q));
    return q;
}

queue queue_enqueue(queue q, queue_elem e) {
    assert(invrep(q));
    struct s_node *new_node = create_node(e);
    if (queue_is_empty(q)) {
        q->first = q->last;
    } else {
        /*
        * COMPLETAR
        *
        */
        struct s_node *puntero =NULL;
        puntero = q->last;
        puntero->next= new_node;
        puntero = NULL;
        // puntero = q->first;
        // while (puntero->next!=NULL)
        // {
        //     puntero = puntero->next;
        // }
        // puntero->next = new_node;
    }
    q->last= new_node;
    q->length ++;
    assert(invrep(q) && !queue_is_empty(q));
    return q;
}

bool queue_is_empty(queue q) {
    assert(invrep(q));
    return q->first == NULL && q->length==0 && q->last ==NULL;
}

queue_elem queue_first(queue q) {
    assert(invrep(q) && !queue_is_empty(q));
    return q->first->elem;
}
unsigned int queue_size(queue q) {
    assert(invrep(q));
    return q->length;
}

queue queue_dequeue(queue q) {
    assert(invrep(q) && !queue_is_empty(q));
    struct s_node * killme=q->first;
    if(q->length==1){
        q->last = q->last->next;
    }
    q->first = q->first->next;
    killme = destroy_node(killme);
    q->length --;
    assert(invrep(q));
    return q;

}

queue queue_destroy(queue q) {
    assert(invrep(q));
    struct s_node *node=q->first;
    while (node != NULL) {
        struct s_node *killme=node;
        node = node->next;
        killme = destroy_node(killme);
    }
    free(q);
    q->first= NULL;
    q->length = 0;
    q->last= NULL;
    q = NULL;
    assert(q == NULL);
    return q;
}

