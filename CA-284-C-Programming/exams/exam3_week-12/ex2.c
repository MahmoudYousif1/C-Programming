/*
   Author: Mahmoud Yousif
   Date: 30/11/22
   Description: Program manipulates a singly linked list from command 
   line inputs, removing even-valued nodes and displaying the 
   remaining list with a sum.

   Approach:
   1. BldLst: Constructs list from arguments.
   2. NewNd: Creates new nodes.
   3. RmEv: Removes even-valued nodes.
   4. PrtLst: Prints list and sum.
   5. FrLst: Frees memory.
*/


/* Includes */
#include <stdio.h>
#include <stdlib.h>

/* Type definitions */
typedef struct Node Node;

/* Structure definitions */
struct Node {
    int val;
    Node *nxt;
};

/* Function prototypes */
Node *NewNd(int val);
Node *BldLst(int argc, char *argv[]);
void PrtLst(Node *hd);
Node *RmEv(Node *hd);
void FrLst(Node **hd);

/* Main driver function */
int main(int argc, char *argv[]) {
    /* Build list from command line arguments */
    Node *hd = BldLst(argc, argv);
    /* Remove even values from the list */
    hd = RmEv(hd);
    /* Print the list and the sum of its values */
    PrtLst(hd);
    /* Free the list */
    FrLst(&hd);
    return 0;
}

/* Function implementations */

/* Creates a new Node with given value */
Node *NewNd(int val) {
    Node *nd = (Node *)malloc(sizeof(Node));
    nd->val = val;
    nd->nxt = NULL;
    return nd;
}

/* Builds a linked list from command line arguments */
Node *BldLst(int argc, char *argv[]) {
    Node *hd = NULL, *cur = NULL;
    for (int i = 1; i < argc; i++) {
        Node *nd = NewNd(atoi(argv[i]));
        if (!hd) {
            hd = nd;
        } else {
            cur->nxt = nd;
        }
        cur = nd;
    }
    return hd;
}

/* Prints the list and the sum of its values */
void PrtLst(Node *hd) {
    Node *cur = hd;
    int sum = 0;
    while (cur) {
        printf("%d\n", cur->val);
        sum += cur->val;
        cur = cur->nxt;
    }
    printf("%d\n", sum);
}

/* Removes even-valued nodes from the list */
Node *RmEv(Node *hd) {
    Node *cur = hd, *prev = NULL;
    while (cur) {
        if (cur->val % 2 == 0) {
            Node *tmp = cur;
            cur = cur->nxt;

            if (prev) {
                prev->nxt = cur;
            } else {
                hd = cur;
            }

            free(tmp);
        } else {
            prev = cur;
            cur = cur->nxt;
        }
    }
    return hd;
}



/* Frees all nodes in the list */
void FrLst(Node **hd) {
    Node *cur = *hd, *tmp;
    while (cur) {
        tmp = cur->nxt;
        free(cur);
        cur = tmp;
    }
    *hd = NULL;
}
