#include<stdio.h>
#include<stdlib.h>
#include "Analytics.h"


void bubbleSort(int n, int *vetor, Analytics* analyze){
    int i, j, aux;
    startTimer(analyze);
    for(i=1; i<n; i++){
        analyze->comparedTimes++;
        if(analyze->comparedTimes<0){
            printf("%lld", analyze->comparedTimes);
        }
        else if(analyze->comparedTimes>0){
            printf("");
        }
        for(j=0;  j<n-1; j++){
            analyze->comparedTimes+=2;

            if(vetor[j]>vetor[j+1] ){
                aux = vetor[j+1];
                vetor[j+1] = vetor[j];
                vetor[j] = aux;

                analyze->swaps+=3;
            }
        }
    }
    finishTimer(analyze);
}
