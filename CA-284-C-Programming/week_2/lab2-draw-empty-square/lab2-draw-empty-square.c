/*
Program: lab2-draw-empty-spuare.c
Author: Mahmoud Yousif
Date: 23/09/2023

Description:
this programme takes a command line arguement 
and uses a for loop to print out a square shape

libraries:
#include <stdio.h>
#include <stdlib.h>

*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){

    /* initialising variables */
    int rows = atoi(argv[1]);
    
    /* for loop that checks if if i or j is == 1 and if it is, 
    a "*" is printed and if it's not then a space will be printed.
    this creates a square shape*/
    
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= rows; j++) {
            if (i == 1 || i == rows || j == 1 || j == rows){
                printf("*");
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
