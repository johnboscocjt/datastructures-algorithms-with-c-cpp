#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE 50

void addBook(char books[MAX_BOOKS][MAX_TITLE], int *count, char *title) {
    if (*count < MAX_BOOKS) {
        strcpy(books[*count], title);
        (*count)++;
    } else {
        printf("Library is full!\n");
    }
}

int searchBook(char books[MAX_BOOKS][MAX_TITLE], int count, char *title) {
    for (int i = 0; i < count; i++) {
        if (strcmp(books[i], title) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    char books[MAX_BOOKS][MAX_TITLE];
    int count = 0;
    char input[MAX_TITLE];

    printf("Enter book titles (type 'stop' to finish):\n");
    while (1) {
        printf("Add book: ");
        scanf(" %[^\n]s", input);
        if (strcmp(input, "stop") == 0) break;
        addBook(books, &count, input);
    }

    printf("\nSearch for a book: ");
    scanf(" %[^\n]s", input);
    int result = searchBook(books, count, input);
    if (result != -1) {
        printf("Book '%s' found at index %d.\n", input, result);
    } else {
        printf("Book '%s' not found.\n", input);
    }

    return 0;
}

/*
Big O Analysis:
Insertion: 
𝑂(1)(at the end)

Search: 
𝑂(𝑛)(linear search)

*/
