/* 
Program: lab6-get-countries.c
Author: Mahmoud Yousif
Date: 21/10/2023
Description:this program organizes and displays information about multiple countries, 
with each country's details structured using the Country type.
*/

/* Important Includes */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Type definition */
typedef struct Country Country;

/* Structure definition */
struct Country
{
    char name[20];
    char capital[20];
    float population;
    int size;
};

/* Function prototypes */
int calculateNumberOfCountries(int argc);
void fillCountryDetails(int argc, char *argv[], Country countries[], int numberOfCountries);
void displayHeader();
void displayCountry(Country *country);

/* Main driver function */
int main(int argc, char *argv[])
{
    /* Calculate the number of countries based on the number of arguments */
    int numberOfCountries = calculateNumberOfCountries(argc);

    /* Declare an array of Country structures to store information for each country */
    Country countries[numberOfCountries];

    /* Fill in the details of each country from command-line arguments */
    fillCountryDetails(argc, argv, countries, numberOfCountries);

    /* Display the header for country information */
    displayHeader();

    /* Loop through each country and display its information */
    for (int i = 0; i < numberOfCountries; ++i)
    {
        displayCountry(&countries[i]);
    }

    return 0;
}

/* Calculate the number of countries based on the number of arguments */
int calculateNumberOfCountries(int argc)
{
    return (argc - 1) / 4;
}

/* Fill in the details of each country from command-line arguments */
void fillCountryDetails(int argc, char *argv[], Country countries[], int numberOfCountries)
{
    /* Initialize the index for accessing command-line arguments */
    int index = 1;

    /* Loop through each country and fill in the details */
    for (int i = 0; i < numberOfCountries; ++i)
    {
        /* Copy information from command-line arguments to the Country structure */
        strcpy(countries[i].name, argv[index]);
        strcpy(countries[i].capital, argv[index + 1]);
        countries[i].population = atof(argv[index + 2]);
        countries[i].size = atoi(argv[index + 3]);

        /* Move to the next country by increasing the index by 4 */
        index += 4;
    }
}

/* Display the header for country information */
void displayHeader()
{
    printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n");
}

/* Display the details of a country */
void displayCountry(Country *country)
{
    /* Print the details of the country */
    printf("%s\t\t\t%s\t\t\t%d\t\t\t%.2f\n", country->name, country->capital, country->size, country->population);
}
