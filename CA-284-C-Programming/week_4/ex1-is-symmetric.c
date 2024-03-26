/*
Author: Mahmoud Yousif
program: ex1-is-symmetric.c
Date: 1/10/2023
description: this program takes a string input from the command line 
and checks if is the string is the same backwards and forwards.
*/

/* Libaries used */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Prototypes */
void getSentence(char array[], char *argv[]);
void returnReverse(char array[], char *argv[]);

// Main Function
int main(int argc, char *argv[])
{
    // Declare two arrays to store the original and reversed strings
    char array1[50];
    char array2[50];

    // Call the getSentence function to copy the input string to array1
    getSentence(array1, argv);

    // Call the returnReverse function to reverse the string in array1 and store it in array2
    returnReverse(array2, argv);

    // Compare the original and reversed strings using strcmp
    if (strcmp(array1, array2) == 0)
    {
        // If the strings are the same, print "Yes"
        printf("Yes\n");
    }
    else
    {
        // If the strings are different, print "No"
        printf("No\n");
    }
    
    return 0;
}

// Function to copy the input string to an array
void getSentence(char array[], char *argv[])
{
    // Calculate the length of the input string
    int len = strlen(argv[1]);

    // Copy each character of the input string to the array
    for (int i = 0; i < len; i++)
    {
        array[i] = argv[1][i];
    }

    array[len] = '\0';
}

// Function to reverse the characters in an array
void returnReverse(char array[], char *argv[])
{
    int len = strlen(argv[1]);

    // Copy each character of the input string to the array
    for (int i = 0; i < len; i++)
    {
        array[i] = argv[1][i];
    }

    // Reverse the characters in the array
    for (int i = 0; i < len / 2; i++)
    {
        char temp = array[i];
        array[i] = array[len - i - 1];
        array[len - i - 1] = temp;
    }

    array[len] = '\0';
}
