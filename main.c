#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "where_collatz_is.h"
#include "lru_cache.h"
#include "fifo_cache.h"

int main(int argc, char *argv[]){
    int N = atoi(argv[1]);
    int minVal = atoi(argv[2]);
    int maxVal = atoi(argv[3]);
    char cachePolicy = argv[4][0];
    int cacheSize = atoi(argv[5]);
    int numOfIteration = 0;
    FILE *collatzInfo = fopen("GSheet.csv", "w");
    fprintf(collatzInfo, "Randomized Number, Iteration, Cache Hit\n");


    for (int i = 1; i <= N ; i++){
        unsigned long long int randomNumber = randomizingNum(maxVal, minVal);
        fprintf(collatzInfo, "%llu", randomNumber);
        if (cachePolicy == 'f') numOfIteration = FIFOCaching(cacheSize, randomNumber);
        else numOfIteration = LRUCaching(cacheSize, randomNumber);
       //int numOfIteration = collatzingUntilOne(randomNumber);
        fprintf(collatzInfo, ", %llu", numOfIteration);
        int cacheHit = FIFOCacheHit();
        fprintf(collatzInfo, ", %d\n", cacheHit);
    }
    fclose(collatzInfo);
    return 0;
}
