/*
Program: lab11-load-binary.c
Author: Mahmoud Yousif
Date: 24/11/2023
Description:
Approach:
*/

/* Important Includes */

#include <stdio.h>
#include <stdlib.h>

/* Define a structure to hold student data */
typedef struct
{
    char *name;
    char *college;
    int age;
    float grade;
} Student;

/* Function prototypes */
void readString(FILE *file, char **str);
void readAgeAndGrade(FILE *file, int *age, float *grade);
void displayStudent(const Student *student);
void freeStudent(Student *student);

int main()
{
    /* Open the binary file for reading */
    FILE *file = fopen("studentBinary.bin", "rb");

    while (1)
    {
        Student student;

        /* Read the student name and check for EOF */
        readString(file, &student.name);
        if (student.name == NULL)
            break;

        /* Read the college name */
        readString(file, &student.college);

        /* Read the age and grade of the student */
        readAgeAndGrade(file, &student.age, &student.grade);

        /* Display the student's information */
        displayStudent(&student);

        /* Free the dynamically allocated memory for the student */
        freeStudent(&student);
    }

    /* Close the file */
    fclose(file);
    return 0;
}

/* Function to read a string from the binary file */
void readString(FILE *file, char **str)
{
    int length;
    /* Read the length of the string and allocate memory */
    if (fread(&length, sizeof(int), 1, file) != 1)
    {
        *str = NULL;
        return;
    }
    *str = malloc(length + 1);
    /* Read the string from the file */
    fread(*str, sizeof(char), length, file);
    (*str)[length] = '\0'; /* Null-terminate the string */
}

/* Function to read the age and grade of a student from the binary file */
void readAgeAndGrade(FILE *file, int *age, float *grade)
{
    fread(age, sizeof(int), 1, file);
    fread(grade, sizeof(float), 1, file);
}

/* Function to display a student's information */
void displayStudent(const Student *student)
{
    printf("Name: %s\n", student->name);
    printf("College: %s\n", student->college);
    printf("Age: %d\n", student->age);
    printf("Grade: %.2f\n", student->grade);
}

/* Function to free the dynamically allocated memory of a student */
void freeStudent(Student *student)
{
    free(student->name);
    free(student->college);
}
