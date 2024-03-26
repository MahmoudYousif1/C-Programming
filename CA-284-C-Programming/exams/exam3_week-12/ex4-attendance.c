/* Program: ex3-find-frequent-modified.c
   Author: Mahmoud Yousif
   Date: 30/11/22
   Description: Identifies and prints elements appearing more than 3 
   times from command line input.

   Approach:
   1. get_inputs: Reads integers from command line.
   2. findelements: Identifies frequent elements.
   3. sort: Sorts elements using bubble sort.
   4. print1: Prints sorted frequent elements.
*/

/* Important Includes */
#include <stdio.h>
#include <stdlib.h>

/* Function prototypes */
void get_inputs(int argc, char *argv[], int **nums, int *sz);
void findelements(int *nums, int sz, int **freq, int *freqSz);
void sort(int *arr, int sz);
void swaping(int *x, int *y);
void print1(int *arr, int sz);

/* Main driver function */
int main(int argc, char *argv[])
{
    int *nums = NULL;
    int sz = 0;

    get_inputs(argc, argv, &nums, &sz);

    int *freq = NULL;
    int freqSz = 0;
    findelements(nums, sz, &freq, &freqSz);

    sort(freq, freqSz);
    print1(freq, freqSz);

    free(nums);
    free(freq);
    return 0;
}

/* Parse command line arguments to get integers */
void get_inputs(int argc, char *argv[], int **nums, int *sz)
{
    *sz = argc - 1;
    *nums = (int *)malloc(*sz * sizeof(int));
    for (int i = 1; i < argc; ++i)
    {
        (*nums)[i - 1] = atoi(argv[i]);
    }
}

/* Find frequent elements (appearing more than 3 times) */
void findelements(int *nums, int sz, int **freq, int *freqSz)
{
    *freq = (int *)malloc(sz * sizeof(int));
    *freqSz = 0;

    for (int i = 0; i < sz; ++i)
    {
        int ct = 0;
        for (int j = 0; j < sz; ++j)
        {
            if (nums[i] == nums[j])
            {
                ct++;
            }
        }

        if (ct > 3)
        {
            (*freq)[*freqSz] = nums[i];
            (*freqSz)++;
        }
    }
}

/* Sort the array using bubble sort */
void sort(int *arr, int sz)
{
    for (int i = 0; i < sz - 1; ++i)
    {
        for (int j = 0; j < sz - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                swaping(&arr[j], &arr[j + 1]);
            }
        }
    }
}

/* Swap two elements */
void swaping(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

/* Print the sorted array of frequent elements */
void print1(int *arr, int sz)
{
    for (int i = 0; i < sz; ++i)
    {
        printf("%d\n", arr[i]);
    }
}
