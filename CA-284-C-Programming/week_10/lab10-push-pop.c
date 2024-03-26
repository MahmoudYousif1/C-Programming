/*
Program: lab10-push-pop.c
Author: Mahmoud Yousif
Date: 223/11/2023
*/

/* Important Includes */

#include <stdio.h>
#include <stdlib.h>

/* Define the Node structure for the linked list */
struct Node
{
    int value;         /* Value of the node */
    struct Node *next; /* Pointer to the next node */
};

/* Function prototypes */
struct Node *createNode(int value);
void push(struct Node **head, int value);
void pop(struct Node **head);
void displayList(struct Node *head);
void reverseList(struct Node **head);

int main(int argc, char *argv[])
{
    struct Node *head = NULL; /* Initialize the head of the list */

    int numberOfElements = atoi(argv[1]); /* First argument: number of elements to push initially */

    /* Push initial elements onto the list */
    for (int i = 2; i < 2 + numberOfElements; i++)
    {
        push(&head, atoi(argv[i]));
    }

    /* Pop the last two elements */
    pop(&head);
    pop(&head);

    /* Push the last two command line arguments */
    push(&head, atoi(argv[argc - 2]));
    push(&head, atoi(argv[argc - 1]));

    /* Reverse the list */
    reverseList(&head);

    /* Display the list */
    displayList(head);

    /* Free the list memory */
    while (head != NULL)
    {
        pop(&head);
    }

    return 0;
}

/* Function to create a new node */
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->value = value; /* Set node's value */
    newNode->next = NULL;   /* Next node is initially null */
    return newNode;
}

/* Function to push a value onto the list */
void push(struct Node **head, int value)
{
    struct Node *newNode = createNode(value); /* Create a new node */
    newNode->next = *head;                    /* New node points to the current head */
    *head = newNode;                          /* Update head to the new node */
}

/* Function to pop a value from the list */
void pop(struct Node **head)
{
    if (*head != NULL)
    {
        struct Node *temp = *head; /* Temporarily store the head */
        *head = (*head)->next;     /* Update head to the next node */
        free(temp);                /* Free the old head node */
    }
}

/* Function to reverse the list */
void reverseList(struct Node **head)
{
    struct Node *prev = NULL;
    struct Node *current = *head;
    struct Node *next = NULL;

    while (current != NULL)
    {
        next = current->next; /* Store next */
        current->next = prev; /* Reverse current node's pointer */
        prev = current;       /* Move pointers one position ahead */
        current = next;
    }

    *head = prev;
}

/* Function to display the list */
void displayList(struct Node *head)
{
    struct Node *current = head; /* Start from the head */
    while (current != NULL)
    {
        printf("%d\n", current->value); /* Print the value of the current node */
        current = current->next;        /* Move to the next node */
    }
}
