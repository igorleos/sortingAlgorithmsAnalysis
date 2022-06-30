#include<stdio.h>
#include<stdlib.h>
#include "Analytics.h"
#include "VectorDefinitions.h"


void bubbleSort(int n, int *vetor, Analytics* analyze){
    int i, j, aux;
    startTimer(analyze);
    for(i=1; analyze->comparedTimes++, i<n; i++){

        for(j=0; analyze->comparedTimes++, j<n-1; j++){
            
            if(vetor[j]>vetor[j+1] && analyze->comparedTimes++){

                aux = vetor[j+1];
                vetor[j+1] = vetor[j];
                vetor[j] = aux;

                analyze->swaps++;
                analyze->swaps++;
                analyze->swaps++;
            }
        }
    }
    finishTimer(analyze);
}

