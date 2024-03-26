/*
Author: Mahmoud Yousif
date: 30/9/2023
description: takes an integer as input and loops through an array of numbers and if
the input is in the array, then the program returns it's position.

liberies used:
<stdlib>
<stdio.h>
*/

/* Important includes */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Function prototypes */

void search(int n, int array[], int len);


/* Main function */

int main(int argc, char*argv[]){

    /* Initialising variables */
    
    /* Using atoi to convert from string to integer */
    int num1 = atoi(argv[1]);

    /* Creating the array of numbers */
    int array[argc - 2];

    /* Creating the length of the array of numbers */
    int len = argc - 2;

    /* this for is used to convert every number in the array to an integer */
    for (int i = 2; i < argc; i++){

        array[i - 3] = atoi(argv[i]);
    }

    /* Calling the function search() and adding the inputs */
    search(num1, array, len);
    return 0;
}

/* This function works by looping throught an array of numbers and 
if "n" is in the array,then the function prints out "n" followed 
by it's position in the format below */

void search(int n, int array[], int len){

    for (int i = 0; i < len; i++){

        if (array[i] == n){

            printf("Found %d at %d\n", n, i + 1);
            break;
        }
    }
    
}


// exam tip: front of the queue is at the bottom while the bottom is at
// top 