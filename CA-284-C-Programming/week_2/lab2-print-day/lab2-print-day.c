/*
Program: lab2-print-day.c
Author: Mahmoud Yousif
Date: 23/09/2023

Description:
this programme takes a command line input in the
form of an integer and it returns the day based on the number

libraries:
#include <stdio.h>
#include <stdlib.h>

*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    /* initialising variables */

    int day = atoi(argv[1]);

    /* returns the day based on the integer input */
    if (day == 1)
    {
        printf("Sunday\n");
    }
    else if (day == 2)
    {
        printf("Monday\n");
    }
    else if (day == 3)
    {
        printf("Tuesday\n");
    }
    else if (day == 4)
    {
        printf("Wednesday\n");
    }
    else if (day == 5)
    {
        printf("Thursday\n");
    }
    else if (day == 6)
    {
        printf("Friday\n");
    }
    else if (day == 7)
    {
        printf("Saturday\n");
    }
    return 0;
}