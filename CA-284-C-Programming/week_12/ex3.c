/*
Program: ex3-product.c
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
#include <string.h>
#include <stdlib.h>

/* Type definitions */
typedef struct Node Node;

/* Structure definitions */
struct Node {
    char code[50];
    char country[50];
    int price;
    Node *next;
};

/* Function prototypes */
Node *new_node(void);
Node *get_nodes(int *length, char *argv[]);
Node *update_price(Node *head);
void print_nodes(Node *head);

/* Main driver function */
int main(int argc, char *argv[]) {
    /* Calculate the length of the product list */
    int length = (argc - 1) / 3;
    /* Build the linked list from command line arguments */
    Node *head = get_nodes(&length, argv);
    /* Update the price of Irish products */
    head = update_price(head);
    /* Print the updated product list */
    print_nodes(head);
    return 0;
}

/* Function to create a linked list from command line arguments */
Node *get_nodes(int *length, char *argv[]) {
    Node *head, *current;
    head = new_node();
    current = head;
    int count = 0;
    /* Loop through the arguments to create nodes */
    for (int i = 0; i < *length; ++i) {
        current->next = new_node();

        /* Copy product details to the node */
        strcpy(current->code, argv[++count]);
        strcpy(current->country, argv[++count]);
        current->price = atoi(argv[++count]);

        current = current->next;
    }
    current->next = NULL;
    return head;
}

/* Function to create and initialize a new node */
Node *new_node() {
    Node *new = (Node *)calloc(1, sizeof(Node));
    /* Handle memory allocation failure */
    if (!new) {
        printf("Error allocating memory!\n");
        exit(0);
    }
    return new;
}

/* Function to update the price of Irish products by 20% */
Node *update_price(Node *head) {
    Node *current = head;
    while (current->next) {
        /* Check if the product is from Ireland */
        if (strcmp(current->country, "Ireland") == 0) {
            current->price = current->price * 1.2;
        }
        current = current->next;
    }
    return head;
}

/* Function to print all nodes in the linked list */
void print_nodes(Node *head) {
    Node *current = head;
    while (current->next) {
        /* Print product details */
        printf("%s\n", current->code);
        printf("%s\n", current->country);
        printf("%d\n", current->price);
        current = current->next;
    }
}
