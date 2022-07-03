#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataManager.h"


int readCsvFile(Alg algoritms[], int algmsQnt){
	FILE* fp = fopen("AnalyticsData.csv", "r");

	if (!fp)
		printf("Arquivo nao foi aberto\n");

	else {
		// Here we have taken size of
		// array 1024 you can modify it
		char buffer[1024];

		int row = 0;
		int column = 0;

		while (fgets(buffer,1024, fp)) {
			column = 0;
			row++;

			// To avoid printing of column

			if (row == 1)
				continue;

			// Splitting the data
			char* value = strtok(buffer, "; ");

            
			while (value) {
                int algNamePos, groupSizePos, entryFormatPos;
                int groupSize, algNamePos, groupSizePos, entryFormatPos;
                long long comparedTimes, swaps;
                float totalTimes;
                char algName[15], entryFormat[15];


				if (column == ALG_NAME_COLUMN) {
					algNamePos = getAlgsPos(value);
				}

				if (column == VECTOR_SIZE_COLUMN) {
                    int valueRead;
                    sscanf(buffer,"%d", &valueRead);
					groupSizePos= getSizeGroupPos(valueRead);
                    algoritms[algNamePos].sizeGroups[groupSizePos].groupSize = value;
				}     



				if (column == ENTRY_FORMAT_COLUMN) {
                    entryFormatPos = getEntryFormatPos(value);
				}
                
				if (column == COMPARED_TIMES_COLUMN) {
                    algoritms[algNamePos].sizeGroups[groupSizePos].entryFormats[entryFormatPos].comparedTimes = value;
				}

				if (column == SWAPS_COLUMN) {
                    algoritms[algNamePos].sizeGroups[groupSizePos].entryFormats[entryFormatPos].swaps = value;
				}

                if (column == TIME_COLUMN) {
                    algoritms[algNamePos].sizeGroups[groupSizePos].entryFormats[entryFormatPos].clockTime = (float)*value;
				}

				value = strtok(NULL, "; ");
				column++;
			}
		}
		fclose(fp);
	}
	return 0;
}

int main(){
    Alg algoritms[ALG_QUANTITY];
    readCsvFile(algoritms, ALG_QUANTITY);

    //Alg *alg = malloc(sizeof(Alg));
    // mockBubbleSortResults(alg);
    for(int algPos = 0; algPos < ALG_QUANTITY; algPos++){
        setBaseExpoToEqualizeGraph(&algoritms[algPos]);
    }
    // printAlgData(alg);
}

void setBaseExpoToEqualizeGraph(Alg *alg){
    long long comparedTimes = alg->sizeGroups[0].entryFormats[0].comparedTimes;
    long long swaped ;

    long clockTime = alg->sizeGroups[0].entryFormats[0].clockTime;
    
    
    int greaterBaseExpo = getBaseExpo(comparedTimes, clockTime);

    for(int gpSizePos = 0; gpSizePos < SIZE_GROUP_QUANTITY; gpSizePos++){
        for(int etFtP = 0; etFtP < ENTRY_FORMAT_QUANTITY; etFtP++){
            comparedTimes = alg->sizeGroups[gpSizePos].entryFormats[etFtP].comparedTimes;
            swaped = alg->sizeGroups[gpSizePos].entryFormats[etFtP].swaps;

            clockTime = alg->sizeGroups[gpSizePos].entryFormats[etFtP].clockTime;

            int comparedTimesToClockTimes = getBaseExpo(comparedTimes, clockTime);
            int swapedTimesToClockTimes = getBaseExpo(swaped, clockTime);

            if(greaterBaseExpo < comparedTimesToClockTimes){
                greaterBaseExpo = comparedTimesToClockTimes;
            }
            if(greaterBaseExpo < swapedTimesToClockTimes){
                greaterBaseExpo = swapedTimesToClockTimes;
            }

            if(DEBUG_IS_ON){
                printf("greaterBaseExpo expo %d\n", greaterBaseExpo);
                printf("comparedTimesToClockTimes expo %d\n", comparedTimesToClockTimes);
                printf("swapedTimesToClockTimes expo %d\n\n", swapedTimesToClockTimes);
            }
        }
    }
    alg->baseExpoToEqualizeGraph = greaterBaseExpo;

    if(DEBUG_IS_ON){
        printf("base expo %d\n", alg->baseExpoToEqualizeGraph);
    }
}

