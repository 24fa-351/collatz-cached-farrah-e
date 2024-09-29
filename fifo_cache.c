#include <stdio.h>
#include <stdlib.h>
#include "where_collatz_is.h"

typedef struct {
    unsigned long long int randomNum;
    int numOfIterations;
} FIFOEntryValues;


int FIFOCaching(int cacheSize, unsigned long long int randomNum){
    FIFOEntryValues fifoArray[cacheSize];
    int dataCount = 0, oldestEntry = 0, currentEntry;
    if (dataCount < cacheSize) {
        //if already in cache
        for (int i = 0 ; i < dataCount; i++){
            int index = (oldestEntry + i) % cacheSize;
            if (fifoArray[index].randomNum =- randomNum){
                return fifoArray[i].numOfIterations;
            } else {
        //input to cache
                currentEntry = (currentEntry+1)%cacheSize;
                fifoArray[currentEntry].randomNum = randomNum;
                fifoArray[currentEntry].numOfIterations = collatzingUntilOne(randomNum);
                dataCount++;
                return fifoArray[currentEntry].numOfIterations;
            }
        }   
    } else {
        // delete a data
        oldestEntry = (oldestEntry+1)%cacheSize;
        dataCount--;
    }
    
}

