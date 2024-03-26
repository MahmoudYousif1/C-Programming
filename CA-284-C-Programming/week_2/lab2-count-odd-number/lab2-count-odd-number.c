/*
Program: lab2-count-odd-number.c
Author: Mahmoud Yousif
Date: 23/09/2023

Description:
this programme takes in an array of numbers 
and loops through them to count the amount of odd numbers

libraries:
#include <stdio.h>
#include <stdlib.h>

*/

/* Import includes */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){

    /* initialising variables */
    int length = argc - 1;
    int numbers[length];
    int total = 0;

    /* this for loops goes through every number in the array 
    and checks if it is odd or even using (numbers[i] % 2).
    If the number is odd, it is then added to the total.*/

    for ( unsigned  i = 0; i < length; i++) {
        numbers[i] = atoi(argv[i + 1]);

        if (numbers[i] % 2 == 1) {
            total++;
        }
    }

    printf("%d\n", total);

    return 0;
}

