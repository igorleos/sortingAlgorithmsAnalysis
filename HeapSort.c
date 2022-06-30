#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "Analytics.h"
#include "VectorDefinitions.h"

void constroiHeap(int *vetor, int i, int n, Analytics*  analyze) {
    int maior, l, r, aux;
    maior = i;
    l = 2*i + 1;
    r = 2*i + 2;

    if (analyze->comparedTimes+=2 && l<n && vetor[l]>vetor[maior]) {
        maior = l;
    }

    if (analyze->comparedTimes+=2 && (r<n) && vetor[r]>vetor[maior]) {
        maior = r;
    }

    if (analyze->comparedTimes+=2 && maior!=i) {
        aux = vetor[i];
        vetor[i] = vetor[maior];
        vetor[maior] = aux;
        constroiHeap(vetor, maior, n, analyze);

        analyze->swaps++;
        analyze->swaps++;   
        analyze->swaps++;
    }
}

void heapSort(int n, int *vetor, Analytics* analyze) {
    int i, aux;
    startTimer(analyze);
    for(i = (n/2)-1; analyze->comparedTimes+=2,i >= 0; i--) {
        constroiHeap(vetor, i, n, analyze);
    }
    for(i = n-1; analyze->comparedTimes+=2, i >= 0; i--) {
        aux = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = aux;
        constroiHeap(vetor, 0, i, analyze);

        analyze->swaps++;
        analyze->swaps++;
        analyze->swaps++;
    }
    finishTimer(analyze);
}


int main(){
    testSorting(1,2);
    return 0; 
}