#ifndef ORDENA_H
#define ORDENA_H

#include "item.h"

//algoritmos de ordenação
void selection(Item** V, int n);
void insertion(Item** V, int n);
void bubblesort(Item** V, int n);
void shellsort(Item** V, int n);
void mergesort(Item** A, int tam);
void quicksort(Item** V, int tam);

#endif