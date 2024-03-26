/*
Author: Mahmoud Yousif
program: lab3-calculator.c
date: 29/9/2023
description: the program takes in a command line 
input of multiply or divide
and depending on the input the program will either return a number
that is divided or multiplied
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function prototypes */

float multiply(float n1, float n2);
float divide(float n1, float n2);
void calculation(float n1, float n2, char input[]);

/* Main function */
int main(int argc, char *argv[])
{
    /* Initialising variables (atof converts variables from strings to floats)*/
    float n1 = atof(argv[2]); 
    float n2 = atof(argv[3]);
    char *input = argv[1];

    /* This calls the function calculation to operate on 2 numbers and a string */
    calculation(n1, n2, input);

    return 0;
}

/* this function returns 2 numbers that are multiplied */
float multiply(float n1, float n2)
{
    return (n1 * n2);
}

/* this function returns 2 numbers that are divided */
float divide(float n1, float n2)
{
    return (n1 / n2);
}

/* this function takes in 2 numbers and string.Depending on 
whether the string input is (multiply or divide) the 
function will perform the calculations based on the input 
*/
void calculation(float n1, float n2, char input[])
{   
/* if the input is (devide) then the divide function is called */
    if (strcmp(input, "divide") == 0 && n2 != 0)
    {
        printf("%f\n", divide(n1, n2));
    }
    /* if the input is (multiply) then the multiply function is called */

    else if (strcmp(input, "multiply") == 0)
    {
        printf("%f\n", multiply(n1, n2));
    }

    /* if the input is neither then "invalid" is returned */
    else
    {
        printf("invalid\n");
    }
}
