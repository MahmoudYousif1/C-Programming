/*
Program:
Author: Mahmoud Yousif
Date: 14/12/2023
Description: 

Approach:
*/

#include <stdio.h>
#include <stdlib.h>

/* Definition of the Node structure for a linked list */
typedef struct Node {
    int data;         /* The data stored in the node */
    struct Node* next; /* Pointer to the next node in the list */
    int duplicate;    /* Flag to mark duplicates, used for duplicate removal */
} Node;

/* Function prototypes */
void appendNode(Node** head, int data);
void tagDupes(Node* head);
void removeDupes(Node** head);
void print1(Node* head);

/* Main function */
int main(int argc, char* argv[]) {
    Node* head = NULL; /* Initialize head pointer of the list */

    /* Append nodes to the linked list based on command line arguments */
    for (int i = 1; i < argc; i++) {
        appendNode(&head, atoi(argv[i]));
    }

    /* Tag duplicates in the list */
    tagDupes(head);
    /* Remove tagged duplicates */
    removeDupes(&head);
    /* Print the list and free the nodes */
    print1(head);

    return 0;
}

/* Function to append a node at the end of the linked list */
void appendNode(Node** head, int data) {
    /* Allocate memory for the new node */
    Node* newNode = malloc(sizeof(Node));

    /* Initialize the new node's data */
    newNode->data = data;
    newNode->next = NULL;
    newNode->duplicate = 0; /* Initially marked as not a duplicate */

    /* Insert the new node at the end of the list */
    if (!*head) {
        *head = newNode;
    } else {
        Node* tail = *head;
        while (tail->next) {
            tail = tail->next;
        }
        tail->next = newNode;
    }
}

/* Function to tag duplicates in the linked list */
void tagDupes(Node* head) {
    Node *current = head, *c2;

    /* Iterate through each node */
    while (current) {
        c2 = current->next;
        /* Compare current node with rest of the list */
        while (c2) {
            if (current->data == c2->data) {
                current->duplicate = 1;
                c2->duplicate = 1;
            }
            c2 = c2->next;
        }
        current = current->next;
    }
}

/* Function to remove nodes marked as duplicates */
void removeDupes(Node** head) {
    Node *current = *head, *prev = NULL, *temp;

    /* Iterate through the list */
    while (current) {
        if (current->duplicate) {
            /* Remove the duplicate node */
            temp = current;
            if (prev) {
                prev->next = current->next;
            } else {
                *head = current->next;
            }
            current = current->next;
            free(temp); /* Free the memory of the duplicate node */
        } else {
            prev = current;
            current = current->next;
        }
    }
}

/* Function to print the linked list and free the nodes */
void print1(Node* head) {
    while (head) {
        printf("%d\n", head->data); /* Print the node's data */
        Node* temp = head;
        head = head->next;
        free(temp); /* Free the node after printing */
    }
}
