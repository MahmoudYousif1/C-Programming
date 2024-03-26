/*
Program: lab11-longest-line.c
Author: Mahmoud Yousif
Date: 24/11/2023
Description:
Approach:
*/

/* Important Includes */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 200

int main(){
    FILE *pfile = NULL;
    char *filename = "paragraph.txt";
    pfile = fopen(filename, "r");
    if(!pfile)  
        printf("Failed to open %s.\n", filename);

    char para[MAX][MAX];
    int maxLength = 0;
    int maxLine = 0;
    int currentLength = 0;
    
    int currentLine = 0;
    while(fgets(para[currentLine], MAX, pfile)){
        currentLength = strlen(para[currentLine]);
        if(currentLength > maxLength){
            maxLength = currentLength;
            maxLine = currentLine;
        }
        currentLine++;               
    }

    printf("%d\n", maxLength);
    printf("%s\n", para[maxLine]);
    return 0;
}