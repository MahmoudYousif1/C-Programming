/*
Author: Mahmoud Yousif

Date: 1/10/2023

description: this program takes an input from the command line and runs it through
a hailstones function.The hailstones functions will return n / 2 is n is even and will
multiply by 3 and add 1 is n is odd.This will return an array of numbers until n is 1.

*/

/* Important include */

#include <stdio.h>
#include <stdlib.h>

/* Function prototypes */

void getHailstones(int n);

/* Main function */

int main(int argc, char *argv[])
{
    /* Initialising variables */

    int num1 = atoi(argv[1]);

    /* Calling the getHailstones() function and executing it */
    getHailstones(num1);

    return 0;
}

void getHailstones(int n)
{
    /* Printing the original input */

    printf("%d ", n);

    /* this while loop runs until n = 1. if n % 2 is odd then 
    multiply it by 3 and add 1 to give n' = 3n + 1 and if n % 2 = 0
    then n is divided by 2*/
    while (n != 1)
    {
        if (n % 2 == 1)
        {
            n = 3 * n + 1;
        }
        else
        {
            n /= 2;
        }

        printf("%d ", n);
    }

    printf("\n");
}
