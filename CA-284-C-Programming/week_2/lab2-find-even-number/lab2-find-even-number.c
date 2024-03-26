/*
Program: lab2-find-even-number.c
Author: Mahmoud Yousif
Date: 23/09/2023

Description:
loops through an array and determines the even numbers 
and then the programme prints out the even numbers with 
their indexes.

libraries:
#include <stdio.h>
#include <stdlib.h>

*/

/* Important includes */

#include <stdlib.h>
#include <stdio.h>

odd_or_even(int nums[], int len){

    int odd_nums = 0;
    int even_nums = 0;
    int i = 0;

    for (i = 0; i < len; i++) {
        
        if (nums[i] % 2 == 1) {
            odd_nums++;
        }
        else if (nums[i] % 2 == 0)
        {
            even_nums++;
        }
    }
    return even_nums;
    return odd_nums;
}

int main(int argc, char * argv[]){

    
}