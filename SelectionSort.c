#include<stdio.h>
#include<stdlib.h>
#include "Analytics.h"
#include "VectorDefinitions.h"

void selectionSort(int n, int *vetor, Analytics* analyze) {
    startTimer(analyze);
    
    int i, j, aux, min;

    for(i = 0; i < n-1; i++) {
        analyze->comparedTimes++;

        min = i;
        for(j = i+1; j < n; j++) {

            analyze->comparedTimes+=2;
            if(vetor[j] < vetor[min])  {
                min = j;
            }
        }
        analyze->comparedTimes++;


        aux = vetor[min];
        vetor[min] = vetor[i];
        vetor[i] = aux;

        analyze->swaps+=3;
    }
    analyze->comparedTimes++;

    finishTimer(analyze);
}