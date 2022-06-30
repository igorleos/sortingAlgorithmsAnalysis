#include<stdio.h>
#include<stdlib.h>
#include "Analicts.h"

void selectionSort(int n, int *vetor, Analicts* analyze){
    int i, j ,aux, min; 

    for(i=0; i < n; i++){

        min = i; 
        for(j = i+1; j<n; j++) {

            if(vetor[j] < vetor[min]) {
                min = j;
            }
        }
        
        aux = vetor[min];
        vetor[min] = vetor[i];
        vetor[i] = aux; 
    }
}