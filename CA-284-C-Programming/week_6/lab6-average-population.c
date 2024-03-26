/* 
Program: Lab6-average-population.c
Author: Mahmoud Yousif
Date: 30/10/2023
Description:This code defines and manages information about a list of countries, 
specifically their names, capitals, populations, sizes and returns the average population.
*/

/* Important Includes */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Structure definition for Country */
typedef struct Country {
    char name[20]; 
    char capital[20];
    float population;
    int size;
} Country;

/* Function prototypes */
int getCountryCount(int argc);
void extractCountryData(char *argv[], Country countries[], int count);
void displayCountries(Country countries[], int count);
float averagePopulation(Country countries[], int count);

int main(int argc, char *argv[])
{
    int count = getCountryCount(argc);
    Country countries[count];
    
    extractCountryData(argv, countries, count);
    displayCountries(countries, count);
    
    printf("Population average: %.2f\n", averagePopulation(countries, count));
    return 0;
}

int getCountryCount(int argc)
{
    return (argc - 1) / 4;
}

void extractCountryData(char *argv[], Country countries[], int count)
{
    int argIndex = 1;
    for (int i = 0; i < count; ++i)
    {
        strcpy(countries[i].name, argv[argIndex++]);
        strcpy(countries[i].capital, argv[argIndex++]);
        countries[i].population = atof(argv[argIndex++]);
        countries[i].size = atoi(argv[argIndex++]);
    }
}

void displayCountries(Country countries[], int count)
{
    printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n");
    for (int i = 0; i < count; ++i)
    {
        printf("%s\t\t\t%s\t\t\t%d\t\t\t%.2f\n",
               countries[i].name, 
               countries[i].capital, 
               countries[i].size, 
               countries[i].population);
    }
}

float averagePopulation(Country countries[], int count)
{
    float total = 0.0;
    for (int i = 0; i < count; ++i)
    {
        total += countries[i].population;
    }
    return total / count;
}
