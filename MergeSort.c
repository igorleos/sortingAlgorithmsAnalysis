#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "Analytics.h"
#include "VectorDefinitions.h"

void merge(int *vetor, int ini, int meio, int fim, Analytics* analyze) {
    int i = ini, j = meio, k = 0, *w = malloc(fim*sizeof(int));
    
    while(analyze->comparedTimes += 2 && i < meio && j < fim) {
        if(analyze->comparedTimes ++ && vetor[i] <= vetor[j]) {
            w[k] = vetor[i];
            analyze->swaps ++; 
            i++;
        }
        else {
            w[k] = vetor[j];
            analyze->swaps ++; 
            j++;
        }
        k++;
    }

    while(analyze->comparedTimes++ && i < meio) {
        w[k] = vetor[i];
        i++;
        k++;
    }

    while(analyze->comparedTimes++ && j < fim) {
        w[k] = vetor[j];
        j++;
        k++;
    }

    for(i = ini; analyze->comparedTimes++ && i < fim; i++) {
        vetor[i] = w[i-ini];
    }

    free(w);
}

void mergeSort(int *vetor, int i, int f, Analytics* analyze) {
    int m;
    if(i<f-1) {
        m = (i+f)/2;
        mergeSort(vetor, i, m, analyze);
        mergeSort(vetor, m, f, analyze);
        merge(vetor, i, m, f, analyze);
    }
}

void mergeSortOrder(int n, int *vetor, Analytics* analyze) {
    mergeSort(vetor, 0, n, analyze);
}

int main() {
    testSorting(4,1);
    return 0;
}
