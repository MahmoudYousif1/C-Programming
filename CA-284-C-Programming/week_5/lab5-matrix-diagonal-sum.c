/*
Program: lab5-multiple-matrix.c
Author: Mahmoud Yousif
Date:16/10/2023
Description:this program takes a square matrix and calculates the sum of 
its diagonal numbers and the result is printed at the end.
*/

/* Important Includes */
#include <stdio.h>
#include <stdlib.h>

/* Function Prototypes */
void findsum(int num, int *array);

int main(int argc, char *argv[]) {
    /* Get the size of the matrix from the command-line argument */
    int num = atoi(argv[1]);
    
    /* Allocate memory for the matrix elements */
    int *matrix = malloc(num * num * sizeof(int));

    /* Convert string elements to integers and store them in the matrix array */
    for (int i = 0; i < num * num; ++i) {
        matrix[i] = atoi(argv[i + 2]);
    }

    /* Call the findsum function to calculate and print the diagonal sum */
    findsum(num, matrix);

    /* Free the allocated memory */
    free(matrix);

    return 0; /* Exit successfully */
}

void findsum(int num, int *array) {
    int total = 0;

    /* Iterate through the matrix elements */
    for (int i = 0; i < num; i++) {
        /* Access the element on the main diagonal using pointer arithmetic */
        int ele = array[i * num + i];
        
        /* Sum the main diagonal elements */
        total += ele;
    }

    /* Print the diagonal sum */
    printf("%d\n", total);
}
