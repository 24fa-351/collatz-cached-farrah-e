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
    double cacheHit;
    FILE *collatzInfo = fopen("GSheet.csv", "w");
    fprintf(collatzInfo, "Randomized Number, Iteration, Cache Policy, Cache Hit Percentage\n");


    for (int i = 1; i <= N ; i++){
        unsigned long long int randomNumber = randomizingNum(maxVal, minVal);
        fprintf(collatzInfo, "%llu", randomNumber);
        if (cachePolicy == 'f'){
            numOfIteration = FIFOCaching(cacheSize, randomNumber);
            cacheHit = FIFOCacheHit(N);

            }
        else if (cachePolicy == 'l'){
            numOfIteration = LRUCaching(cacheSize, randomNumber);
            cacheHit = LRUCacheHit(N);
        }
        else return printf("Please Input f (fifo) or l (lru)");
       //int numOfIteration = collatzingUntilOne(randomNumber);
        fprintf(collatzInfo, ", %llu", numOfIteration);
        fprintf(collatzInfo, ", %c", cachePolicy);
        fprintf(collatzInfo, ", %d \n", cacheHit);
    }
    fclose(collatzInfo);
    return 0;
}
