#include<stdio.h>
#include<stdlib.h>
#include "Analytics.h"
#include "VectorDefinitions.h"


void shellSort(int n, int *vetor, Analytics* analyze){
    int h, i, j, chave;
    h = 1;

    startTimer(analyze);

    while(h < n){
        h = 3 * h + 1;
    }
    while(h>=1){
        h=h/3; 
        for(i=h, analyze->comparedTimes++, i<n; i++;){
            chave = vetor[i];
            j = i - h;

            analyze->swaps++;

            while (analyze->comparedTimes+=2 && j>=0 && vetor[j]>chave){
                vetor[j+h] = vetor[i];
                j = j - h;

                analyze->swaps++;

            }
            vetor[j+h] = chave;

            analyze->swaps++;

        }
    }
    finishTimer(analyze);

}
