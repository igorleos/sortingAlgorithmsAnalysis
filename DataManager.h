#ifndef __Analytics_H_
#define __Analytics_H_
#include <time.h>

#define DEBUG_IS_ON 0

#define SIZE_GROUP_QUANTITY 4
#define ENTRY_FORMAT_QUANTITY 3

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

void mockBubbleSortResults(Alg *alg);
void setBaseExpoToEqualizeGraph(Alg *alg);
void printAlgData(Alg *alg);
int getBaseExpo(Alg *alg, int groupSizePosition, int entryFormatPosition);
int isMaxEntireDivider(long long divis, const void* divid, int powRating);

#endif //__Analytics_H_