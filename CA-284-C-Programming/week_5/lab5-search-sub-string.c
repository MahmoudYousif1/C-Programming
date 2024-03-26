/*
Program: lab5-search-sub-string.c
Author: Mahmoud Yousif
Date: 16/10/2023
Description: this program takes 2 inputs from the cammand line, a string
and a sub string and it searches if the sub string is in the
main string and prints it's positions
*/

/* Important includes */
#include <stdio.h>
#include <string.h>

/* Function prototypes */
void finding_sub(char *string1, char *string2);

/* Main function */
int main(int argc, char *argv[]) {

    /* Get the main string and substring from command-line arguments */
    char *string1 = argv[1];
    char *string2 = argv[2];

    /* Calling the function to check and print positions */
    finding_sub(string1, string2);

    return 0;
}

/* Function to search for a substring in a main string and print positions */
void finding_sub(char *string1, char *string2) {
    /* Get the length of the main string and substring */
    int len1 = strlen(string1);
    int len2 = strlen(string2);

    /* Iterate through the main string */
    for (int i = 0; i <= len1 - len2; ++i) {
        int same = 1; /* Assume a match */

        /* Compare each character of the substring with the main string */
        for (int j = 0; j < len2; ++j) {
            if (string1[i + j] != string2[j]) {
                same = 0; /* No match found */
                break;
            }
        }

        /* If a match is found, print the positions and return */
        if (same) {
            printf("%d %d\n", i, i + len2 - 1);
            return;
        }
    }
}
