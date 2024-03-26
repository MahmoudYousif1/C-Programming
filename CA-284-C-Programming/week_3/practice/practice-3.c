/*
Author: Mahmoud Yousif

date: 30/29/2023

description: this program returns the largest element in an 
array of numbers.

liberies:
<stdlib.h>
<string.h>
<stdio.h>

*/

/* Important Includes */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Function Prototypes */

void findMax(int num1, int array[], int len);


/* Main function */

int main(int argc, char*argv[]){

    int num1 = atoi(argv[1]);
    int array[argc - 2];
    int len = argc - 2;

    for (int i = 2; i < argc; i++){

        array[i - 2] = atoi(argv[i]);
    }

    findMax(num1, array, len);
    return 0;
}


void findMax(int num1, int array[], int len){

    int max = array[0];
    for (int i = 0; i < len; i++){

        if (array[i] > max){

            max = array[i];
        }
    }

    printf("%d\n", max);
}