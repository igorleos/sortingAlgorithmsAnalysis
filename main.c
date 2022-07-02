#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
#include"Menu.h"
#include "VectorDefinitions.h"
#include "Analytics.h"

int main(){
    VectorDefinitions *vectorDefinitons = malloc(sizeof(VectorDefinitions));
    menu(vectorDefinitons);
    free(vectorDefinitons);
}
