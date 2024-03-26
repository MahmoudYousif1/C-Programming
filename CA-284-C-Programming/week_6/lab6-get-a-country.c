/*
Program: Lab6-get-a-country.c
Author: Mahmoud Yousif
Date: 20/10/2023
Description: this program demonstrates the use of a structure to 
organize and display information about a geographic location, 
with data provided through command-line arguments
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Type definition */
typedef struct GeoLocation GeoLocation;

/* Structure definition */
struct GeoLocation
{
    /* Initialising */
    char region[20];
    char mainCity[20];
    float inhabitants;
    int landArea;
};

/* Function prototypes */
void displayGeoLocation(GeoLocation *location);

/* Main driver function */
int main(int argc, char *argv[])
{
    /* Declare and initialize a GeoLocation structure */
    GeoLocation location;
    GeoLocation *locationPtr = &location;

    /* Copy command-line arguments to the GeoLocation structure */
    strcpy(locationPtr->region, argv[1]);
    strcpy(locationPtr->mainCity, argv[2]);
    locationPtr->inhabitants = atof(argv[3]);
    locationPtr->landArea = atoi(argv[4]);

    /* Call the displayGeoLocation function to print details */
    displayGeoLocation(locationPtr);

    return 0;
}

/* Print out the details of the geographical location */
void displayGeoLocation(GeoLocation *locationPtr)
{
    /* Print the region, main city, population, and land area */
    printf("%s\n", locationPtr->region);
    printf("%s\n", locationPtr->mainCity);
    printf("%.2f million people\n", locationPtr->inhabitants);
    printf("%d km2\n", locationPtr->landArea);
}
