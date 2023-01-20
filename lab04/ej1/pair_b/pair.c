#include "pair.h"
#include <stdlib.h>
#include <assert.h>
pair_t pair_new(int x, int y){
    pair_t p = (pair_t)malloc(sizeof(pair_t));
    p->fst = x;
    p->snd = y;
    assert(p->fst == x);
    assert(p->snd == y);
    return p;
}

int pair_first(pair_t p){
    return p->fst;
}

int pair_second(pair_t p){
    return p->snd;
}

pair_t pair_swapped(pair_t p){
    pair_t q=NULL;
    q = (pair_t)malloc(sizeof(pair_t));
    q->fst = p->snd;
    q->snd = p->fst;
    return q;
}

pair_t pair_destroy(pair_t p){
    free(p);
    return p;
}