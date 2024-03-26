/*
Program: lab9-dot-product-two-vector.c
Author: Mahmoud Yousif
Date: 11/11/2023
Description:
Approach:
*/


/* Standard library includes */
#include <stdio.h>
#include <stdlib.h>

/* Function prototypes */
void extract_vectors_from_args(char *args[], int vec_length, int *vec_x, int *vec_y);
void compute_scalar_product(int vec_length, int *vec_x, int *vec_y, int *result_scalar);
void display_result(int *result_scalar);

/* Main driver function */
int main(int arg_count, char *args[])
{
    int vector_length = atoi(args[1]);
    int *vector_x = (int *)malloc(vector_length * sizeof(int));
    int *vector_y = (int *)malloc(vector_length * sizeof(int));
    int scalar_product = 0;

    extract_vectors_from_args(args, vector_length, vector_x, vector_y);
    compute_scalar_product(vector_length, vector_x, vector_y, &scalar_product);

    display_result(&scalar_product);

    free(vector_x);
    free(vector_y);

    return EXIT_SUCCESS;
}

/* Extracts two vectors from command line arguments */
void extract_vectors_from_args(char *args[], int vec_length, int *vec_x, int *vec_y)
{
    for (int i = 0; i < vec_length; ++i)
    {
        vec_x[i] = atoi(args[i + 2]);
        vec_y[i] = atoi(args[i + 2 + vec_length]);
    }
}

/* Computes the scalar product of two vectors */
void compute_scalar_product(int vec_length, int *vec_x, int *vec_y, int *result_scalar)
{
    for (int index = 0; index < vec_length; ++index)
    {
        *result_scalar += vec_x[index] * vec_y[index];
    }
}

/* Displays the result of the scalar product computation */
void display_result(int *result_scalar)
{
    printf("%d\n", *result_scalar);
}
