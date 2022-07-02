#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "Analytics.h"
#include "VectorDefinitions.h"
#include "BubbleSort.h"
#include "HeapSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "SelectionSort.h"
#include "ShellSort.h"

void buildVector(int *vector, VectorDefinitions* vectorDefinitions){
    int i;

    if(vectorDefinitions->entryFormat == 1)
        for (i = 0; i < vectorDefinitions->vectorSize; i++) 
            vector[i] = i+1;
    
    if(vectorDefinitions->entryFormat == 2)
        for (i = 0; i < vectorDefinitions->vectorSize; i++) 
            vector[vectorDefinitions->vectorSize - i -1] = i+1;
    
    if(vectorDefinitions->entryFormat == 3)
        for (i = 0; i < vectorDefinitions->vectorSize; i++) 
            vector[i] = (rand() % vectorDefinitions->vectorSize) + 1;
}

void sortVector(VectorDefinitions* vectorDefinitions, int *vetor, Analytics* analyze){
    if(vectorDefinitions->orderAlgm == 1){
        bubbleSort(vectorDefinitions->vectorSize, vetor, analyze);
    }
    if(vectorDefinitions->orderAlgm == 2){
        heapSort(vectorDefinitions->vectorSize, vetor, analyze);
    }
    if(vectorDefinitions->orderAlgm == 3){
        insertionSort(vectorDefinitions->vectorSize, vetor, analyze);
    }
    if(vectorDefinitions->orderAlgm == 4){
        mergeSortOrder(vectorDefinitions->vectorSize, vetor, analyze);
    }
    if(vectorDefinitions->orderAlgm == 5){
        quickSortOrder(vectorDefinitions->vectorSize, vetor, analyze);
    }
    if(vectorDefinitions->orderAlgm == 6){
        selectionSort(vectorDefinitions->vectorSize, vetor, analyze);
    }
    if(vectorDefinitions->orderAlgm == 7){
        shellSort(vectorDefinitions->vectorSize, vetor, analyze);
    }
}

void printVector(int *vector, VectorDefinitions* vectorDefinitions){
    int i;
    printf("\n");

    for(i = 0; i < vectorDefinitions->vectorSize; i++){
        printf("%d ", vector[i]);
    }
}

void generateReports(int orderAlgm, int entryFormat, int vectorSize) {
    VectorDefinitions* vectorDefinitions = malloc(sizeof(VectorDefinitions));
    vectorDefinitions->vectorSize = vectorSize;
    vectorDefinitions->orderAlgm = orderAlgm;
    vectorDefinitions->entryFormat = entryFormat;

    Analytics* analyze = malloc(sizeof(Analytics));
    analyze->clockTime=0;
    analyze->comparedTimes=0;
    analyze->swaps=0;

    int *vector = malloc(vectorDefinitions->vectorSize *sizeof(int));

    srand(0);
    buildVector(vector, vectorDefinitions);

    // printVector(vector, vectorDefinitions);

    sortVector(vectorDefinitions, vector, analyze);

    // printVector(vector, vectorDefinitions);
    writeAnalyticsDataCSV(analyze, vectorDefinitions);

    free (vector);
    free (vectorDefinitions);
    free (analyze);
}

void getAlgName(char *algName, VectorDefinitions* vectorDefinitions){
    if(vectorDefinitions->orderAlgm == 1){
        strcpy(algName, "BubbleSort");
    }
    if(vectorDefinitions->orderAlgm == 2){
        strcpy(algName, "HeapSort");
    }
    if(vectorDefinitions->orderAlgm == 3){
        strcpy(algName, "InsertionSort");
    }
    if(vectorDefinitions->orderAlgm == 4){
        strcpy(algName, "MergeSort");
    }
    if(vectorDefinitions->orderAlgm == 5){
        strcpy(algName, "QuickSort");
    }
    if(vectorDefinitions->orderAlgm == 6){
        strcpy(algName, "SelectionSort");
    }
    if(vectorDefinitions->orderAlgm == 7){
        strcpy(algName, "ShellSort");
    }
}

void getEntryFormatName(char *entryFormatName, VectorDefinitions* vectorDefinitions){
    if(vectorDefinitions->entryFormat == 1){
        strcpy(entryFormatName, "Crescente");
    }
    if( vectorDefinitions->entryFormat == 2){
        strcpy(entryFormatName, "Decrescente");
    }
    if( vectorDefinitions->entryFormat == 3){
        strcpy(entryFormatName, "Aleatorio");
    }
}