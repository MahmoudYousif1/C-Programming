/*
Author: Mahmoud Yousif
date: 30/9/2023
description: this program accepts an array of numbers and
returns the largest element

liberies used:
<stdlib.h>
<stdio.h>

*/

/* Important includes */
#include <stdlib.h>
#include <stdio.h>

/* Function Prototpyes */

void findMax(int array[], int len);


/* Main Function */

int main(int argc, char *argv[])
{
    /* setting the array */
    int array[argc - 1];

    /* Setting the lengnth of the array */
    int len = argc - 1;

    /* this loops through each number in the array 
    and changes into integers */
    for (int i = 1; i < argc; i++)
    {
        array[i - 1] = atoi(argv[i]);
    }

    // Call the findMax function with the array and its length
    findMax(array, len);

    return 0;
}

/* The maximum number is calculated with this function. */
void findMax(int array[], int len)
{
    int max = array[0];

    
    for (int i = 0; i < len; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    printf("%d\n", max);
}