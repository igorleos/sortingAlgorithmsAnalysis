#include <time.h>
#include<stdio.h>
#include<stdlib.h>
#include "Analytics.h"
#include "VectorDefinitions.h"

void startTimer(Analytics* analyze){
    analyze->clockTime = clock();
}

void finishTimer(Analytics* analyze){
    analyze->clockTime = clock() - analyze->clockTime;
}

void prepareCSVFile(){
    FILE *fpt;
    fpt = fopen("AnalyticsData.csv", "w+");
    fprintf(fpt,"Tamanho do vetor;Algoritmo usado;Forma de entrada;Comparacoes realizadas; Chaves trocadas; Tempo total\n");
    fclose(fpt);
}


void writeAnalyticsDataCSV(Analytics* analyze, const void * _vectorDefinitions){
    VectorDefinitions* vectorDefinitions = ((VectorDefinitions *)_vectorDefinitions);

    FILE *fpt;
    fpt = fopen("AnalyticsData.csv", "a");
    char *algName = malloc(20*sizeof(char));
    char *entryFormatName = malloc(20*sizeof(char));
    
    double totalTime = ((double)analyze->clockTime)/CLOCKS_PER_SEC;

    getAlgName(algName, vectorDefinitions);
    getEntryFormatName(entryFormatName, vectorDefinitions);

    fprintf(fpt,"%ld;%s;%s;%lld;%lld;%f\n", vectorDefinitions->vectorSize, algName, entryFormatName, analyze->comparedTimes, analyze->swaps, totalTime);

    fclose(fpt);
}
