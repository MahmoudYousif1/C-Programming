/*
Author: Mahmoud Yousif
date: 1/10/2023
description: this program accepts an array of numbers and sorts them using
selection sort.

liberies:
<stdlib.h>
<stdio.h>
*/


/* Important Includes */
#include <stdio.h>
#include <stdlib.h>

/* Function Prototypes */
void selectionSorting(int array[], int len);
int getArray(int array[], int len, char*argv[]);


/* Main Function */
int main(int argc, char*argv[]){

    /* Initialsing variables */

    /* Creating the length of the array */
    int len = argc - 1;

    /* Creating the array */
    int array[len];

    /* this function returns the array of numbers from the command line */
    getArray(array, len, argv);

    /* Calling the function: selectionSorting() to sort the array */
    selectionSorting(array, len);

    /* printing the sorted numbers using a for loop */
    for (unsigned int i = 0; i < len; i++){

        printf("%d\n", array[i]);
    }
    return 0;
}


/* this function creates the array */
int getArray(int array[], int len, char*argv[]){

    for (int i = 0; i < len; i++){

        array[i] = atoi(argv[i + 1]);
    }
}


/* this function uses selection sort to arrange and modify the array to sort
the numbers within */
void selectionSorting(int array[], int len){

    for (unsigned int i = 0; i < len; i++){

        /* Starting with the minimum number of i which is 0 */
        int min_num = i;

        /* if the minimum number in the array is larger than the next 
        number than the next number becomes the new minimum */
        for (int next = i + 1; next < len; next++){

            if (array[min_num] > array[next]){

                min_num = next;
            }
        }

        /*The swapping process here ensures that the minimum element is moved 
        to its correct position at the beginning of the unsorted part of 
        the array. This process is repeated until the array is sorted.
        */
        int temp = array[min_num];
        array[min_num] = array[i];
        array[i] = temp;
    }
}