/*
Program: lab9-second-largest.c
Author: Mahmoud Yousif
Date: 13/11/2023
Description:
Approach:
*/


#include <stdio.h>
#include <stdlib.h>

/* Function declarations */
void fillArrayWithInput(int argc, char *argv[], double *array);
double* findSecondLargest(double *array, int size);

int main(int argc, char *argv[])
{
    /* Calculate the size of the array based on the argument count */
    int size = argc - 1;

    /* Allocate memory for the array */
    double *array = (double *)malloc(size * sizeof(double));

    /* Fill the array with input values from command line arguments */
    fillArrayWithInput(argc, argv, array);
    
    /* Find the second largest element in the array */
    double *secondLargest = findSecondLargest(array, size);
    /* If a second largest element is found, print it */
    if (secondLargest != NULL) {
        printf("%.1f\n", *secondLargest);
    }

    /* Free the allocated memory for the array */
    free(array);
    return 0;
}

/* Function to fill the array with input values converted from strings to doubles */
void fillArrayWithInput(int argc, char *argv[], double *array)
{
    for (int i = 0; i < argc - 1; ++i) {
        array[i] = atof(argv[i + 1]);
    }
}

/* Function to find the second largest element in an array */
double* findSecondLargest(double *array, int size)
{
    /* Return NULL if the array size is less than 2 */
    if (size < 2) {
        return NULL;
    }

    /* Initialize pointers to the largest and second largest elements */
    double *largest = &array[0];
    double *secondLargest = NULL;

    /* Loop through the array to find the second largest element */
    for (int i = 1; i < size; ++i) {
        if (array[i] == *largest) {
            /* Skip if it's a duplicate of the largest value */
            continue;
        } else if (!secondLargest || array[i] > *secondLargest) {
            /* Update second largest if a larger value is found */
            secondLargest = &array[i];
        }
        if (array[i] > *largest) {
            /* Update largest and second largest if a new largest is found */
            secondLargest = largest;
            largest = &array[i];
        }
    }

    /* Return the pointer to the second largest element */
    return secondLargest;
}
