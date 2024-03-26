/*
Program:
Author: Mahmoud Yousif
Date: 14/12/2023
Description: This program evaluates student attendance records
inputted as command-line arguments, determines attendance status
based on absences and lateness, and outputs each student's status.

Approach: Manage memory for attendance data,
process records for absences, output and clean up.
*/

/* Important Includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Struct definition for holding attendance information */
typedef struct
{
    char *record; /* Pointer to a string holding attendance marks */
    int status;   /* Attendance status: 0 for less than 3 absences, 1 for 3 or more */
} Records;

/* Function Prototypes */
void getInputs(char *argv[], Records *attendance, int len);
void checkingAttendance(Records *attendance, int len);
void print1(Records *attendance, int len);
void free1(Records **attendance, int len);

/* Main function: Entry point of the program */
int main(int argc, char *argv[])
{
    /* Calculate the number of attendance records based on command line arguments */
    int len = argc - 1;

    /* Dynamically allocate memory for attendance records */
    Records *attendance = calloc(len, sizeof(Records));

    /* Read and store the attendance records from command line arguments */
    getInputs(argv, attendance, len);

    /* Process the records to determine attendance status */
    checkingAttendance(attendance, len);

    print1(attendance, len);

    free1(&attendance, len);

    return 0;
}

/* Function to read command line arguments and initialize Record structs */
void getInputs(char *argv[], Records *attendance, int len)
{
    for (int i = 0; i < len; i++)
    {
        /* Allocate memory for each attendance record string */
        attendance[i].record = malloc(strlen(argv[i + 1]) + 1);

        /* Check for successful allocation before copying */
        if (attendance[i].record)
        {
            /* Copy the record from arguments into allocated memory */
            strcpy(attendance[i].record, argv[i + 1]);
        }
        else
        {
            /* Exit if memory allocation fails */
            exit(1);
        }
    }
}

/* Function to check attendance records and update status accordingly */
void checkingAttendance(Records *attendance, int len)
{
    for (int i = 0; i < len; i++)
    {
        int missing_days = 0; /* Counter for absent days */

        /* Iterate over each character in the attendance record */
        for (int j = 0; j < strlen(attendance[i].record); j++)
        {
            /* Increment counter if 'A' (Absent) is found */
            if (attendance[i].record[j] == 'A')
            {
                missing_days++;
                /* Check for three consecutive 'L's (Late) and treat as one absence */
            }
            else if (j < strlen(attendance[i].record) - 2 &&
                     attendance[i].record[j] == 'L' &&
                     attendance[i].record[j + 1] == 'L' &&
                     attendance[i].record[j + 2] == 'L')
            {
                missing_days++;
                j += 2; /* Skip the next two 'L's */
            }
        }
        /* Update status based on missing days */
        attendance[i].status = missing_days >= 3 ? 1 : 0;
    }
}

/* Function to print the attendance status for each student */
void print1(Records *attendance, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d\n", attendance[i].status);
    }
}

/* Function to free dynamically allocated memory for records */
void free1(Records **attendance, int len)
{
    if (attendance && *attendance)
    {
        /* Free each individual attendance record string */
        for (int i = 0; i < len; i++)
        {
            free((*attendance)[i].record);
        }
        free(*attendance);
        /* Setting the pointer to NULL to prevent dangling references */
        *attendance = NULL;
    }
}
