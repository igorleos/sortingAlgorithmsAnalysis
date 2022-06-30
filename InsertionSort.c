#include<stdio.h>
#include<stdlib.h>
#include "Analytics.h"

void insertionSort(int n, int *vetor, Analytics* analyze) {
    int i, j, chave; 

    for(i=1; i<n ; i++){

        chave = vetor[i];
        j = i -1; 

        while(j>=0 && vetor[i]>chave){

            vetor[j+1] = vetor[j];
            j = j - 1;
        }
        vetor[j+1] = chave; 
    }
}