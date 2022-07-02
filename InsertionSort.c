#include<stdio.h>
#include<stdlib.h>
#include "Analytics.h"
#include "VectorDefinitions.h"


void insertionSort(int n, int *vetor, Analytics* analyze) {
    int i, j, chave; 

    startTimer(analyze);

    for( i=1; i<n ; i++){
        analyze->comparedTimes++;

        chave = vetor[i];
        j = i -1; 

        analyze->swaps++;

        while( j>=0 && vetor[j]>chave){
            analyze->comparedTimes+=2;

            vetor[j+1] = vetor[j];
            j = j - 1;

            analyze->swaps++;

        }
        vetor[j+1] = chave; 

        analyze->swaps++;

    }
    
    finishTimer(analyze);

}
