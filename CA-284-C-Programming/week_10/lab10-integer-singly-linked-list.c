/*
Program: lab10-integer-singly-linked-list.c
Author: Mahmoud Yousif
Date: 23/11/2023
*/

/* Important Includes */
#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node
{
    int value;
    struct Node *next;
};

// Function prototypes
struct Node *createNode(int value);
void insertAtEnd(struct Node **head, int value);
void displayList(struct Node *head);
void freeList(struct Node *head);

// Function pointer prototypes
typedef void (*DisplayFunction)(struct Node *);
typedef void (*InsertFunction)(struct Node **, int);

int main(int argc, char *argv[])
{

    struct Node *head = NULL;
    InsertFunction insert = insertAtEnd;
    DisplayFunction display = displayList;

    for (int i = 2; i < argc; i++)
    { // Start from the third argument (index 2)
        int value = atoi(argv[i]);
        insert(&head, value);
    }

    display(head);
    freeList(head);
    return 0;
}

// Function to create a new node
struct Node *createNode(int value)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node **head, int value)
{
    struct Node *newNode = createNode(value);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to display the list
void displayList(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d\n", current->value);
        current = current->next;
    }
}

// Function to free the list memory
void freeList(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }
}
