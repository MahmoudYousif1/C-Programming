/*
Program: lab10-float-doubly-linked-list.c
Author: Mahmoud Yousif
Date:23/11/2023
*/

/* Important Includes */
#include <stdio.h>
#include <stdlib.h>

/* Define the Node structure for a doubly linked list */
struct Node
{
    float value;       /* Value of the node */
    struct Node *next; /* Pointer to the next node */
    struct Node *prev; /* Pointer to the previous node */
};

/* Function prototypes */
struct Node *createNode(float value);
void insertAtEnd(struct Node **head, struct Node **tail, float value);
void displayListReverse(struct Node *tail);
void freeList(struct Node *head);

/* Function pointer prototypes */
typedef void (*DisplayFunction)(struct Node *);
typedef void (*InsertFunction)(struct Node **, struct Node **, float);

int main(int argc, char *argv[])
{
    /* Initialize head and tail pointers of the list */
    struct Node *head = NULL, *tail = NULL;

    /* Assign function pointers for inserting and displaying nodes */
    InsertFunction insert = insertAtEnd;
    DisplayFunction display = displayListReverse;

    /* Loop through command line arguments to read floating numbers */
    for (int i = 2; i < argc; i++)
    {
        /* Convert argument to float and insert into the list */
        float value = atof(argv[i]);
        insert(&head, &tail, value);
    }

    /* Display the list in reverse order */
    display(tail);

    /* Free the allocated memory for the list */
    freeList(head);
    return 0;
}

/* Function to create a new node */
struct Node *createNode(float value)
{
    /* Allocate memory for a new node */
    struct Node *newNode = malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    /* Initialize the node with given value and null pointers */
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

/* Function to insert a node at the end of the list */
void insertAtEnd(struct Node **head, struct Node **tail, float value)
{
    /* Create a new node */
    struct Node *newNode = createNode(value);

    /* Insert the node at the end of the list */
    if (*head == NULL)
    {
        /* If the list is empty, set head and tail to the new node */
        *head = *tail = newNode;
    }
    else
    {
        /* Link the current tail to the new node and update tail */
        (*tail)->next = newNode;
        newNode->prev = *tail;
        *tail = newNode;
    }
}

/* Function to display the list in reverse order */
void displayListReverse(struct Node *tail)
{
    /* Traverse the list from tail to head */
    struct Node *current = tail;
    while (current != NULL)
    {
        /* Print the value of each node */
        printf("%.2f\n", current->value);
        current = current->prev;
    }
}

/* Function to free the list memory */
void freeList(struct Node *head)
{
    /* Traverse the list and free each node */
    struct Node *current = head;
    while (current != NULL)
    {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }
}
