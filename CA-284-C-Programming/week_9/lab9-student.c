/*
Program: lab9-student.c
Author: Mahmoud Yousif
Date: 14/11/2023
Description:
Approach:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *program;
    float grade;
} Student;

Student *allocateStudents(int count);
char *duplicateString(const char *src);
void readStudentInfo(Student *students, int count, char **argv);
void printStudentInfo(Student *students, int count);
void freeStudents(Student *students, int count);

int main(int argc, char *argv[]) {

    int studentCount = (argc - 1) / 3;
    Student *students = allocateStudents(studentCount);
    
    readStudentInfo(students, studentCount, argv);
    printStudentInfo(students, studentCount);
    freeStudents(students, studentCount);

    return 0;
}

Student *allocateStudents(int count) {
    return (Student *)malloc(count * sizeof(Student));
}

char *duplicateString(const char *src) {
    char *dst = malloc(strlen(src) + 1);
    if (dst == NULL) return NULL;
    strcpy(dst, src);
    return dst;
}

void readStudentInfo(Student *students, int count, char **argv) {
    for (int i = 0; i < count; ++i) {
        students[i].name = duplicateString(argv[i * 3 + 1]);
        students[i].program = duplicateString(argv[i * 3 + 2]);
        students[i].grade = atof(argv[i * 3 + 3]);
    }
}

void printStudentInfo(Student *students, int count) {
    for (int i = 0; i < count; ++i) {
        printf("%s, %s, %.2f\n", students[i].name, students[i].program, students[i].grade);
    }
}

void freeStudents(Student *students, int count) {
    for (int i = 0; i < count; ++i) {
        free(students[i].name);
        free(students[i].program);
    }
    free(students);
}
