/*
file: Converting-units.c
author: Mahmoud Yousif
*/

/* includes*/
#include <stdio.h>  /* provides functions for inputs and outputs */
#include <stdlib.h> /* Includes necessary functions for memory, etc*/

/* Function: Main
 parameters: int argc (argument count)
 char *argv[] an array of command-line arguments
description:  Takes a single argument and converts from centimetres
to inches.
 */

int main(int argc, char *argv[])
{
    /* variable initialisation */
    float input = 0.0;
    float centemetres = 2.54;
    float output_inches = 0.0;

    /* atoi changes command line inputs into ints */
    input = atoi(argv[1]);

    output_inches = input / centemetres; /* calculates the inches by dividing the input by the centemetres */
    
    printf("%.2f\n", output_inches); /* prints output*/
    return (0);                      /* ends program*/
}