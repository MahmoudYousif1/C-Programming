/*
Author: Mahmoud Yousif

date: 30/9/2023

description: this program takes in an array of numbers and 
an input of argv[1]. If the integer at argv[1] is in the array, then
the program returns the integer and it's position

liberies used:

<stdio.h>
<stlib.h>
*/

/* Important includes */

#include <stdlib.h>
#include <stdio.h>

/* Function Prototypes */

void search_nums(int num1, int array[], int len);


/* Main Function */

int main(int argc, char*argv[]){

    int array[argc - 2];
    int len = argc - 2;
    int num1 = atoi(argv[1]);

    for (int i = 2; i < argc; i++){

        array[i - 3] = atoi(argv[i]);
    }

    search_nums(num1, array, len);
    return 0;
}


void search_nums(int num1, int array[], int len){

    for (int i = 1; i < len; i++){

        if (array[i] == num1){

            printf("Found %d at %d\n", num1, i + 1);
            break;
        }
    }
}