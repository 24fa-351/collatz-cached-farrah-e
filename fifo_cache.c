#include <stdio.h>
#include <stdlib.h>
#include "where_collatz_is.h"

typedef struct {
    unsigned long long int randomNum;
    unsigned long long int numOfIterations;
} FIFOEntryValues;

typedef struct
{
    int dataCount;
    int oldestEntry;
    int currentEntry;
    int fifocacheHit;
}values;
values currentVals;

unsigned long long int FIFOCaching(int cacheSize, unsigned long long int randomNum){
    FIFOEntryValues fifoArray[cacheSize];
    if (currentVals.dataCount < cacheSize-1) {
        // if already in cache
        for (int i = 0 ; i <= currentVals.dataCount; i++){
            int index = (currentVals.oldestEntry+i)%cacheSize;
            if (fifoArray[index].randomNum == randomNum){
                return fifoArray[index].numOfIterations;
                currentVals.fifocacheHit++;
            } else {
        //input to cache
                currentVals.currentEntry = (currentVals.currentEntry+1)%cacheSize;
                fifoArray[currentVals.currentEntry].randomNum = randomNum;
                fifoArray[currentVals.currentEntry].numOfIterations = collatzingUntilOne(randomNum);
                currentVals.dataCount++;
                return fifoArray[currentVals.currentEntry].numOfIterations;
            }
        }   
    } else {
        // delete a data
        currentVals.oldestEntry = (currentVals.oldestEntry+1)%cacheSize;
        currentVals.dataCount--;
        return FIFOCaching(cacheSize, randomNum);
    }
}
int FIFOCacheHit(){
    return currentVals.fifocacheHit;
}

