#include <stdio.h>
#include <stdlib.h>
#include "where_collatz_is.h"

typedef struct {
    unsigned long long int randomNum;
    int numOfIterations;
    unsigned long long int timesUsed;
} FIFOEntryValues;


int FIFOCaching(int cacheSize, unsigned long long int randomNum){
    FIFOEntryValues fifoArray[cacheSize];
    int dataCount = 0, oldestEntry = 0, currentEntry;
    if (dataCount < cacheSize){
        //add to array
        currentEntry = (currentEntry+1)%cacheSize;
        fifoArray[currentEntry].randomNum = randomNum;
        fifoArray[currentEntry].numOfIterations = collatzingUntilOne(randomNum);
    }
    else {
        // delete a data
        oldestEntry = (oldestEntry+1)%cacheSize;
        dataCount--;
    }
    
}

