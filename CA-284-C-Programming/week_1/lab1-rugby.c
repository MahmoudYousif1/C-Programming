/*
filename: lab1-rugby.c
author: Mahmoud Yousif
*/

/*Necessary includes*/
#include <stdlib.h> /* contains functions we may need*/
#include <stdio.h>

/* Function: Main
 parameters: int argc (argument count)
 char *argv[] an array of command-line arguments
description:  Takes a single argument and computes area of circle
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s <tries> <conversions> <penalties> <drop_goals>\n", argv[0]);
        return 1; // Return a non-zero value to indicate an error.
    }

    int try, conversion, penalty, drop_goal, sum;

    try = atoi(argv[1]) * 5;
    conversion = atoi(argv[2]) * 2;
    penalty = atoi(argv[3]) * 3;
    drop_goal = atoi(argv[4]) * 3;

    sum = try + conversion + penalty + drop_goal;

    printf("%d\n", sum);

    return 0;
}
