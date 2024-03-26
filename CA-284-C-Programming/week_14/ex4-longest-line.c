/* 
Program:
Author: Mahmoud Yousif
Date: 14/12/2023
Description: This program analyzes a paragraph to find and display the shortest or 
longest sentence based on user input.

Approach: Parsing input text into a linked list of sentences, then applies functions to 
identify and print the target sentence as per command line argument 
'shortest' or 'longest', handling memory management.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Type definitions */
typedef struct Sentence Sentence;

/* Structure definitions */
struct Sentence {
    char words[200];
    Sentence *next;
};

/* Function prototypes */
Sentence *get_paragraph(char *argv);
Sentence *new_sentence();
void longest(Sentence *first, char *sentence);
void shortest(Sentence *first, char *sentence);
void check_indicator(char *indicator, Sentence *first, char *sentence);
void indicated_func(void (*pfun)(Sentence *, char *), Sentence *first, char *sentence);
void print_sentence(char *sentence);

/* Main driver function */
int main(int argc, char *argv[]) {
    /* Check for correct number of command-line arguments */
    if (argc != 3) {
        printf("Usage: %s <text> <'shortest' or 'longest'>\n", argv[0]);
        return 1;
    }

    /* Copy the indicator from command line arguments */
    char indicator[strlen(argv[2]) + 1];
    strcpy(indicator, argv[2]);

    /* Allocate memory for sentence */
    char *sentence = (char *)calloc(200, sizeof(char));
    if (!sentence) {
        printf("Error allocating memory!");
        exit(1);
    }

    /* Process the paragraph and get the first sentence of the linked list */
    Sentence *first = get_paragraph(argv[1]);
    check_indicator(indicator, first, sentence);

    /* Free the allocated memory for the linked list */
    Sentence *temp;
    while (first) {
        temp = first;
        first = first->next;
        free(temp);
    }
    free(sentence);

    return 0;
}

/* Function to split paragraph into sentences */
Sentence *get_paragraph(char *argv) {
    Sentence *curr, *first;
    first = new_sentence();
    curr = first;
    int i = 0, j = 0;
    int inSingleQuote = 0; /* Variable to track single quotes */

    while (argv[i]) {
        /* Toggle single quote flag */
        if (argv[i] == '\'') {
            inSingleQuote = !inSingleQuote;
        } else if (!inSingleQuote && (argv[i] == '.' || argv[i] == '?') && 
                   (argv[i+1] == ' ' || argv[i+1] == '\0' || argv[i+1] == '\'')) {
            /* Copy the sentence into the current node */
            strncpy(curr->words, argv + j, i - j + 1);
            curr->words[i - j + 1] = '\0'; // Null terminate the sentence

            /* Create a new node if not end of string */
            if (argv[i+1] != '\0') {
                curr->next = new_sentence();
                curr = curr->next;
            }
            j = i + 2; // Skip the punctuation and the following space
        }
        i++;
    }

    return first;
}

/* Helper function to allocate new node */
Sentence *new_sentence() {
    Sentence *new = (Sentence *)calloc(1, sizeof(Sentence));
    if (!new) {
        printf("Error allocating memory!");
        exit(1);
    }
    return new;
}

/* Function to find the longest sentence */
void longest(Sentence *first, char *sentence) {
    int longest_len = 0;
    Sentence *curr = first;

    while (curr) {
        /* Update the longest sentence found so far */
        if (strlen(curr->words) > longest_len) {
            longest_len = strlen(curr->words);
            strcpy(sentence, curr->words);
        }
        curr = curr->next;
    }

    print_sentence(sentence);
}

/* Function to find the shortest sentence */
void shortest(Sentence *first, char *sentence) {
    int shortest_len = strlen(first->words);
    strcpy(sentence, first->words);

    Sentence *curr = first;

    while (curr) {
        /* Update the shortest sentence found so far */
        if (strlen(curr->words) < shortest_len && strlen(curr->words) > 0) {
            shortest_len = strlen(curr->words);
            strcpy(sentence, curr->words);
        }
        curr = curr->next;
    }

    print_sentence(sentence);
}

/* Function to check the indicator */
void check_indicator(char *indicator, Sentence *first, char *sentence) {
    void (*pf)(Sentence *, char *) = NULL;

    /* Determine the function to call based on the indicator */
    if (strcmp(indicator, "longest") == 0) {
        pf = longest;
    } else if (strcmp(indicator, "shortest") == 0) {
        pf = shortest;
    } else {
        printf("Not valid!\n");
        exit(1);
    }

    /* Call the indicated function */
    indicated_func(pf, first, sentence);
}

/* Function to call the indicated function */
void indicated_func(void (*pfun)(Sentence *, char *), Sentence *first, char *sentence) {
    pfun(first, sentence);
}

/* Function to print the sentence */
void print_sentence(char *sentence) {
    printf("%ld\n%s\n", strlen(sentence), sentence);
}
