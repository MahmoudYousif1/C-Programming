/*
Program: lab2-cyclinder-area.c
Author: Mahmoud Yousif
Date: 23/09/2023

Description:
this program takes 2 command line arguements and 
calculates the area of a cyclinder using this formula: A=2πrh+2πr2

libraries:
#include <stdio.h>
#include <stdlib.h>

*/

#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415
int main(int argc, char *argv[]) {
    /* Checking if there is an input argument or not */
    if (argc == 1) {
        printf("No input was given\n");
        return 1;
    }

    /* Checking if there are exactly two command-line arguments */
    if (argc != 3) {
        printf("Two arguments needed\n");
        return 1;
    }

    /* Initializing variables */
    float total_area = 0.0;
    float radius = atoi(argv[1]);
    float height = atoi(argv[2]);

    /* Checking if the radius or the height is negative */
    if (radius < 0) {
        printf("The radius cannot be negative\n");
        return 1;
    }

    if (height < 0) {
        printf("The height cannot be negative\n");
        return 1;
    }

    /* Calculating the area of a cylinder */
    total_area = (2 * PI * radius * height) + (2 * PI * (radius * radius));
    printf("%.2f\n", total_area);

    return 0;
}


