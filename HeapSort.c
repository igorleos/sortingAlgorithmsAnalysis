#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "Analicts.h"

void constroiHeap(int *vetor, int i, int n) {
    int maior, l, r, aux;
    maior = i;
    l = 2*i + 1;
    r = 2*i + 2;

    if (l<n && vetor[l]>vetor[maior]) {
        maior = l;
    }

    if ((r<n) && vetor[r]>vetor[maior]) {
        maior = r;
    }

    if (maior!=i) {
        aux = vetor[i];
        vetor[i] = vetor[maior];
        vetor[maior] = aux;
        constroiHeap(vetor, maior, n);
    }
}

void heapSort(int n, int *vetor, Analicts* analyze) {
    int i, aux;
    for(i = (n/2)-1; i >= 0; i--) {
        constroiHeap(vetor, i, n);
    }
    for(i = n-1; i >= 0; i--) {
        aux = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = aux;
        constroiHeap(vetor, 0, i);
    }
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

//     heapSort(tamanho_vetor, vetor);

//     printf("\n");
//     for(i = 0; i < tamanho_vetor; i++){
//         printf("%d ", vetor[i]);
//     }

//     free (vetor);

//     return 0;
// }
