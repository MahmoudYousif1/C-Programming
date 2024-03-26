/*
Program: is-triangular.c
Author: Mahmoud Yousif
Date: 0/0/0000
Description:

*/

/* Includes */

#include <stdio.h>
#include <stdlib.h>

/* Function Prototypes */

int get_triangular(int n);

/* Main function */

int main(int argc, char*argv[]){

    int number = atoi(argv[1]);

    if (get_triangular(number)){

        printf("%d is a triangular number\n", number);
    }

    else{

        printf("%d is not a triangular number\n", number);
    }


}

int get_triangular(int n){

    int num = 0;
    int terms = 0;

    while (terms <= n){

        terms = num * (num + 1) / 2;

        if (terms == n){

            return 1;
        }
        num++;
    }
    return 0;
}