/*
Program: Lab6-average-population.c
Author: Mahmoud Yousif
Date: 31/10/2023
Description:
*/

/* Important Includes */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Structure definition */

typedef struct country
{

    char name[20];
    char cap[20];
    int size;
    float pop;
} country;

/* Function Prototypes */

int getcount(int argc);
void data(char *argv[], country countries[], int count);
void display(country countries[], int count);

/* Main Function */

int main(int argc, char *argv[])
{
    int count = getcount(argc);
    country countries[count];

    data(argv, countries, count);
    display(countries, count);
    return 0;
}

int getcount(int argc)
{

    return (argc - 1) / 4;
}

void data(char *argv[], country countries[], int count)
{

    int tracking = 1;

    for (unsigned int i = 0; i < count; i++)
    {

        strcpy(countries[i].name, argv[tracking++]);
        strcpy(countries[i].cap, argv[tracking++]);
        countries[i].pop = atof(argv[tracking++]);
        countries[i].size = atoi(argv[tracking++]);
    }
}

void display(country countries[], int count)
{

    printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n");

        for (int i = 0; i < count; i++)
    {

        printf("%s\t\t\t%s\t\t\t%d\t\t\t%.2f\n",

               countries[i].name,
               countries[i].cap,
               countries[i].size,
               countries[i].pop);
    }
}
