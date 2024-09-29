#include <stdio.h>
#include <stdlib.h>
#include "where_collatz_is.h"

unsigned long long int randomizingNum(int max, int min){
    return rand() % (max-min+1) + min;
}
int collatzingUntilOne(unsigned long long int randomNum){
unsigned long long int collatz = randomNum;
int iteration = 0;
while (collatz !=  1){
    iteration ++;
    if (collatz % 2 == 0) collatz = collatz/2;
    else collatz = (3*collatz)+1;
}
return iteration;
}
