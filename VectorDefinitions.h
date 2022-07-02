#ifndef __VectorDefinitions_H_
#define __VectorDefinitions_H_

#include"Analytics.h" 

// #define VECTOR_FIRST_SIZE 10

#define VECTOR_FIRST_SIZE 100000
#define VECTOR_SECOND_SIZE 300000
#define VECTOR_THIRD_SIZE 500000
#define VECTOR_FOURTH_SIZE 700000
#define VECTOR_FIFTH_SIZE 1000000
#define VECTOR_SIXTH_SIZE 2000000
#define VECTOR_SIZE_QUANTITY 6
#define MIN_VALUE 0

typedef struct{
    int orderAlgm;
    char *orderAlgmName;
    int vectorSize;
    int entryFormat;
}VectorDefinitions;

void buildVector(int *vector, VectorDefinitions* vectorDefinitions);
void sortVector(VectorDefinitions* vectorDefinitions, int *vetor, Analytics* analyze);
void printVector(int *vector, VectorDefinitions* vectorDefinitions);
void generateReports(int orderAlgm, int entryFormat, int vectorSize);
void getAlgName(char *algName, VectorDefinitions* vectorDefinitions);
void getEntryFormatName(char *entryFormatName, VectorDefinitions* vectorDefinitions);

#endif //__VectorDefinitions_H_