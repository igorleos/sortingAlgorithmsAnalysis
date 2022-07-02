#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataManager.h"

// int main(){
// 	FILE* fp = fopen("AnalyticsData.csv", "r");

// 	if (!fp)
// 		printf("Can't open file\n");

// 	else {
// 		// Here we have taken size of
// 		// array 1024 you can modify it
// 		char buffer[1024];

// 		int row = 0;
// 		int column = 0;



// 		while (fgets(buffer,1024, fp)) {
// 			column = 0;
// 			row++;

// 			// To avoid printing of column

// 			if (row == 1)
// 				continue;

// 			// Splitting the data
// 			char* value = strtok(buffer, "; ");
//             //fprintf(fpt,"Tamanho do vetor;Algoritmo usado;Forma de entrada;Comparacoes realizadas; Chaves trocadas; Tempo total\n");

// 			while (value) {
// 				// Column 1
// 				if (column == 0) {
// 					printf("Name :");
// 				}

// 				// Column 2
// 				if (column == 1) {
// 					printf("\tAccount No. :");
// 				}

// 				// Column 3
// 				if (column == 2) {
// 					printf("\tAmount :");
// 				}

// 				printf("%s", value);
// 				value = strtok(NULL, ", ");
// 				column++;
// 			}

// 			printf("\n");
// 		}

// 		// Close the file
// 		fclose(fp);
// 	}
// 	return 0;
// }

int main(){
    Alg *alg = malloc(sizeof(Alg));
    mockBubbleSortResults(alg);
    setTimePivot(alg);
    // printAlgData(alg);
}

void mockBubbleSortResults(Alg *alg){
    int oneK = 1000;

    alg->sizeGroups[0].groupSize = 100 * oneK;
    alg->sizeGroups[1].groupSize = 300 * oneK;
    alg->sizeGroups[2].groupSize = 500 * oneK;
    alg->sizeGroups[3].groupSize = 700 * oneK;
    alg->sizeGroups[4].groupSize = oneK * oneK;

    /*==========Mock da Coluna de tempo=========*/
    alg->sizeGroups[0].entryFormats[0].clockTime = 18.488;
    alg->sizeGroups[0].entryFormats[1].clockTime = 26.813;
    alg->sizeGroups[0].entryFormats[2].clockTime = 32.239;

    alg->sizeGroups[1].entryFormats[0].clockTime = 166.608;
    alg->sizeGroups[1].entryFormats[1].clockTime = 234.756;
    alg->sizeGroups[1].entryFormats[2].clockTime = 282.313;

    alg->sizeGroups[2].entryFormats[0].clockTime = 453.714;
    alg->sizeGroups[2].entryFormats[1].clockTime = 658.02;
    alg->sizeGroups[2].entryFormats[2].clockTime = 791.108;

    alg->sizeGroups[3].entryFormats[0].clockTime = 885.641;
    alg->sizeGroups[3].entryFormats[1].clockTime = 1291.075;
    alg->sizeGroups[3].entryFormats[2].clockTime = 1548.748;

    alg->sizeGroups[4].entryFormats[0].clockTime = 1809.524;


    /*==========Mock da Coluna de comparacoes=========*/
    alg->sizeGroups[0].entryFormats[0].comparedTimes = 19999700001;
    alg->sizeGroups[0].entryFormats[1].comparedTimes = 19999700001;
    alg->sizeGroups[0].entryFormats[2].comparedTimes = 19999700001;

    alg->sizeGroups[1].entryFormats[0].comparedTimes = 179999000000;
    alg->sizeGroups[1].entryFormats[1].comparedTimes = 179999000000;
    alg->sizeGroups[1].entryFormats[2].comparedTimes = 179999000000;

    alg->sizeGroups[2].entryFormats[0].comparedTimes = 499999000000;
    alg->sizeGroups[2].entryFormats[1].comparedTimes = 499999000000;
    alg->sizeGroups[2].entryFormats[2].comparedTimes = 499999000000;

    alg->sizeGroups[3].entryFormats[0].comparedTimes = 979998000000;
    alg->sizeGroups[3].entryFormats[1].comparedTimes = 979998000000;
    alg->sizeGroups[3].entryFormats[2].comparedTimes = 979998000000;

    alg->sizeGroups[4].entryFormats[0].comparedTimes = 2000000000000;

    /*==========Mock da Coluna de chaves=========*/
    alg->sizeGroups[0].entryFormats[0].swaps = 0;
    alg->sizeGroups[0].entryFormats[1].swaps = 14999850000;
    alg->sizeGroups[0].entryFormats[2].swaps = 7521285681;

    alg->sizeGroups[1].entryFormats[0].swaps = 0;
    alg->sizeGroups[1].entryFormats[1].swaps = 135000000000;
    alg->sizeGroups[1].entryFormats[2].swaps = 67612016250;

    alg->sizeGroups[2].entryFormats[0].swaps = 0;
    alg->sizeGroups[2].entryFormats[1].swaps = 374999000000;
    alg->sizeGroups[2].entryFormats[2].swaps = 187495000000;

    alg->sizeGroups[3].entryFormats[0].swaps = 0;
    alg->sizeGroups[3].entryFormats[1].swaps = 734999000000;
    alg->sizeGroups[3].entryFormats[2].swaps = 367478000000;

    alg->sizeGroups[4].entryFormats[0].swaps = 0;

}

 void printAlgData(Alg *alg){
    for(int gpSizeP = 0; gpSizeP < SIZE_GROUP_QUANTITY; gpSizeP++){
        for(int etFtP = 0; etFtP < ENTRY_FORMAT_QUANTITY; etFtP++){
            printf("group: %d    ", gpSizeP);
            printf("group: %d    ", alg->sizeGroups[gpSizeP].groupSize);
            printf("group: %d    ", gpSizeP);
            printf("entry: %d    ", etFtP);

            printf("clock: %.2f    ", alg->sizeGroups[gpSizeP].entryFormats[etFtP].clockTime);
            printf("comp: %lld    ", alg->sizeGroups[gpSizeP].entryFormats[etFtP].comparedTimes);
            printf("swap: %lld\n\n", alg->sizeGroups[gpSizeP].entryFormats[etFtP].swaps);
        }
    }
    printf("%ld\n", alg->timePivot);
 }


