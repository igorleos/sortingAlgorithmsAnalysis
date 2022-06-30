#include<stdio.h>
#include<stdlib.h>
#include "Analicts.h"

void bubbleSort(int n, int *vetor, Analicts* analyze){
    int i, j, aux;
    for(i=1; i<n; i++){

        for(j=0; j<n-1; j++){
            
            if(vetor[j]>vetor[j+1]){

                aux = vetor[j+1];
                vetor[j+1] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
}