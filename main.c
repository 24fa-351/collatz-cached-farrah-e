#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "where_collatz_is.h"



int main(int argc, char *argv[]){
    int N = atoi(argv[1]);
    int minVal = atoi(argv[2]);
    int maxVal = atoi(argv[3]);
    char cachePolicy = argv[4][0];
    int cacheSize = atoi(argv[5]);
    for (int i = 0; i <= N ; i++){
        unsigned long long int randomNumber = randomizingNum(maxVal, minVal);
        int numOfIteration = collatzingUntilOne(randomNumber);
    }
    return 0;
}
