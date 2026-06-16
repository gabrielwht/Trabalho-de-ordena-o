#include <stdlib.h>
#include "ordena.h"
#include "item.h"

// SELECTION SORT
void selection(Item** V, int n) {
    if (V == NULL) {
        return;
    }
    int i, j, imin;
    Item *T = NULL;
    for (i = 0; i < n - 1; i++) {
        imin = i;
        for (j = i + 1; j < n; j++) {
            if (V[imin]->valor > V[j]->valor) {
                imin = j;
            }
        }
        if (i != imin) {
            T = V[i];
            V[i] = V[imin];
            V[imin] = T;
        }
    }
}

// INSERTION SORT
void insertion(Item** V, int n) {
    long int i, j;
    Item *T = NULL;
    if (V != NULL) {
        for (j = 1; j < n; j++) {
            T = V[j];
            i = j - 1;
            while (i >= 0 && V[i]->valor > T->valor) {
                V[i + 1] = V[i];
                i--;
            }
            V[i + 1] = T;
        }
    }
}

// BUBBLE SORT
void bubblesort(Item** V, int n) {
    if (V == NULL) {
        return;
    }
    int Lsup, Bolha, j;
    Item* Aux = NULL;
    Lsup = n - 1;
    do {
        Bolha = 0;
        for (j = 0; j < Lsup; j++) {
            if (V[j]->valor > V[j + 1]->valor) {
                Aux = V[j];
                V[j] = V[j + 1];
                V[j + 1] = Aux;
                Bolha = j;
            }
        }
        Lsup = Bolha;
    } while (Lsup > 0);
}

// SHELL SORT
void shellsort(Item **V, int n) {
    int i, j, aux = 1;
    Item* T;
    do {
        aux = 3 * aux + 1;
    } while (aux < n);
    do {
        aux /= 3;
        for (i = aux; i < n; i++) {
            T = V[i];
            j = i - aux;
            while (j >= 0 && T->valor < V[j]->valor) {
                V[j + aux] = V[j];
                j -= aux;
            }
            V[j + aux] = T;
        }
    } while (aux > 1);
}

// MERGE SORT
void intercala(Item** A, Item **B, int ini, int meio, int fim) {
    int i = ini, j = meio + 1, k = ini;
    while (i < meio + 1 && j < fim + 1) {
        if (A[i]->valor < A[j]->valor) {
            B[k] = A[i];
            i++; k++;
        } else {
            B[k] = A[j];
            j++; k++;
        }
    }
    while (i < meio + 1) {
        B[k] = A[i];
        k++; i++;
    }
    while (j < fim + 1) {
        B[k] = A[j];
        k++; j++;
    }
    for (k = ini; k < fim + 1; k++) {
        A[k] = B[k];
    }
}

void mergesortRecursivo(Item** A, Item** B, int ini, int fim) {
    int meio;
    if (fim == ini) {
        return;
    } else {
        meio = (ini + fim) / 2;
        mergesortRecursivo(A, B, ini, meio);
        mergesortRecursivo(A, B, meio + 1, fim);
        intercala(A, B, ini, meio, fim);
        return;
    }
}

void mergesort(Item **A, int tam) {
    if (A) {
        Item **B = (Item**) calloc(tam, sizeof(Item*));
        int ini = 0;
        int fim = tam - 1;
        mergesortRecursivo(A, B, ini, fim);
        free(B);
    }
}

// QUICKSORT
void quicksortRecursivo(Item **vetor, int Esq, int Dir) {
    Item *x = NULL, *aux = NULL, *t = NULL;
    int i = 0, j = 0;
    
    if (Dir > Esq) {
        x = vetor[Dir];
        i = Esq;
        j = Dir - 1;
        for (;;) {
            aux = vetor[i];
            while (i < Dir && aux->valor < x->valor) {
                i++;
                aux = vetor[i];
            }
            aux = vetor[j];
            while (j >= Esq && aux->valor > x->valor) {
                j--;
                if(j >= 0)
                    aux = vetor[j];
            }
            if (i >= j) break;
            
            t = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = t;
            i++;
            j--;
        }
        t = vetor[i];
        vetor[i] = vetor[Dir];
        vetor[Dir] = t;
        
        quicksortRecursivo(vetor, Esq, i - 1);
        quicksortRecursivo(vetor, i + 1, Dir);
    }
}

void quicksort(Item **V, int tam) {
    int inicio = 0, fim = tam - 1;
    quicksortRecursivo(V, inicio, fim);
}
