#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Structure definition for ShoppingCartItem */
typedef struct cart {
    char name[21]; // Item name with maximum of 20 characters
    unsigned int amount; // Amount of the item
    float price; // Price per item
    char promotionStatus[8]; // "On Sale" or "No Sale"
} cart;

/* Function prototypes */
int getItemCount(int argc);
void extractItemData(char *argv[], cart items[], int count);
void displayItems(cart items[], int count);

int main(int argc, char *argv[])
{
    int count = getItemCount(argc);
    cart items[count]; // Create an array of ShoppingCartItems

    extractItemData(argv, items, count);
    displayItems(items, count);

    return 0;
}

/* Function to determine the number of items based on argument count */
int getItemCount(int argc)
{
    // Each item has 4 pieces of information
    return (argc - 1) / 4;
}

/* Function to extract item data from argv array */
void extractItemData(char *argv[], cart items[], int count)
{
    int argIndex = 1;
    for (int i = 0; i < count; ++i)
    {
        strncpy(items[i].name, argv[argIndex++], 20);
        items[i].name[20] = '\0'; // Ensure null termination
        items[i].amount = (unsigned int) atoi(argv[argIndex++]);
        items[i].price = (float) atof(argv[argIndex++]);

        // Set promotion status based on the promotion value using an if statement
        int promotion = atoi(argv[argIndex++]);
        if (promotion == 1) {
            strcpy(items[i].promotionStatus, "On Sale");
        } else {
            strcpy(items[i].promotionStatus, "No Sale");
        }
    }
}


/* Function to display items */
void displayItems(cart items[], int count)
{
    for (int i = 0; i < count; ++i)
    {
        printf("%s,%u,%.2f,%s\n",
               items[i].name, 
               items[i].amount, 
               items[i].price, 
               items[i].promotionStatus);
    }
}
