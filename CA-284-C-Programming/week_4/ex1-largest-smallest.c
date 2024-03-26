/*
Author: Mahmoud Yousif
Date: 1/10/2023
description: this program takes an input from the command line and an array
of numbers and depending on whether the input is smallest or largest the program
will print either the smallest element or the largest element in the array.
*/

/* Important includes */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Prototypes */

void getArray(float array[], int len, char*argv[]);
float getLargest(float array[], int len);
float getSmallest(float array[], int len);

/* Main Function */

int main(int argc, char*argv[]){

    /* Initialsing variables */
    
    char*input = argv[1];
    int len = argc - 2;
    float array[len];

    /* Calling the getArray function to create the array */
    getArray(array, len, argv);

    /* strcmp is used to check if the word (largest) is at argv[1]. */
    if (strcmp(input, "largest") == 0){

        /* if the input is largest than the getLargest() function is called and the 
        largest element in the array is printed */

        float largest = getLargest(array, len);
        printf("%.2f\n", largest);
    }
    else if (strcmp(input, "smallest") == 0){

        /* if the input is smallest than the getSmallest() is called and the smallest
        element in the array is printed */

        float smallest = getSmallest(array, len);
        printf("%.2f\n", smallest);
    }

    return 0;
}

/* this function creates an array and loops through number to change it to a float */
void getArray(float array[], int len, char*argv[]){

    for (unsigned int i = 0; i < len; i++){

        array[i] = atof(argv[i + 2]);

    }
}

/* Function that takes in an array and the len of
the array and returns the largest element in the array */

float getLargest(float array[], int len){

    float largest = array[0];

    for (int i = 0; i < len; i++){

        if (array[i] > largest){

            largest = array[i];
        }
    }
    return largest;
}

/* Function that takes in an array and the len of
the array and returns the smallest element in the array */

float getSmallest(float array[], int len){

    float smallest = array[0];

    for (unsigned int i = 0; i < len; i++){

        if (array[i] < smallest){

            smallest = array[i];
        }
    }

    return smallest;
}
