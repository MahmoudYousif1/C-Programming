#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Structure definition for ShoppingCartItem */
typedef struct cart {
    char name[21]; // Item name with maximum of 20 characters
    unsigned int amount; // Amount of the item
    float price; // Price per item
    int promotion; // Promotion status (1 for on sale, 0 for no sale)
} ShoppingCartItem;

/* Function prototypes */
int getItemCount(int argc);
void extractItemData(char *argv[], ShoppingCartItem items[], int count);
int calculateTotal(ShoppingCartItem items[], int count); // Return type changed to int

int main(int argc, char *argv[])
{
    int count = getItemCount(argc);
    ShoppingCartItem items[count]; // Create an array of ShoppingCartItems

    extractItemData(argv, items, count);
    int total = calculateTotal(items, count); // Changed type to int

    printf("%d\n", total); // Changed format specifier to %d for integers

    return 0;
}

/* Function to determine the number of items based on argument count */
int getItemCount(int argc)
{
    // Each item has 4 pieces of information
    return (argc - 1) / 4;
}

/* Function to extract item data from argv array */
void extractItemData(char *argv[], ShoppingCartItem items[], int count)
{
    int argIndex = 1;
    for (int i = 0; i < count; ++i)
    {
        strncpy(items[i].name, argv[argIndex++], 20);
        items[i].name[20] = '\0'; // Ensure null termination
        items[i].amount = (unsigned int)atoi(argv[argIndex++]);
        items[i].price = atof(argv[argIndex++]);
        items[i].promotion = atoi(argv[argIndex++]);
    }
}

/* Function to calculate total cost */
int calculateTotal(ShoppingCartItem items[], int count)
{
    float total = 0;
    for (int i = 0; i < count; ++i)
    {
        // Calculate total for non-promotional items directly
        if (items[i].promotion == 0) {
            total += items[i].price * items[i].amount;
        } else {
            // Apply promotion: for every three items, one is free
            unsigned int nonPromotionalItems = items[i].amount / 3;
            unsigned int promotionalItems = items[i].amount - nonPromotionalItems;
            total += items[i].price * promotionalItems;
        }
    }
    return (int)(total + 0.5); // Round to the nearest integer before returning
}
