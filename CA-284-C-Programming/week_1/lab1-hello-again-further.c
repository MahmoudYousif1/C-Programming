/*
Program: lab1-hello_again.c
Author: Your Name
Input: A full name
Output: Print out the given name
*/

/* includes */
#include <stdio.h>
#include <stdlib.h> /* a header file with a function we might need */

int main(int argc, char *argv[])
{
   /* Prints "hello" followed by a space and the first command-line argument*/
   printf("hello %s \n\n", argv[1]);

   /* Print "hello" followed by a newline character*/
   printf("hello \n%s \n\n", argv[1]);

   /* Prints "hello" followed by a question mark*/
   printf("Hello\? %s \n\n", argv[1]);

   /* Prints "hello" followed by a tab character*/
   printf("hello \t%s \n\n", argv[1]);

   /*Prints "hello" follwed by a backspace character*/
   printf("hello \b%s \n\n", argv[1]);

   /*Prints "hello followed by (" ") on either side */
   printf("hello \"%s\"\n\n", argv[1]);
}
