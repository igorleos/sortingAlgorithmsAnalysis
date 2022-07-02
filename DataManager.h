#ifndef __Analytics_H_
#define __Analytics_H_
#include <time.h>

#define DEBUG_IS_ON 1

#define ALG_QUANTITY 7
#define SIZE_GROUP_QUANTITY 4
#define ENTRY_FORMAT_QUANTITY 3

#define VECTOR_SIZE_COLUMN 0
#define ALG_NAME_COLUMN 1
#define ENTRY_FORMAT_COLUMN 2
#define COMPARED_TIMES_COLUMN 3
#define SWAPS_COLUMN 4
#define TIME_COLUMN 5

typedef struct{
    float clockTime;
    long long  comparedTimes;
    long long swaps;
}EntryFormat;


typedef struct{
    EntryFormat entryFormats[ENTRY_FORMAT_QUANTITY];
    int groupSize;
}SizeGroup;

typedef struct{
    SizeGroup sizeGroups[SIZE_GROUP_QUANTITY];
    int baseExpoToEqualizeGraph;
}Alg;

int readCsvFile(Alg algoritms[], int algmsQnt);
void setBaseExpoToEqualizeGraph(Alg *alg);
int getBaseExpo(long long greaterValue, long _smallerValue);
int isMaxEntireDivider(long long dividend, const void* _divider, int _expo);

int getAlgsPos(char *algName);
int getSizeGroupPos();
int getEntryFormatPos(char *entryFormatName);


void mockBubbleSortResults(Alg *alg);
void printAlgData(Alg *alg);

#endif //__Analytics_H_