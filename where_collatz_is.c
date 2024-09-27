#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "where_collatz_is.h"

//#define finalCollatz (1);
FILE *collatzInfo;

int randomizingNum(int max, int min){
    srand(time(NULL));
    return rand() % (max-min+1) + min;
    //printf("%d is the randomized num", randomizedNum);
}

int collatzingUntilOne(int randomNum){
int collatz = randomNum;
int iteration = 0;
while (collatz !=  1){
    if (collatz % 2 == 0) collatz = collatz/2;
    else collatz = (3*collatz)+1;
    iteration --;
}
return iteration;
}
