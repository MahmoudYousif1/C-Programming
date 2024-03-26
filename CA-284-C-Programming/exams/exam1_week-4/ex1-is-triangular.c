/*
program: ex1-is-triangular.c
Author: Mahmoud Yousif
date: 2/10/2023
description: this program accepts an integer of n from the command line
and checks whether it is a triangular number or not.
*/

/* Libaries used */

#include <stdio.h>
#include <stdlib.h>

/* Function Prototypes */
int triangular(int n);

/* Main function */
int main(int argc, char *argv[])
{
    int number = atoi(argv[1]);

    if (triangular(number))
    {
        printf("%d is a triangular number\n", number);
    }
    else
    {
        printf("%d is not a triangular number\n", number);
    }

    return 0;
}

int triangular(int num)
{
    int n = 0;
    int formula = 0;

    while (formula <= num)
    {
        formula = (n * (n + 1)) / 2;

        if (formula == num)
        {
            return 1;
        }
        n++;
    }
    return 0;
}
