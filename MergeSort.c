#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "Analytics.h"
#include "VectorDefinitions.h"

void merge(int *vetor, int ini, int meio, int fim, Analytics* analyze) {
    int i = ini, j = meio, k = 0, *w = malloc(fim*sizeof(int));

    while(i < meio && j < fim) {
        analyze->comparedTimes+=2;
        if(analyze->comparedTimes++ && vetor[i] <= vetor[j]) {
            w[k] = vetor[i];
            analyze->swaps++;
            i++;
        }
        else {
            w[k] = vetor[j];
            analyze->swaps++;
            j++;
        }
        k++;
    }

    while(i < meio) {
        analyze->comparedTimes++;
        w[k] = vetor[i];
        analyze->swaps++;
        i++;
        k++;
    }

    while(j < fim) {
        analyze->comparedTimes++;
        w[k] = vetor[j];
        analyze->swaps++;
        j++;
        k++;
    }

    for(i = ini; analyze->comparedTimes++ && i < fim; i++) {
        vetor[i] = w[i-ini];
        analyze->swaps++;
    }

    free(w);
}

void mergeSort(int *vetor, int i, int f, Analytics* analyze) {
    int m;

    analyze->comparedTimes++;
    if(i<f-1) {
        m = (i+f)/2;
        mergeSort(vetor, i, m, analyze);
        mergeSort(vetor, m, f, analyze);
        merge(vetor, i, m, f, analyze);
    }
}

void mergeSortOrder(int n, int *vetor, Analytics* analyze) {
    startTimer(analyze);

    mergeSort(vetor, 0, n, analyze);

    finishTimer(analyze);
}