void setTimePivot(Alg *alg){
    int diferenceRate = getDiferenceRate(alg, 0, 0);

    for(int gpSizeP = 0; gpSizeP < SIZE_GROUP_QUANTITY; gpSizeP++){
        for(int etFtP = 0; etFtP < ENTRY_FORMAT_QUANTITY; etFtP++){
            int aux = getDiferenceRate(alg, gpSizeP, etFtP);

            if(etFtP > aux){
                diferenceRate = aux;
            }
        }
    }
    alg->timePivot = diferenceRate;
}

int getDiferenceRate(Alg *alg, int groupSizePosition, int entryFormatPosition){
    long long comparedTimes = alg->sizeGroups[groupSizePosition].entryFormats[entryFormatPosition].comparedTimes;
    float *clockTime = malloc(sizeof(float));
    *clockTime = alg->sizeGroups[groupSizePosition].entryFormats[entryFormatPosition].clockTime;
    int expo = 0;
    int exec =100;
    while(!isMaxEntireDiv(comparedTimes, clockTime, expo) && exec>=0){
        expo++;
        exec--;
    }

    printf("\ncompared: %lld\n", comparedTimes);
    printf("clockTime: %.2f\n", *clockTime);
    printf("expo: %d\n", expo);
    return expo;
}

int isMaxEntireDiv(long long dividend, const void* _divider, int _expo){
    float divider = *((float *)_divider);
    int expo = _expo;
    long long productBase10 = 1;


    int exec =20;
    while (expo != 0 && exec>=0) {
        productBase10 *= 10;
        --expo;
        exec--;
    }

    long long dividerValue = dividend / productBase10;
    long long divisonRest = dividerValue %  (int)divider;
    
    if(divisonRest < 10){
        printf("\n      %lld / (10 ^ %d) = %lld\n", dividend, _expo, productBase10);
        printf("-------------------------------- = ");
        printf(" %lld\n", divisonRest);
        printf("      %d\n\n", (int)divider );
    }


    // printf("expoente:%d\n", _expo);
    // printf("divisor puro: %lld\n\n\n", divider);
    
    return divisonRest < 10;
}

