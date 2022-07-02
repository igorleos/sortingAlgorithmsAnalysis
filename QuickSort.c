#include<stdio.h>
#include<stdlib.h>
#include "Analytics.h"

void quickSort(int *vector, int left, int right, Analytics* analyze) {
    int i, j, x, y;
    i = left;
    j = right;
    x = vector[(left + right) / 2];

    analyze->swaps++;

    while(i <= j) {
        analyze->comparedTimes++;
        
        while(vector[i] < x && i < right) {
            analyze->comparedTimes+=2;

            i++;
        }
        analyze->comparedTimes++;


        while(vector[j] > x && j > left) {
            analyze->comparedTimes+=2;
            
            j--;
        }
        analyze->comparedTimes++;

        analyze->comparedTimes++;
        if(i <= j) {
            y = vector[i];
            vector[i] = vector[j];
            vector[j] = y;

            analyze->swaps+=3;


            i++;
            j--;
        }
    }
    analyze->comparedTimes++;

    analyze->comparedTimes++;
    if(j > left) {
        quickSort(vector, left, j, analyze);
    }

    analyze->comparedTimes++;
    if(i < right) {
        quickSort(vector, i, right, analyze);
    }
}

void quickSortOrder(int n, int *vetor, Analytics* analyze) {
    startTimer(analyze);

    quickSort(vetor, 0, n - 1, analyze);
    
    finishTimer(analyze);
}