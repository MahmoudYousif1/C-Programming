/*
Program: lab1-hello-again-c
Author: Mahmoud Yousif
Date: 00/00/00

Description:
this program takes a name from the command line and
prints out hello followed by the name

approach:
Input: A full name
Output: Print out the given name

libraries:
#include <stdio.h>
#include <stdlib.h>

*/

/* includes */
#include <stdio.h>
#include <stdlib.h> /* a header file with a function we might need */

int main(int argc, char *argv[])
{
   printf("Hello %s\n", argv[0]);
   return (0);
}
