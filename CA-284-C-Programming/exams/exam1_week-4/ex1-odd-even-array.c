/*
Author: Mahmoud Yousif

Date: 1/10/2023

description: this program accepts an array of numbers and loops through the array
to find all the even and odd numbers.All the odd numbers are added together while
the even numbers are used to find the difference between all of them.

liberies used:

<stdlib.h>
<stdio.h>
<string.h>
*/

/* Important includes */

#include <stdio.h>
#include <stdlib.h>

/* Function Prototypes */
void getArray(int array[], int len, char *argv[]);
int getOdd(int array[], int len);
int getEven(int array[], int len);

/* Main Function */
int main(int argc, char *argv[])
{

    /* Initialising variables */

    /* Creating the length of the array */
    int len = argc - 1;

    /* initialising the array */
    int array[len];

    /* Calling the getArray() function to create the array */
    getArray(array, len, argv);

    /* Calling the getOdd() function to calculate any odd numbers and sum the total */
    int odd = getOdd(array, len);

    /* Calling the getEven() function to calculate any even numbers and
    subtracting all the numbers */
    int even = getEven(array, len);

    printf("%d\n%d\n", odd, even);

    return 0;
}

/* this function creates an array and loops through number to change 
it to a float */
void getArray(int array[], int len, char *argv[])
{

    for (int i = 0; i < len; i++)
    {
        array[i] = atoi(argv[i + 1]);
    }
}

/* this function Checks for any odd numbers and it sums all the odd 
numbers in the array */
int getOdd(int array[], int len)
{

    int totalOdd = 0;

    for (int i = 0; i < len; i++)
    {
        if (array[i] % 2 == 1)
        {
            totalOdd += array[i];
        }
    }

    return totalOdd;
}

/* this function first checks for the first even number so we don't start at 0.
then using a second for loop, all the other even numbers are found and the difference
between all of them is returned */
int getEven(int array[], int len)
{

    int even = 0;

    for (int i = 0; i < len; i++)
    {
        if (array[i] % 2 == 0)
        {
            even = array[i];
            break;
        }
    }

    int diff = even;

    for (int i = 1; i < len; i++)
    {
        if (array[i] % 2 == 0)
        {
            diff -= array[i];
        }
    }

    return diff;
}
