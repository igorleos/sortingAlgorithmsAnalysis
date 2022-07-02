#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
#include "VectorDefinitions.h"
#include "Analytics.h"

int menu(VectorDefinitions *vectorDefinitons){

    int menuOption = 4;
    // printf("1 - Definir algoritmo de ordenacao\n");
    // printf("2 - Definir tamanho do vetor\n");
    // printf("3 - Escolher formato de entrada do vetor\n");
    // printf("4 - Gerar relatorios\n");
    // printf("-1 - Para sair\n");
    //scanf("%d", &menuOption);

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
        scanf("%lld", &vectorDefinitons->vectorSize);

    }else if(menuOption == 3){
        printf("1 - Ordem crescente\n");
        printf("2 - Ordem decrescente\n");
        printf("3 - Ordem aleatoria\n");
        scanf("%d", &vectorDefinitons->entryFormat);

    }else if(menuOption == 4){
        int vectorSizes[]= {VECTOR_FIRST_SIZE, VECTOR_SECOND_SIZE, VECTOR_THIRD_SIZE, VECTOR_FOURTH_SIZE, VECTOR_FIFTH_SIZE, VECTOR_SIXTH_SIZE};
        prepareCSVFile();
        
        for(int size=0; size<7; size++){
            for(int alg=1; alg<8; alg++){
                for(int entry=1; entry<4; entry++){
                    generateReports(alg,entry, vectorSizes[size]);
                }
            }
        }
    }else if(menuOption == -1){
        //*hasPressedEscape = 1;TODO escape
        
    }else{
        printf("Digite uma opcao valida\n");
    }
    return 0;
}
