/*
Author: Mahmoud Yousif
Date: 1/10/2023
description: this program takes an array of years and it calculates all
the leap years between the first arguement and the second arguement.


liberies used:

<stdio.h>
<stdlib.h>
<string.h>

*/

/* important includes */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Prototypes */

void getArray(int array[], int len, char *argv[]);
void calc_Leapyear(int array[], int len);

/* Main function */

int main(int argc, char *argv[])
{
    /* initialising variables */

    /* Creating the length of the area */
    int len = argc - 1;

    /* Creating the array and setting it's length to the variable len */
    int array[len];

    /* Calling the getArray() function to create the array from 
    the command line */
    getArray(array, len, argv);

    /* Calling the calc_Leapyear function to find the leap years */
    calc_Leapyear(array, len);
}

/* this function is used to create an array of years */
void getArray(int array[], int len, char *argv[])
{
    /* for every number in the array, this for loop will change it into an
     integer */
    for (unsigned int i = 0; i < len; i++)
    {

        array[i] = atoi(argv[i + 1]);
    }
}

void calc_Leapyear(int array[], int len)
{
    /* Initialising variables */
    int y1 = array[0];
    int y2 = array[1];

    /* Creates a range of years */
    for (int year = y1; year <= y2; year++)
    {
        /* this code checks if a year is a leap year */
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        {
            printf("%d\n", year);
        }
    }
}