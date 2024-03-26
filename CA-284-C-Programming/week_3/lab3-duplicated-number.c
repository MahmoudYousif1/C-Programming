/*
Author: Mahmoud Yousif
Date: 30/9/2023
description: this program finds any duplicated numbers in array and
returns that number

liberies:
<stdio.h>
<stdlib.h>

*/

/* Important Includes */
#include <stdlib.h>
#include <stdio.h>

/* Function Prototypes */
int findDuplicates(int array[], int len);

/* Main function */
int main(int argc, char *argv[])
{
    /* Initialising variables */

    /* Setting the array */
    int array[argc - 1];

    /* Creating the length of the array */
    int len = argc - 1;

    /* this loop converts every number in the array to an integer using atoi*/
    for (int i = 1; i < argc; i++)
    {
        array[i - 1] = atoi(argv[i]);
    }

    /* calling the function findDuplicates()*/
    findDuplicates(array, len);
    return 0;
}

/* this function checks to see if the first number is the same as the next number
and if this statement is true, then the program returns the first number that has duplicates.*/
int findDuplicates(int array[], int len)
{
    /* Keeping tracking of the amount of duplicates */
    int tracking = 0;

    /* looping through the first number and the ones after it and if they
    are equal, the number that has a duplicate is printed */
    for (int i = 0; i < len; i++)
    {
        for (int next = i + 1; next < len; next++)
        {
            if (array[i] == array[next])
            {
                printf("%d\n", array[i]);
                tracking = 1;
                return 0;
            }
        }
    }

    /* if there are no duplicates then this printf statement is run */
    if (tracking != 1){

        printf("no duplicated number\n");
    }
    return 0;
}
