#include <stdio.h>
#include <stdlib.h>
#include "where_collatz_is.h"

typedef struct {
    unsigned long long int randomNum;
    int numOfIterations;
    unsigned long long int timesUsed;
} LRUEntryValues;

int LRUCaching(int cacheSize, unsigned long long int randomNum){
    LRUEntryValues cacheArray[cacheSize];
    int currentEmptyIndex = 0;
    int indexLeastUsed = 0;
    if (&cacheArray[cacheSize-1].numOfIterations == 0){
     for (int i = 0 ; i <= cacheSize; i++){
        if(cacheArray[i].randomNum = randomNum){
            cacheArray[i].timesUsed ++;
            return cacheArray[i].numOfIterations;
        }
     }
    cacheArray[currentEmptyIndex].randomNum=randomNum;
    cacheArray[currentEmptyIndex].numOfIterations=collatzingUntilOne(randomNum);
    cacheArray[currentEmptyIndex].timesUsed=0; 
    currentEmptyIndex++;
    return cacheArray[currentEmptyIndex].numOfIterations;
    }
    else{
     for (int i = 0 ; i <= cacheSize; i++){
        if(cacheArray[i].timesUsed < cacheArray[indexLeastUsed].timesUsed){
            indexLeastUsed = i;
        }
     }
     cacheArray[currentEmptyIndex].numOfIterations = 0;
     currentEmptyIndex--;
    }
}




