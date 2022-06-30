#include<stdio.h>
#include<stdlib.h>
#include"BubbleSort.h"
#include"HeapSort.h"
#include"InsertionSort.h"
#include"MergeSort.h"
#include"QuickSort.h"
#include"SelectionSort.h"
#include"ShellSort.h"

#define tamanho_vetor 10
#define valor_max 20
#define valor_min 0

int main(){
    int i, *vetor;
    strand(0);

    vetor = malloc(tamanho_vetor*sizeof(int));

    for(i=0; i<tamanho_vetor; i++)
        vetor[i] = (rand() % valor_max) + valor_min;

    for(i=0; i<tamanho_vetor; i++)
        print("%d", vetor[i]);

    bubbleSort(tamanho_vetor, vetor);

    selectionSort(tamanho_vetor, vetor);

    insertionSort(tamanho_vetor, vetor); 

    shellSort(tamanho_vetor, vetor); 

    for(i=0; i< tamanho_vetor; i++)
        printf("%d", vetor[i]);
    

    free(vetor);

    return 0;    

}