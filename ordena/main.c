#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "item.h"
#include "ordena.h"

//Cria vetor usando rand
Item** criaVetor(int tam) {

    Item** V = (Item**) malloc(tam * sizeof(Item*));

    if (V == NULL) {

        printf("Erro de alocação\n");
        exit(1);

    }
    
    for(int i = 0; i < tam; i++) {

        V[i] = (Item*) malloc(sizeof(Item)); // Valor = (rand() % tam) + 1
        V[i]->valor = (rand() % tam) + 1; // O campo msg pode ficar vazio para esse teste de performance

    }

    return V;

}

// Copia o vetor
Item** copiaVetor(Item** original, int tam) {

    Item** copia = (Item**) malloc(tam * sizeof(Item*));

    for(int i = 0; i < tam; i++) {

        // Copiamos apenas as referências (ponteiros).
        // Isso é o suficiente pois os algoritmos apenas trocam os ponteiros de lugar.
        copia[i] = original[i];

    }

    return copia;

}

// Liberar memória e evitar memory leaks
void liberaItens(Item** V, int tam) {

    for(int i = 0; i < tam; i++) {

        free(V[i]);

    }

    free(V);

}

int main() {

    // Inicializa a semente randômica
    srand((unsigned)time(NULL)); 
    
    int tamanhos[] = {10000, 100000, 200000};
    int num_tamanhos = 3;
    
    printf("===========================\n");
    printf("   BATERIA DE BENCHMARKS\n");
    printf("===========================\n\n");
    
    for(int t = 0; t < num_tamanhos; t++) {
        int tam = tamanhos[t];
        printf("------------------------\n");
        printf(" Teste com %d registros\n", tam);
        printf("------------------------\n");
        
        // Cria o vetor embaralhado original para esta rodada
        Item** original = criaVetor(tam);
        Item** copia;
        clock_t inicio, fim;
        double tempo_gasto;
        
        // Selection Sort
        copia = copiaVetor(original, tam);
        inicio = clock();
        selection(copia, tam);
        fim = clock();
        tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        printf("Selection Sort : %f segundos\n", tempo_gasto);
        free(copia);
        
        // Insertion Sort
        copia = copiaVetor(original, tam);
        inicio = clock();
        insertion(copia, tam);
        fim = clock();
        tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        printf("Insertion Sort : %f segundos\n", tempo_gasto);
        free(copia);
        
        // Bubble Sort
        copia = copiaVetor(original, tam);
        inicio = clock();
        bubblesort(copia, tam);
        fim = clock();
        tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        printf("Bubble Sort    : %f segundos\n", tempo_gasto);
        free(copia);
        
        // Shell Sort
        copia = copiaVetor(original, tam);
        inicio = clock();
        shellsort(copia, tam);
        fim = clock();
        tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        printf("Shell Sort     : %f segundos\n", tempo_gasto);
        free(copia);
        
        // Merge Sort
        copia = copiaVetor(original, tam);
        inicio = clock();
        mergesort(copia, tam);
        fim = clock();
        tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        printf("Merge Sort     : %f segundos\n", tempo_gasto);
        free(copia);
        
        // Quick Sort
        copia = copiaVetor(original, tam);
        inicio = clock();
        quicksort(copia, tam);
        fim = clock();
        tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        printf("Quick Sort     : %f segundos\n", tempo_gasto);
        free(copia);
        
        // Limpeza final da memória deste vetor
        liberaItens(original, tam);
        printf("\n");
    }

    return 0;

}

/*
===========================
   BATERIA DE BENCHMARKS
===========================

------------------------------
 Testando com 10000 registros
------------------------------
Selection Sort : 0.107000 segundos
Insertion Sort : 0.076000 segundos
Bubble Sort    : 0.248000 segundos
Shell Sort     : 0.003000 segundos
Merge Sort     : 0.002000 segundos
Quick Sort     : 0.001000 segundos

-------------------------------
 Testando com 100000 registros
-------------------------------
Selection Sort : 90.725000 segundos
Insertion Sort : 36.834000 segundos
Bubble Sort    : 118.037000 segundos
Shell Sort     : 0.115000 segundos
Merge Sort     : 0.031000 segundos
Quick Sort     : 0.022000 segundos

-------------------------------
 Testando com 200000 registros
-------------------------------
Selection Sort : 301.090000 segundos
Insertion Sort : 182.544000 segundos
Bubble Sort    : 500.627000 segundos
Shell Sort     : 0.209000 segundos
Merge Sort     : 0.063000 segundos
Quick Sort     : 0.049000 segundos




ALGORITMO       | MELHOR CASO     | CASO MÉDIO      | PIOR CASO
----------------|-----------------|-----------------|---------------------------
Selection Sort  | O(n^2)          | O(n^2)          | O(n^2)
Insertion Sort  | O(n)            | O(n^2)          | O(n^2)
Bubble Sort     | O(n)            | O(n^2)          | O(n^2)
Shell Sort      | O(n log n)      | O(n^1.5)        | O(n^2)
Merge Sort      | O(n log n)      | O(n log n)      | O(n log n)
Quick Sort      | O(n log n)      | O(n log n)      | O(n^2)
--------------------------------------------------------------------------------

*/