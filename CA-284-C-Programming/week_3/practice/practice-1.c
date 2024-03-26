/*
Author: Mahmoud Yousif
date: 29/9/2023

description: this program takes a input of (multiply or devide) and 2 numbers
and depending on the input the program will either multiply or divide them

liberies:
<stdlib.h>
<stdio.h>
<string.h>
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* Function Prototypes */

float multiply(float n1, float n2);
float divide(float n1, float n2);
void calc(float n1, float n2, char input[]);


/* Main function */

int main(int argc, char*argv[]){

    char input[50];
    strcpy(input, argv[1]);
    float n1 = atof(argv[2]);
    float n2 = atof(argv[3]);

    calc(n1, n2, input);
    return 0;
}


float multiply(float n1, float n2){

    return(n1 * n2);
}


float divide(float n1, float n2){

    return(n1 / n2);
}

void calc(float n1, float n2, char input[]){

    if (strcmp(input, "multiply") == 0){

        printf("%f\n", multiply(n1, n2));
    }
    else if (strcmp(input, "divide") == 0 && n2 != 0){

        printf("%f\n", divide(n1, n2));
    }

    else{

        printf("invalid\n");
    }
}