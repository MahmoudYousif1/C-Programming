/* 
Program: Lab5-multiple-matrix.c
Author: Mahmoud Yousif
Date: 16/10/2023
Description: this program takes two matrices as input, multiplies them
and prints the resulting matrix.
*/


#include <stdio.h>
#include <stdlib.h>

/* Function Prototypes */
int* get_matrix(int rows, int cols, char *argv[], int start);
void displaying(int *matrix, int rows, int cols);
void multiply(int *matrixA, int rowsA, int colsA, int *matrixB, int rowsB, int colsB);

int main(int argc, char *argv[]) {
    /* Get the dimensions of the first matrix (m1 x n1) */
    int rowsA = atoi(argv[1]);
    int colsA = atoi(argv[2]);

    /* Generate the first matrix from command-line arguments */
    int *matrixA = get_matrix(rowsA, colsA, argv, 3);

    /* Get the dimensions of the second matrix (m2 x n2) */
    int rowsB = atoi(argv[rowsA * colsA + 3]);
    int colsB = atoi(argv[rowsA * colsA + 4]);

    /* Generate the second matrix from command-line arguments */
    int *matrixB = get_matrix(rowsB, colsB, argv, rowsA * colsA + 5);

    /* Call the multiply function to calculate and print the resulting matrix */
    multiply(matrixA, rowsA, colsA, matrixB, rowsB, colsB);

    /* Free the allocated memory for both matrices */
    free(matrixA);
    free(matrixB);

    return 0;
}

/* Generate a matrix from command-line arguments */
int* get_matrix(int rows, int cols, char *argv[], int start) {
    int *matrix = malloc(rows * cols * sizeof(int));
    for (int i = 0; i < rows * cols; ++i) {
        matrix[i] = atoi(argv[start + i]);
    }
    return matrix;
}

/* Display a matrix */
void displaying(int *matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d", matrix[i * cols + j]);
            if (j < cols - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

/* Multiply two matrices and print the result */
void multiply(int *matrixA, int rowsA, int colsA, int *matrixB, int rowsB, int colsB) {
    /* Allocate memory for the resulting matrix */
    int *resultMatrix = malloc(rowsA * colsB * sizeof(int));

    /* Perform matrix multiplication */
    for (int i = 0; i < rowsA; ++i) {
        for (int next = 0; next < colsB; ++next) {
            int sum = 0;
            for (int next1 = 0; next1 < colsA; ++next1) {
                sum += matrixA[i * colsA + next1] * matrixB[next1 * colsB + next];
            }
            resultMatrix[i * colsB + next] = sum;
        }
    }

    /* Displaying the resulting matrix */
    displaying(resultMatrix, rowsA, colsB);

    /* Free the allocated memory for the resulting matrix */
    free(resultMatrix);
}
