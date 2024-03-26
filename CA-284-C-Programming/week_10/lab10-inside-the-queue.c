/*
Program: lab10-inside-the-queue.c
Author: Mahmoud Yousif
Date: 23/11/2023
*/

/* Important Includes */

#include <stdio.h>
#include <stdlib.h>

/* Define the Node structure for the linked list */
struct Node
{
    int value;
    struct Node *next;
};

/* Function prototypes */
struct Node *createNode(int value);
void append(struct Node **head, int value);
void insertAfter(struct Node *prevNode, int value);
void displayList(struct Node *head);

int main(int argc, char *argv[])
{

    int memberToFind = atoi(argv[1]);
    int valueToInsert = atoi(argv[2]);

    /* Predefined list of numbers */
    int numbers[] = {8, 7, 3, 4, 5, 6, 9, 2, 14, 12};
    int n = sizeof(numbers) / sizeof(numbers[0]);

    struct Node *head = NULL;

    /* Initialize the linked list with predefined numbers */
    for (int i = 0; i < n; i++)
    {
        append(&head, numbers[i]);
    }

    /* Find the specified member and insert new integer after it */
    struct Node *current = head;
    while (current != NULL)
    {
        if (current->value == memberToFind)
        {
            insertAfter(current, valueToInsert);
            break;
        }
        current = current->next;
    }

    /* Display the updated list */
    displayList(head);

    /* Free the list memory */
    while (head != NULL)
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

/* Function to create a new node */
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

/* Function to append a value to the list */
void append(struct Node **head, int value)
{
    struct Node *newNode = createNode(value);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    struct Node *lastNode = *head;
    while (lastNode->next != NULL)
    {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
}

/* Function to insert a value after a given node */
void insertAfter(struct Node *prevNode, int value)
{
    if (prevNode == NULL)
    {
        printf("Previous node cannot be NULL\n");
        return;
    }
    struct Node *newNode = createNode(value);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

/* Function to display the list */
void displayList(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d\n", current->value);
        current = current->next;
    }
}
