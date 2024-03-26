/*
Program: lab9-longest-sentence.c
Author: Mahmoud Yousif
Date: 14/11/2023
Description:
Approach:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function prototypes */
int findMaxLength(int argc, char *argv[]);
void printLongestStrings(int argc, char *argv[], int maxLength);

int main(int argc, char *argv[]) {

    int maxLength = findMaxLength(argc, argv);
    printLongestStrings(argc, argv, maxLength);

    return 0;
}

/* Function to find the maximum length among the strings */
int findMaxLength(int argc, char *argv[]) {
    int maxLength = 0;
    for (int i = 1; i < argc; i++) {
        int length = strlen(argv[i]);
        if (length > maxLength) {
            maxLength = length;
        }
    }
    return maxLength;
}

/* Function to print the longest strings */
void printLongestStrings(int argc, char *argv[], int maxLength) {
    for (int i = 1; i < argc; i++) {
        if (strlen(argv[i]) == maxLength) {
            printf("%s\n", argv[i]);
        }
    }
}
