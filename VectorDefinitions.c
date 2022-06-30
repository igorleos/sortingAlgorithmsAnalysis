#include<stdio.h>
#include<stdlib.h>

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
            vector[i] = i;
    
    if(vectorDefinitions->entryFormat == 2)
        for (i = 0; i < vectorDefinitions->vectorSize; i++) 
            vector[vectorDefinitions->vectorSize - i -1] = i;
    
    if(vectorDefinitions->entryFormat == 3)
        for (i = 0; i < vectorDefinitions->vectorSize; i++) 
            vector[i] = (rand() % vectorDefinitions->vectorSize) + 0;
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
        printf("%d\n", vector[i]);
    }
}

void testSorting(int orderAlgm, int entryFormat) {
    VectorDefinitions* vectorDefinitions = malloc(sizeof(VectorDefinitions));
    vectorDefinitions->vectorSize = VECTOR_FIRST_SIZE;
    vectorDefinitions->entryFormat = 1;
    vectorDefinitions->orderAlgm = orderAlgm;
    vectorDefinitions->entryFormat = entryFormat;

    Analytics* analyze = malloc(sizeof(Analytics));

    int *vector = malloc(vectorDefinitions->vectorSize *sizeof(int));

    srand(0);
    buildVector(vector, vectorDefinitions);

    printVector(vector, vectorDefinitions);

    sortVector(vectorDefinitions, vector, analyze);

    printVector(vector, vectorDefinitions);
    printAnalyticsData(analyze);

    free (vector);
    free (vectorDefinitions);
    free (analyze);
}