int getBaseExpo(long long greaterValue, long _smallerValue){
    long *smallerValue = malloc(sizeof(long));
    *smallerValue = _smallerValue;

    int expo = 0;
    int exec =100;
    while(!isMaxEntireDivider(greaterValue, smallerValue, expo) && exec>=0){
        expo++;
        exec--;
    }

    if(DEBUG_IS_ON){
        printf("\ncompared: %lld\n", greaterValue);
        printf("clockTime: %ld\n", *smallerValue);
        printf("expo: %d\n", expo);
    }

    return expo;
}

int isMaxEntireDivider(long long dividend, const void* _divider, int _expo){
    long divider = *((long *)_divider);
    long long productBase10 = 1;
    int expo = _expo;

    while (_expo != 0 ) {
        productBase10 *= 10;
        --_expo;
    }

    long long dividerValue = divider  * productBase10;
    long long result = dividend / dividerValue;
    if(result < 1 && DEBUG_IS_ON){
        printf("\n\n era para ser 0\n\n");
    }
    
    if(result < 10 && DEBUG_IS_ON){
        printf("\n\n\n      %lld\n", dividend);
        printf("-------------------------------- = ");
        printf(" %lld\n", result);
        printf("    %ld * (10 ^ %d)\n", divider, expo);
    }
    return result < 10;
}

void printAlgData(Alg *alg){
    for(int gpSizePos = 0; gpSizePos < SIZE_GROUP_QUANTITY; gpSizePos++){
        for(int etFtP = 0; etFtP < ENTRY_FORMAT_QUANTITY; etFtP++){
            printf("group: %d    ", gpSizePos);
            printf("group: %d    ", alg->sizeGroups[gpSizePos].groupSize);
            printf("group: %d    ", gpSizePos);
            printf("entry: %d    ", etFtP);

            printf("clock: %.2f    ", alg->sizeGroups[gpSizePos].entryFormats[etFtP].clockTime);
            printf("comp: %lld    ", alg->sizeGroups[gpSizePos].entryFormats[etFtP].comparedTimes);
            printf("swap: %lld\n\n", alg->sizeGroups[gpSizePos].entryFormats[etFtP].swaps);
        }
    }
    printf("%d\n", alg->baseExpoToEqualizeGraph);
 }

void mockBubbleSortResults(Alg *alg){
    int oneK = 1000;

    alg->sizeGroups[0].groupSize = 100 * oneK;
    alg->sizeGroups[1].groupSize = 300 * oneK;
    alg->sizeGroups[2].groupSize = 500 * oneK;
    alg->sizeGroups[3].groupSize = 700 * oneK;
    //alg->sizeGroups[4].groupSize = oneK * oneK;

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

    // alg->sizeGroups[4].entryFormats[0].clockTime = 1809.524;


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

    // alg->sizeGroups[4].entryFormats[0].comparedTimes = 2000000000000;

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

    //alg->sizeGroups[4].entryFormats[0].swaps = 0;

}

int getAlgsPos(char *algName){
    int pos;
    if(algName == "BubbleSort"){
        pos = 0;
    }
    if(algName == "HeapSort"){
        pos = 1;
    }
    if(algName == "InsertionSort"){
        pos = 2;
    }
    if(algName == "MergeSort"){
        pos = 3;
    }
    if(algName == "QuickSort"){
        pos = 4;
    }
    if(algName == "SelectionSort"){
        pos = 5;
    }
    if(algName == "ShellSort"){
        pos = 6;
    }
    return pos;
}

int getSizeGroupPos(int size){
    int pos;
    int oneK =1000;

    if(size == 100*oneK){
        pos = 0;
    }
    else if(size == 300*oneK){
        pos = 1;
    }
    else if(size == 500*oneK){
        pos = 2;
    }
    else if(size == 700*oneK){
        pos = 3;
    }
    else if(size == oneK*oneK){
        pos = 4;
    }
    else if(size == 200*oneK*oneK){
        pos = 5;
    }
    else{
        pos=-1;
    }
    return pos;
}

int getEntryFormatPos(char *entryFormatName){
    int pos;
    if(entryFormatName == "Crescente"){
        pos = 0;
    }
    if(entryFormatName == "Decrescente"){
        pos = 1;
    }
    if(entryFormatName == "Aleatorio"){
        pos = 2;
    }
    return pos;
}