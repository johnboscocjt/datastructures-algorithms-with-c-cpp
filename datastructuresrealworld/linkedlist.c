#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char title[50];
    struct Node *next;
} Node;

void addBook(Node **head, char *title) {
    Node *newNode = malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    strcpy(newNode->title, title);
    newNode->next = *head;
    *head = newNode;
}

int searchBook(Node *head, char *title) {
    int index = 0;
    while (head != NULL) {
        if (strcmp(head->title, title) == 0) {
            return index;
        }
        head = head->next;
        index++;
    }
    return -1;
}

void freeList(Node *head) {
    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node *head = NULL;
    char input[50];

    printf("Enter book titles (type 'stop' to finish):\n");
    while (1) {
        printf("Add book: ");
        scanf(" %[^\n]s", input);
        if (strcmp(input, "stop") == 0) break;
        addBook(&head, input);
    }

    printf("\nSearch for a book: ");
    scanf(" %[^\n]s", input);
    int result = searchBook(head, input);
    if (result != -1) {
        printf("Book '%s' found at index %d.\n", input, result);
    } else {
        printf("Book '%s' not found.\n", input);
    }

    freeList(head);
    return 0;
}


/*
Big O Analysis:
Insertion: 
𝑂(1)(at the head)

Search: 
𝑂(𝑛)

*/