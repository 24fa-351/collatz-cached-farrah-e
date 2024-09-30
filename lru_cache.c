#include <stdio.h>
#include <stdlib.h>
#include "where_collatz_is.h"

typedef struct {
    unsigned long long int randomNum;
    unsigned long long int numOfIterations;
    unsigned long long int timesUsed;
} LRUEntryValues;

int cacheHit = 0;

unsigned long long int LRUCaching(int cacheSize, unsigned long long int randomNum){
    LRUEntryValues cacheArray[cacheSize];
    int currentEmptyIndex = 0;
    int indexLeastUsed = 0;
    for (unsigned long long int i = 0; i < cacheArray[cacheSize].numOfIterations; i++){
        cacheArray[i].numOfIterations = 0;
    }
    if (cacheArray[cacheSize-1].numOfIterations != 0){
      for (int i = 0 ; i <= currentEmptyIndex; i++){
        if(cacheArray[i].randomNum = randomNum){
            cacheArray[i].timesUsed ++;
            cacheHit++;
            return cacheArray[i].numOfIterations;
        }
     }
    cacheArray[currentEmptyIndex].randomNum=randomNum;
    cacheArray[currentEmptyIndex].numOfIterations=collatzingUntilOne(randomNum);
    cacheArray[currentEmptyIndex].timesUsed=0; 
    currentEmptyIndex++;
    return cacheArray[currentEmptyIndex-1].numOfIterations;
    }
    else{
     for (int i = 0 ; i <= cacheSize; i++){
        if(cacheArray[i].timesUsed < cacheArray[indexLeastUsed].timesUsed){
            indexLeastUsed = i;
        }
     }
     cacheArray[currentEmptyIndex].numOfIterations = 0;
     currentEmptyIndex--;
     return LRUCaching(cacheSize, randomNum);
    }
}

int LRUCacheHit(){
    return cacheHit;
}




