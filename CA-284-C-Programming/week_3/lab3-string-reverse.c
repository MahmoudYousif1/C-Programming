/*
Author: Mahmoud Yousif
date: 29/9/2023
description: this program takes an input string from the command line and
reverses it.

*/

/* Important includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Prototypes */
void return_reverse(char string[]);

/* Main function */
int main(int argc, char *argv[]) {

    /* setting the character limit */
    char input[50];
    strcpy(input, argv[1]);

    /* Calling the return_reverse function to take an input of "input" */
    return_reverse(input);

    printf("%s\n", input);

    return 0;
}

/* this function is used to reverse a string.the for loop iterates through 
the first half of the string, swapping each character 
with its corresponding character from the end of the string.*/
void return_reverse(char string[]) {

    int len = strlen(string);

    for (int i = 0; i < len / 2; i++) {
        char reversed = string[i];
        string[i] = string[len - i - 1];
        string[len - i - 1] = reversed;
    }
}
