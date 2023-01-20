#include "pair.h"
#include <stdlib.h>
#include <assert.h>
pair_t pair_new(int x, int y){
    pair_t resultado;
    resultado.fst = x;
    resultado.snd = y;

    assert(resultado.fst == x);
    assert(resultado.snd == y);

    return resultado;
}

int pair_first(pair_t p){
    return p.fst;
}

int pair_second(pair_t p){
    return p.snd;
}

pair_t pair_swapped(pair_t p){
    pair_t resultado = {p.snd, p.fst};
    assert(resultado.fst == p.snd);
    assert(resultado.snd == p.fst);
    return resultado;
}

pair_t pair_destroy(pair_t p){
    //free(p); //no pedimos memoria, no somos dueno de la memoria entonces no podeos liberar
    return p;
}