#ifndef __Analytics_H_
#define __Analytics_H_
#include <time.h>
typedef struct{
    clock_t clockTime;
    long comparedTimes;
    long swaps;
}Analytics;

void startTimer(Analytics* analyze);
void finishTimer(Analytics* analyze);
void printAnalyticsData(Analytics* analyze);
#endif //__Analytics_H_