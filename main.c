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
    //char cachePolicy = argv[4][0];
    int cacheSize = atoi(argv[4]);
    FILE *collatzInfo = fopen("GSheet.csv", "w");
    fprintf(collatzInfo, "Number, Iteration\n");
    for (int i = 0; i <= N ; i++){
        unsigned long long int randomNumber = randomizingNum(maxVal, minVal);
        fprintf(collatzInfo, "%llu", randomNumber);
        int numOfIteration = LRUCaching(cacheSize, randomNumber);
        fprintf(collatzInfo, ", %d\n", numOfIteration);
    }
    fclose(collatzInfo);
    return 0;
}
