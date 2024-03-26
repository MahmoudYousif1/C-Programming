/*
Author: Mahmoud Yousif
date: 1/10/2023
description: this program accepts a sentence from the command line
and it returns the longest word in the sentence.

liberies used:

<string.h>
<stdio.h>
*/

/* Important includes */
#include <string.h>
#include <stdio.h>

/* Function Prototypes */
void getSentence(char array[], char *argv[]);
void longestword(char array[]);

/* Main Function */
int main(int argc, char *argv[])
{
    /* Creating an array to store the sentence */
    char array[40];

    /* Calling the getSentence() function to get the 
    sentence from the command line */
    getSentence(array, argv);

    /* Calling the longestword() function to find the longest word
    in the sentence */
    longestword(array);
    return 0;
}

/* this function creates an array to store the sentence */
void getSentence(char array[], char *argv[])
{
    /* getting the length of the sentence */
    int len = strlen(argv[1]);

    /* Copying each character of the sentence to the array */
    for (unsigned int i = 0; i < len; i++)
    {
        array[i] = argv[1][i];
    }

    array[len] = '\0';
}

/* Function to find and print the longest word in the array */
void longestword(char array[])
{
    /* Initialising Variables */

    /* this will store the longest word */
    char longest[60];

    /* current word */
    int current = 0;

    /* previous word */
    int prev = 0;

    /* this gets the length of the array */
    int len = strlen(array);

    for (int i = 0; i <= len; i++)
    {
        if (array[i] == ' ' || array[i] == '\0')
        {
            /* Check if the current word is longer than the previous longest word */
            if (current > prev)
            {
                /* Updating the maximum length and copying the current 
                word to store it in the longest variable */
                prev = current;
                strncpy(longest, &array[i - current], current);
                longest[current] = '\0'; // Null-terminate the string
            }

            /* Resetting the current length for the next word */
            current = 0;
        }
        else
        {
            /* increment the current word */
            current++;
        }
    }

    printf("%s\n", longest);
}
