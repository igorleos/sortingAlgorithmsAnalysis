#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
#include "VectorDefinitions.h"
#include "Analytics.h"


#define TOTAL_COMPRA 15
#define MEIOS_PGMT_QNT 6

int menu(VectorDefinitions *vectorDefinitons){

    int menuOption = 0;
    printf("1 - Definir algoritmo de ordenacao\n");
    printf("2 - Definir tamanho do vetor\n");
    printf("3 - Escolher formato de entrada do vetor\n");
    printf("6 - Gerar relatorios\n");
    printf("-1 - Para sair\n");
    scanf("%d", &menuOption);

    if(menuOption == 1){
        printf("1 - BubbleSort\n");
        printf("2 - HeapSort\n");
        printf("3 - InsertionSort\n");
        printf("4 - MergeSort\n");
        printf("5 - QuickSort\n");
        printf("6 - SelectionSort\n");
        printf("7 - ShellSort\n");
        scanf("%d", &vectorDefinitons->orderAlgm);

    }else if(menuOption == 2){
        printf("Digite o tamanho do vetor\n");
        scanf("%ld", &vectorDefinitons->vectorSize);

    }else if(menuOption == 3){
        printf("1 - Ordem crescente\n");
        printf("2 - Ordem decrescente\n");
        printf("3 - Ordem aleatoria\n");
        scanf("%d", &vectorDefinitons->entryFormat);

    }else if(menuOption == 4){
        //TODO realizar ordenacao

    }else if(menuOption == -1){
        //*hasPressedEscape = 1;TODO escape
        
    }else{
        printf("Digite uma opcao valida\n");
    }
}
