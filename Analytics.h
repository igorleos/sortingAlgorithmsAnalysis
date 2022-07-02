#ifndef __Analytics_H_
#define __Analytics_H_
#include <time.h>

typedef struct{
    clock_t clockTime;
    long long  comparedTimes;
    long long swaps;
}Analytics;

void startTimer(Analytics* analyze);
void finishTimer(Analytics* analyze);
void prepareCSVFile();
void writeAnalyticsDataCSV(Analytics* analyze, const void * _vectorDefinitions);

#endif //__Analytics_H_