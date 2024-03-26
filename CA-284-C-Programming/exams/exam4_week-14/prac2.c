#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef int (*CompareFunction)(int, int);

struct Sentence {
    char* content;
    int length;
    struct Sentence* next;
};

void addSentence(struct Sentence** head, const char* content, int length);
struct Sentence* processParagraph(const char* paragraph);
void determineAndPrintResult(struct Sentence* sentenceList, CompareFunction compare);
int compareLongest(int a, int b);
int compareShortest(int a, int b);
CompareFunction getComparisonFunction(const char* selection);
void freeList(struct Sentence* head);
char* my_strdup(const char* s);

int main(int argc, char* argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <paragraph> <shortest|longest>\n", argv[0]);
        return 1;
    }

    char* selection = argv[2];
    CompareFunction compareFunction = getComparisonFunction(selection);
    if (compareFunction == NULL) {
        fprintf(stderr, "Selection must be either 'shortest' or 'longest'.\n");
        return 1;
    }

    struct Sentence* sentenceList = processParagraph(argv[1]);
    determineAndPrintResult(sentenceList, compareFunction);
    freeList(sentenceList);

    return 0;
}

void addSentence(struct Sentence** head, const char* content, int length) {
    struct Sentence* newSentence = (struct Sentence*)malloc(sizeof(struct Sentence));
    newSentence->content = my_strdup(content);
    newSentence->length = length;
    newSentence->next = *head;
    *head = newSentence;
}

struct Sentence* processParagraph(const char* paragraph) {
    struct Sentence* sentenceList = NULL;
    const char* sentenceStart = paragraph;
    int sentenceLength = 0;
    int inSingleQuote = 0;
    int isEndOfSentence = 0;

    for (const char* p = paragraph; *p; p++) {
        if (*p == '\'') {
            inSingleQuote = !inSingleQuote;
        }

        if (isEndOfSentence && !isspace((unsigned char)*p)) {
            addSentence(&sentenceList, sentenceStart, p - sentenceStart - isEndOfSentence);
            isEndOfSentence = 0;
            sentenceStart = p;
        }

        if ((*p == '.' || *p == '?') && !inSingleQuote && !isEndOfSentence) {
            isEndOfSentence = 1;
        }
    }

    if (!isEndOfSentence) {
        addSentence(&sentenceList, sentenceStart, paragraph + strlen(paragraph) - sentenceStart);
    }

    return sentenceList;
}

void determineAndPrintResult(struct Sentence* sentenceList, CompareFunction compare) {
    struct Sentence* resultSentence = sentenceList;
    for (struct Sentence* current = sentenceList; current != NULL; current = current->next) {
        if (compare(current->length, resultSentence->length)) {
            resultSentence = current;
        }
    }

    printf("%d\n", resultSentence->length);
    printf("%s\n", resultSentence->content);
}

int compareLongest(int a, int b) {
    return a > b;
}

int compareShortest(int a, int b) {
    return a < b;
}

CompareFunction getComparisonFunction(const char* selection) {
    if (strcmp(selection, "longest") == 0) {
        return compareLongest;
    } else if (strcmp(selection, "shortest") == 0) {
        return compareShortest;
    }
    return NULL;
}

void freeList(struct Sentence* head) {
    while (head) {
        struct Sentence* temp = head;
        head = head->next;
        free(temp->content);
        free(temp);
    }
}

char* my_strdup(const char* s) {
    size_t len = strlen(s);
    char* new_str = (char*)malloc(len + 1);
    if (new_str) {
        strcpy(new_str, s);
    }
    return new_str;
}
