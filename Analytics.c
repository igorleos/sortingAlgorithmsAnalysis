#include <time.h>
#include<stdio.h>
#include<stdlib.h>
#include "Analytics.h"

void startTimer(Analytics* analyze){
    analyze->clockTime = clock();
}

void finishTimer(Analytics* analyze){
    analyze->clockTime = clock() - analyze->clockTime;
}

void printAnalyticsData(Analytics* analyze){
    double totalTime = ((double)analyze->clockTime)/CLOCKS_PER_SEC;
    printf("\nTempo total : %f segundos\n", totalTime);
    printf("Total de comparacoes : %d\n", analyze->comparedTimes);
    printf("Total de trocas : %d\n\n", analyze->swaps);
}
