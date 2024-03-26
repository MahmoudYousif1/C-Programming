/*
Program: ex3-array-degree.c
Author: Mahmoud Yousif
Date: 30/11/22
Description:
    This program processes a list of products with their country of origin and price. 
    It specifically targets products from Ireland and increases their prices by 20%. 
    The program reads product information from the command line arguments and displays the updated list.

Approach:
    1. Define a Node structure for storing product details.
    2. Create a linked list from command line arguments.
    3. Update the price of Irish products by 20%.
    4. Print the updated list of products.
*/


/* Includes */
#include <stdio.h>
#include <stdlib.h>

/* Type definitions */
typedef struct Node Node;

/* Structure definitions */
struct Node {
    int value;
    Node *next;
};

/* Function prototypes */
Node *add_node(Node *head, int value);
Node *get_nodes(int argc, char *argv[]);
int sum_nodes(Node *head);
void free_list(Node *head);

/* Main driver function */
int main(int argc, char *argv[]) {
    Node *head = get_nodes(argc, argv);
    int sum = sum_nodes(head);
    printf("Sum of node values: %d\n", sum);
    free_list(head);
    return 0;
}

/* Function to create a new linked list from command line arguments */
Node *get_nodes(int argc, char *argv[]) {
    Node *head = NULL;
    for (int i = 1; i < argc; ++i) {
        head = add_node(head, atoi(argv[i]));
    }
    return head;
}

/* Function to add a new node with a given value */
Node *add_node(Node *head, int value) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (!new_node) {
        printf("Error allocating memory!\n");
        exit(1);
    }
    new_node->value = value;
    new_node->next = head;
    return new_node;
}

/* Function to calculate the sum of all node values */
int sum_nodes(Node *head) {
    int sum = 0;
    Node *current = head;
    while (current != NULL) {
        sum += current->value;
        current = current->next;
    }
    return sum;
}

/* Function to free the linked list */
void free_list(Node *head) {
    Node *current = head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
}
