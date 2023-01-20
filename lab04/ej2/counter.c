#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

#include "counter.h"

struct _counter {
    unsigned int count;
};

counter counter_init(void) {
/*
    Needs implementation.
*/
    counter c=NULL;
    c = (counter)malloc(sizeof(counter));
    c->count =0;
    assert(counter_is_init(c));
    return c;
}

void counter_inc(counter c) {
/*
    Needs implementation.
*/
    c->count ++;
}

bool counter_is_init(counter c) {
/*
    Needs implementation.
*/
    return c->count == 0;
}

void counter_dec(counter c) {
/*
    Needs implementation.
*/
    assert(!counter_is_init(c));
    c->count --;
}

counter counter_copy(counter c) {
/*
    Needs implementation.
*/
    counter d= NULL;
    d = (counter)malloc(sizeof(counter));
    d = c;
    return d;
}

void counter_destroy(counter c) {
/*
   Needs implementation.
*/
    free(c);
}
