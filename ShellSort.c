#include<stdio.h>
#include<stdlib.h>
#include "Analytics.h"
#include "VectorDefinitions.h"

void shellSort(int n, int *vetor, Analytics* analyze) {
    startTimer(analyze);

    int h, i, j, chave;
    h = 1;
    while (h < n) {
        analyze->comparedTimes++;
        h = 3 * h + 1;
    }
    analyze->comparedTimes++;

    while(h>=1) {
        analyze->comparedTimes++;
        
        h=h/3;
        for(i = h; i < n; i++) {
            analyze->comparedTimes++;
            
            chave = vetor[i];

            analyze->swaps++;

            j = i - h;
            while(j>=0 && vetor[j]>chave) {
                analyze->comparedTimes+=2;
                
                vetor[j+h] = vetor[j];

                analyze->swaps++;

                j = j - h;
            }
            analyze->comparedTimes++;

            vetor[j+h] = chave;

            analyze->swaps++;
        }
        analyze->comparedTimes++;

    }
    analyze->comparedTimes++;

    finishTimer(analyze);
}

