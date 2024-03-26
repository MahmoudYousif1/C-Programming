/*
Author: Mahmoud Yousif
Date: 30/9/2023
description: this program takes a string command line arguement and returns
it's reverse version/

liberies:
<stdlib.h>
<stdio.h>
<string.h>

*/

/* Important incldues */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Function Prototypes */

void returnReverse(char input[]);


/* Main function */

int main(int argc, char*argv[]){

    char input[50];
    strcpy(input, argv[1]);

    returnReverse(input);
    return 0;

}


void returnReverse(char input[]){

    int len = strlen(input);

    for (int i = 0; i < len / 2; i++){

        char temp = input[i];
        input[i] = input[len - i - 1];
        input[len - i - 1] = temp;
    }
    
    printf("%s\n", input);
}