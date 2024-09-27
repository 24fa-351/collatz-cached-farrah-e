#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "where_collatz_is.h"


int main(int argc, char *argv[]){
    int N = atoi(argv[1]);
    int minVal = atoi(argv[2]);
    int maxVal = atoi(argv[3]);
    for (int i = 0; i <= N ; i++){
        int randomNumber = randomizingNum(maxVal, minVal);
        collatzingUntilOne(randomNumber);
    }

    return 0;
}
