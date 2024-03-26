/* 
Program:
Author: Mahmoud Yousif
Date: 14/12/2023
Description: This program determines if a list of floats provided via command 
line is in descending order, outputs `1` for yes, `0` for no, 
and cleans up memory afterwards.

Approach: Implements a doubly linked list to manage input floats, 
with functions for node creation, appending, order checking, 
and memory freeing.
*/


/* Important Includes */
#include <stdio.h>
#include <stdlib.h>

/* Structure definition for a doubly linked list node */
typedef struct Node {
    float data; /* Value stored in the node */
    struct Node* next; /* Pointer to the next node */
    struct Node* prev; /* Pointer to the previous node */
} Node;

/* Function prototypes */
Node* makeNode(float data);
void appendNode(Node** head, float data);
int checkOrder(Node* head);
void free1(Node* head);

/* Main function */
int main(int argc, char* argv[]) {
    Node* head = NULL;
    /* Iterate over command line arguments to build the list */
    for (int i = 1; i < argc; i++) {
        appendNode(&head, atof(argv[i]));
    }
    /* Check if the list is in descending order and print result */
    printf("%d\n", checkOrder(head));
    /* Free the allocated memory for the list */
    free1(head);
    return 0;
}

/* Function to create a new list node */
Node* makeNode(float data) {
    Node* newNode = (Node*)malloc(sizeof(Node)); /* Allocate memory for new node */
    newNode->data = data; /* Set node's data */
    newNode->next = NULL; /* Initialize next to NULL */
    newNode->prev = NULL; /* Initialize prev to NULL */
    return newNode;
}

/* Function to append a node at the end of the list */
void appendNode(Node** head, float data) {
    Node* newNode = makeNode(data); /* Create a new node with the given data */
    Node* last = *head;

    /* If the list is empty, then make the new node as the head */
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    /* Traverse till the last node */
    while (last->next != NULL) {
        last = last->next;
    }

    /* Change the next of last node */
    last->next = newNode;
    newNode->prev = last;
}

/* Function to check if the list is in descending order */
int checkOrder(Node* head) {
    /* Traverse the list and verify order */
    while (head && head->next) {
        if (head->data < head->next->data) {
            return 0;
        }
        head = head->next; /* Move to the next node */
    }
    return 1;
}

/* Function to free the memory allocated for the list */
void free1(Node* head) {
    Node* tmp;
    while (head) {
        tmp = head; /* Store the current node */
        head = head->next; /* Move to the next node */
        free(tmp); /* Free the current node */
    }
}
