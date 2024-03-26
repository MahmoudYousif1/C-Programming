/*
Program: Lab6-cal-everything.c
Author: Mahmoud Yousif
Date: 20/10/2023
description: this code demonstrates the use of function pointers and 
arrays of function pointers to perform different operations on two 
integers.
Solution: 
*/

/*Important Includes*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prototypes
typedef float (*Operation)(int, int);

float add(int a, int b);
float subtract(int a, int b);
float multiply(int a, int b);
float divide(int a, int b);
float exponentiate(int base, int exponent);
float logarithm(int a, int b);

void performCalculations(int operand1, int operand2, Operation operations[], int num_operations);

int main(int argc, char *argv[]) {

    // Initialize variables
    int operand1 = atoi(argv[1]);
    int operand2 = atoi(argv[2]);

    // Array of operation functions
    Operation operations[] = {add, subtract, multiply, divide, exponentiate, logarithm};
    int num_operations = sizeof(operations) / sizeof(operations[0]);

    // Perform calculations and print results
    performCalculations(operand1, operand2, operations, num_operations);

    return 0;
}

// Operation functions
float add(int a, int b) { return a + b; }
float subtract(int a, int b) { return a - b; }
float multiply(int a, int b) { return a * b; }

// Check for division by zero and perform division
float divide(int a, int b) {
    return (float)a / b;
}

float exponentiate(int base, int exponent) {
    float result = 1;
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}

float logarithm(int a, int b) {
    return log(a) + log(b);
}

// Perform calculations and print results
void performCalculations(int operand1, int operand2, Operation operations[], int num_operations) {
    float result = 0;
    
    for (int i = 0; i < num_operations; ++i) {
        result = operations[i](operand1, operand2);
        printf("%.2f\n", result);
    }
}
