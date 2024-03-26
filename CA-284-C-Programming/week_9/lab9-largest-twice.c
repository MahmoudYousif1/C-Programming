/*
Program: lab9-largest-twice.c
Author: Mahmoud Yousif
Date: 14/11/2023
Description:
Approach:
*/

#include <stdio.h>
#include <stdlib.h>

/* Function Prototypes */
void readInput(int argc, char *argv[], int *numbers);
int findLargestTwice(int *numbers, int size);

/* Main function of the program */
int main(int argc, char *argv[]) {

    /* Calculate the size of the input array */
    int size = argc - 1;

    /* Dynamically allocate memory for the array of input numbers */
    int *numbers = (int *)malloc(size * sizeof(int));
    if (!numbers) {
        printf("Memory allocation failed\n");
        return 1;
    }

    /* Read input numbers from command-line arguments */
    readInput(argc, argv, numbers);

    /* Find the largest number that is at least twice as large as any other number */
    int result = findLargestTwice(numbers, size);

    /* Print the result */
    printf("%d\n", result);

    /* Free the dynamically allocated memory */
    free(numbers);
    return 0;
}

/* Function to read input from command-line arguments */
void readInput(int argc, char *argv[], int *numbers) {
    for (int i = 0; i < argc - 1; ++i) {
        numbers[i] = atoi(argv[i + 1]);
    }
}

/* Function to find the largest number that is at least twice as large as any other number */
int findLargestTwice(int *numbers, int size) {
    /* Initialize the largest number */
    int largest = numbers[0];
    /* Flag to check if a valid number is found */
    int valid = 0;

    /* Find the largest number in the array */
    for (int i = 1; i < size; ++i) {
        if (numbers[i] > largest) {
            largest = numbers[i];
        }
    }

    /* Check if the largest number is at least twice as large as any other number */
    for (int i = 0; i < size; ++i) {
        if (largest >= 2 * numbers[i] && largest != numbers[i]) {
            valid = 1;
            break;
        }
    }

    /* Return the largest number if valid, otherwise return 0 */
    return valid ? largest : 0;
}
