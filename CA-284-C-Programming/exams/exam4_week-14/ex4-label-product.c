/*
Program:
Author: Mahmoud Yousif
Date: 14/12/2023
Description: This program processes a list of items in a shopping cart, calculating the sales and updating
the status based on the average sales. It also determines the country of origin from the item code.

Approach: The program creates a linked list of items from the command line arguments, calculates the average
sales, updates the status of each item, prints the information, and then frees the allocated memory.
*/

/* Important Includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Struct to hold item information */
typedef struct Item
{
    char code[21];
    float price;
    int number_sold;
    int status;
    struct Item *next; /* Pointer to the next item for linked list */
} Item;

/* Function Prototypes */
Item *create_items(char *argv[], int len);
float calculate_average_sales(Item *head, int len);
void update_status(Item *head, float average);
void print_items_info(Item *head);

/* Main function: Program execution begins here */
int main(int argc, char *argv[])
{
    /* Each item has 3 arguments */
    int len = (argc - 1) / 3;

    /* Create linked list of items */
    Item *head = create_items(argv, len);

    /* Calculate average sales */
    float average_sales = calculate_average_sales(head, len);

    /* Update item status based on average sales */
    update_status(head, average_sales);

    print_items_info(head);

    /* Free the linked list to prevent memory leaks */
    Item *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

/* Create and populate a linked list of items from the command line arguments */
Item *create_items(char *argv[], int len)
{
    Item *head = NULL;
    Item *current = NULL;

    /* Iterate over each argument triplet (code, price, number_sold) */
    for (int i = 0; i < len; i++)
    {
        Item *new_item = malloc(sizeof(Item)); /* Allocate memory for a new item */

        /* Populate the item data */
        strncpy(new_item->code, argv[i * 3 + 1], 20);
        new_item->code[20] = '\0'; /* Ensure string termination */
        new_item->price = atof(argv[i * 3 + 2]);
        new_item->number_sold = atoi(argv[i * 3 + 3]);
        new_item->status = 0;  /* Initialize status to 0 */
        new_item->next = NULL; /* Initialize next pointer to NULL */

        /* Append new item to the linked list */
        if (i == 0)
        {
            head = new_item;
        }
        else
        {
            current->next = new_item;
        }
        current = new_item;
    }
    return head; /* Return the head of the linked list */
}

/* Calculating the average sales from the list of items */
float calculate_average_sales(Item *head, int len)
{
    float total_sales = 0.0;
    Item *current = head;

    /* Sum sales for each item in the list */
    while (current != NULL)
    {
        total_sales += current->price * current->number_sold;
        current = current->next;
    }
    return len ? (total_sales / len) : 0.0; /* Returning the average sales */
}

/* Update the status for each item based on the average sales */
void update_status(Item *head, float average)
{
    Item *current = head;

    /* Iterate through list and update status */
    while (current != NULL)
    {
        if ((current->price * current->number_sold) >= average)
        {
            current->status = 1; /* Set status to 1 if sales are above or equal to average */
        }
        current = current->next;
    }
}

/* Print the status and country of origin for each item */
void print_items_info(Item *head)
{
    Item *current = head;

    /* Iterate through list and print information */
    while (current != NULL)
    {
        printf("%d\n", current->status); /* Print status */
        /* Determine and print country of origin based on item code */
        if (strncmp(current->code, "IE", 2) == 0)
            printf("Ireland\n");
        else if (strncmp(current->code, "FR", 2) == 0)
            printf("France\n");
        else if (strncmp(current->code, "SP", 2) == 0)
            printf("Spain\n");
        else if (strncmp(current->code, "US", 2) == 0)
            printf("USA\n");
        else if (strncmp(current->code, "RU", 2) == 0)
            printf("Russia\n");
        else
            printf("Unknown\n");
        current = current->next;
    }
}
