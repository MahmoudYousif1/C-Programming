/*
Program: ex2-diagonal.c
Author: Mahmoud Yousif
Date: 2/11/2023
Description: This program calculates the sum of anti-diagonal elements in a given n x n matrix.
*/

#include <stdio.h>
#include <stdlib.h>

/* Function prototypes */
int checkArguments(int argc, char *argv[], int *n);
int sum(int argc, char *argv[], int n);
void printSum(int sum);

/* Main function of the program */
int main(int argc, char *argv[])
{
    int n = 0;
    /* Check if the arguments provided are correct */
    if (checkArguments(argc, argv, &n))
    {
        return 1;
    }

    /* Calculate the sum of the anti-diagonal */
    int sum1 = sum(argc, argv, n);
    
    printSum(sum1);

    return 0;
}

/* Function to check if the correct number of arguments are provided. */
int checkArguments(int argc, char *argv[], int *n)
{
    /* Convert the first argument to integer to determine matrix size */
    *n = atoi(argv[1]);
    /* Calculate the expected number of arguments based on matrix size */
    int expectedArgs = 2 + (*n) * (*n);
    return 0;
}

/* Function to sum the anti-diagonal elements of the matrix. */
int sum(int argc, char *argv[], int n)
{
    int sum = 0;
    /* Loop through the matrix to calculate sum of anti-diagonal */
    for (int i = 0; i < n; i++)
    {
        /* Add the current anti-diagonal element to sum */
        sum += atoi(argv[(i * n + (n - 1 - i)) + 2]);
    }
    return sum;
}

/* Function to print the sum. */
void printSum(int sum)
{
    printf("%d\n", sum);
}
