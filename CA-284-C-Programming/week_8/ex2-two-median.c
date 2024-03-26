/*
Program: ex2-two-median.c
Author: Mahmoud Yousif
Date: 1/11/2023
Description:
Approach:
*/

/* Important Includes */
#include <stdio.h>
#include <stdlib.h>

/* Function Prototypes */
void selectionSorting(int array[], int len);
int getArray(int array[], int len, char* argv[]);
void printTwoMedians(int *array, int len);

/* Main Function */
int main(int argc, char* argv[]) {

    /* Initialising variables */

    /* Creating the length of the array */
    int len = argc - 1;

    /* Creating the array */
    int array[len];

    /* This function returns the array of numbers from the command line */
    getArray(array, len, argv);

    /* Calling the function: selectionSorting() to sort the array */
    selectionSorting(array, len);

    /* Printing only the two center elements of the sorted array */
    printTwoMedians(array, len);

    return 0;
}

/* This function creates the array */
int getArray(int array[], int len, char* argv[]) {
    for (int i = 0; i < len; i++) {
        array[i] = atoi(argv[i + 1]);
    }
    return 0;
}

/* This function uses selection sort to arrange and modify the array to sort the numbers within */
void selectionSorting(int array[], int len) {
    for (unsigned int i = 0; i < len; i++) {
        int min_num = i;
        for (int next = i + 1; next < len; next++) {
            if (array[min_num] > array[next]) {
                min_num = next;
            }
        }
        int temp = array[min_num];
        array[min_num] = array[i];
        array[i] = temp;
    }
}

/* This function prints the two center elements of the sorted array */
void printTwoMedians(int *array, int len) {
    printf("%d\n", array[(len-1)/2]); // prints the first center element
    printf("%d\n", array[len/2]);     // prints the second center element
}
