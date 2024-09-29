#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned long long int randomNum;
    int numOfIterations;
    unsigned long long int timesUsed;
} LRUEntryValues;

unsigned long long int gettingOrPutting(int cacheSize, unsigned long long int randomNum){
    // for (int i = 0 ; i <= cacheSize; i++){
    //     //if rnum is there, return val
    //     //else add to cache
    // }
}

void makingSpace(){
    // subtract least used data
}

unsigned long long int LRUCaching(int cacheSize, unsigned long long int randomNum){
    LRUEntryValues cacheArray[cacheSize];
    //check if array is full
    if (&cacheArray[cacheSize-1] != 0) gettingOrPutting(cacheSize, randomNum);
    else makingSpace();

}




