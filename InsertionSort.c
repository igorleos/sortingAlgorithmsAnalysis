#include<stdio.h>
#include<stdlib.h>
#include "Analytics.h"
#include "VectorDefinitions.h"


void insertionSort(int n, int *vetor, Analytics* analyze) {
    int i, j, chave; 

    startTimer(analyze);

    for( i=1; analyze->comparedTimes++, i<n ; i++){

        chave = vetor[i];
        j = i -1; 

        analyze->swaps++;

        while(analyze->comparedTimes+=2 && j>=0 && vetor[i]>chave){

            vetor[j+1] = vetor[j];
            j = j - 1;

            analyze->swaps++;

        }
        vetor[j+1] = chave; 

        analyze->swaps++;

    }
    finishTimer(analyze);

}

int main(){
    testSorting(1,2);
    return 0; 
}