#include<stdio.h>
#include<stdlib.h>
#include "Analicts.h"

void shellSort(int n, int *vetor, Analicts* analyze){
    int h, i, j, chave;
    h = 1;
    while(h < n){
        h = 3 * h + 1;
    }
    while(h>=1){
        h=h/3; 
        for(i=h, i<n; i++;){
            chave = vetor[i];
            j = i - h;
            while (j>=0 && vetor[j]>chave){
                vetor[j+h] = vetor[i];
                j = j - h;
            }
            vetor[j+h] = chave;
        }
    }
}