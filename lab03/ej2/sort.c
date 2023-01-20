/*
  @file sort.c
  @brief sort functions implementation
*/

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "helpers.h"
#include "sort.h"
#include "player.h"
void swap(player_t a[], int x, int y){
    player_t z = a[x];
    a[x] = a[y];
    a[y]= z;
}
bool goes_before(player_t x, player_t y){
    // completar aquí
    if (x.rank > y.rank)
    {
        return false;
        /* code */
    }
    
    return true;
}

bool array_is_sorted(player_t atp[], unsigned int length) {
    unsigned int i = 1u;
    while (i < length && goes_before(atp[i - 1u], atp[i])) {
        i++;
    }
    return (i == length);
}

static unsigned int partition(player_t a[], unsigned int izq, unsigned int der) {
    /* Needs implementation */
    unsigned int ppiv = izq;
    unsigned int i = izq +1;
    unsigned int j = der;
    while (i <= j)
    {
        if (goes_before(a[i], a[ppiv]) )
        {
            i++;
        }
        else if (goes_before(a[ppiv], a[j]) )
        {
            j--;
        }
        else if (goes_before(a[ppiv], a[i]) && goes_before(a[j], a[ppiv]))
        {
            swap(a, i, j);
            i++;
            j--;
        }
    }
    swap(a,ppiv, j);
    ppiv = j;
    return ppiv;
    /* Permutes elements of a[izq..der] and returns pivot such that:
     - izq <= pivot <= der
     - elements in a[izq,pivot) all 'go_before' (according to function goes_before) a[pivot]
     - a[pivot] 'goes_before' all the elements in a(pivot,der]
    */
}

static void quick_sort_rec(player_t a[], unsigned int izq, unsigned int der) {
    /* copiá acá la implementación que hiciste en el ejercicio 3 */
    if (der>izq)
    {   
        
        unsigned int ppiv = partition(a, izq, der);
        
        quick_sort_rec(a, izq, (ppiv== 0u) ? 0u : ppiv - 1u);
   
        quick_sort_rec(a, ppiv+1, der);
        /* code */
    }
}

void quick_sort(player_t a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}

void sort(player_t a[], unsigned int length) {
    // completar aquí
    quick_sort(a, length);
}

