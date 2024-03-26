/*
Program: lab5-find-most-character.c
Author: Mahmoud Yousif
Date: 16/10/2023
Description: This program takes a command-line argument and 
finds the most frequent  character in the string.
*/

/* Important includes */
#include <stdio.h>
#include <string.h>
#include <ctype.h> /* Includes functions that help determine the type of characters */

/* Function prototypes */
char Frequent(char *input);

/* Main function */
int main(int argc, char *argv[])
{
    /* Initialising variables */
    char *input1 = argv[1];

    /* Call the Frequent function to find the most frequent character */
    char output = Frequent(input1);

    /* Print the result */
    printf("%c\n", output);

    return 0;
}

/* this function finds the most frequent alphabetical character in a string */
char Frequent(char *array)
{
    /* Initialising variables */
    char mostFrequent; /* The most frequent character */
    int mostfr = -1;    /* The frequency count of the most frequent character */

    /* Iterate through the input string */
    while (*array != '\0')
    {
        /* Check if the current character is an alphabetical character */
        if (isalpha(*array))
        {
            char currentChar = tolower(*array); /* Convert to lowercase for case-insensitivity */
            int count = 0;                       /* Counter for the current character */

            /* Iterate through the rest of the string */
            char *current = array;
            while (*current != '\0')
            {
                /* Check if the current character is an alphabetical character
                 * and if it matches the currentChar */
                if (isalpha(*current) && tolower(*current) == currentChar)
                {
                    ++count; /* Increment the count for the current character */
                }
                ++current; /* Move to the next character in the string */
            }

            /* Update mostFrequent and maxFrequency if the current character has a higher count */
            if (count > mostfr)
            {
                mostfr = count;
                mostFrequent = currentChar;
            }
        }

        ++array; /* Move to the next character in the string */
    }

    return mostFrequent;
}
