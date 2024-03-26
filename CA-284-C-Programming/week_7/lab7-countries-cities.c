/* 
Program: Lab7-countries-cities.c
Author: Mahmoud Yousif
Date: 31/10/2023
Description:
Approach:
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/* define a new type */
typedef struct Country Country;
typedef struct City City;

/* Define the new struct */
struct City
{
	char name[20];
	int size;
};

struct Country
{
	char name[20];
	City city[20];
};

City findLargestCitiesACountries(Country c);
void addCountries(Country c[], int argc, char*argv[]);

int main(int argc, char * argv[])
{
	Country country[50];
	int numberOfCountries = (argc - 1)/7;

	addCountries(country, argc, argv);

	for(int i = 0; i < numberOfCountries; ++i)
	{
		City largestCity = findLargestCitiesACountries(country[i]);
		printf("%s: %s\n", country[i].name, largestCity.name);
	}

	return 0;
}

void addCountries(Country c[], int argc, char*argv[])
{
	int numberOfCountries = (argc - 1)/7;
	
	int index = 1;
	for(int i = 0; i < numberOfCountries; ++i)
	{
		strcpy(c[i].name, argv[index]);		
		int indexCity = index + 1;
		for(int j = 0; j < 3; ++j)
		{
			strcpy(c[i].city[j].name, argv[indexCity]);
			c[i].city[j].size = atof(argv[indexCity + 1]);
			indexCity += 2;
		}	

		index = index + 7;
	}
}

City findLargestCitiesACountries(Country c)
{
	City largestCity = c.city[0];
	int maxSize = c.city[0].size;
	for(int i = 1; i < 3; ++i)
	{
		if(maxSize < c.city[i].size)
		{
			maxSize = c.city[i].size;
			largestCity = c.city[i];
		}
	}

	return largestCity;
}