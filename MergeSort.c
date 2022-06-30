#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "Analicts.h"

void merge(int *vetor, int ini, int meio, int fim) {
    int i = ini, j = meio, k = 0, *w = malloc(fim*sizeof(int));

    while(i < meio && j < fim) {
        if(vetor[i] <= vetor[j]) {
            w[k] = vetor[i];
            i++;
        }
        else {
            w[k] = vetor[j];
            j++;
        }
        k++;
    }

    while(i < meio) {
        w[k] = vetor[i];
        i++;
        k++;
    }

    while(j < fim) {
        w[k] = vetor[j];
        j++;
        k++;
    }

    for(i = ini; i < fim; i++) {
        vetor[i] = w[i-ini];
    }

    free(w);
}

void mergesort(int *vetor, int i, int f) {
    int m;
    if(i<f-1) {
        m = (i+f)/2;
        mergesort(vetor, i, m);
        mergesort(vetor, m, f);
        merge(vetor, i, m, f);
    }
}

void mergeSortOrder(int n, int *vetor, Analicts* analyze) {
    mergesort(vetor, 0, n);
}

// int main() {
//     int i, *vetor;

//     srand(0);

//     vetor = malloc(tamanho_vetor*sizeof(int));

//     for (i = 0; i < tamanho_vetor; i++) {
//         vetor[i] = (rand() % valor_max) + valor_min;
//     }

//     for(i = 0; i < tamanho_vetor; i++){
//         printf("%d ", vetor[i]);
//     }

//     mergesortOrder(tamanho_vetor, vetor);

//     printf("\n");
//     for(i = 0; i < tamanho_vetor; i++){
//         printf("%d ", vetor[i]);
//     }

//     free (vetor);

//     return 0;
// }
