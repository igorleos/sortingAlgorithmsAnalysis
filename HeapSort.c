#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "Analytics.h"

void constroiHeap(int *vetor, int i, int n, Analytics*  analyze) {
    int maior, l, r, aux;
    maior = i;
    l = (2*i + 1)-1;
    r = (2*i + 2)-1;

    analyze->comparedTimes+=2;
    if (l<n && vetor[l]>vetor[maior]) {
        maior = l;
    }

    analyze->comparedTimes+=2;
    if ((r<n) && vetor[r]>vetor[maior]) {
        maior = r;
    }

    analyze->comparedTimes++;
    if ( maior!=i) {
        aux = vetor[i];
        vetor[i] = vetor[maior];
        vetor[maior] = aux;

        analyze->swaps+=3;

        constroiHeap(vetor, maior, n, analyze);
    }
}

void heapSort(int n, int *vetor, Analytics* analyze) {
    int i, aux;

    startTimer(analyze);

    for(i = (n/2)-1; i >= 0; i--) {
        analyze->comparedTimes++;
        constroiHeap(vetor, i, n, analyze);
    }
    for(i = n-1; i >= 0; i--) {
        analyze->comparedTimes++;

        aux = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = aux;

        analyze->swaps+=3;

        constroiHeap(vetor, 0, i, analyze);

    }
    finishTimer(analyze);
}


