/* Program: lab5-count-character.c
Author: Mahmoud Yousif
Date: 12/10/2023
Description: this program takes 2 arguements from the command line.The
first arguement checks if the it's character is in the second arguement.
this process repeats until the end of the array where the total is
calculated
*/

/* Important includes */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Function Prototypes */
void sentence(char input[], char *argv[]);

/* Main Function */
int main(int argc, char *argv[])
{
    /* Initialising variables */
    char input[100];

    /* Calling the function to take the inputs */
    sentence(input, argv);

    return 0;
}

/* this function creates an array of characters from the command line
starting from the second index onwards and using the first index to check
if the character at the first index is in the array. If this is true, then
it will be added to the total */
void sentence(char input[], char *argv[])
{
    /* Initialising Variables */
    int len = strlen(argv[2]);
    int total = 0;
    
    /* Using a pointer to the second element of the input array */
    char *index1 = &input[0];
    
    for (int i = 0; i < len; i++)
    {
        /* copying and creating the array of characters */
        input[i] = argv[2][i];

        /* checking if the character at the first index is equal to
        any characters in the array, and the total is counted */
        if (*index1 == input[i])
        {
            total += 1;
        }
    }

    /* Null-terminating the input array to make it a valid string */
    input[len] = '\0';

    printf("%d\n", total);
}

