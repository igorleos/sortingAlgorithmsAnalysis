#include<stdio.h>
#include<stdlib.h>
#include "Analytics.h"
#include "VectorDefinitions.h"


void selectionSort(int n, int *vetor, Analytics* analyze){
    int i, j ,aux, min; 

    startTimer(analyze);

    for(i=0; analyze->comparedTimes++,i < n; i++){

        min = i; 
        for(j = i+1; analyze->comparedTimes++, j<n; j++) {

            if(analyze->comparedTimes+=2 && vetor[j] < vetor[min]) {
                min = j;
            }
        }
        
        aux = vetor[min];
        vetor[min] = vetor[i];
        vetor[i] = aux; 

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