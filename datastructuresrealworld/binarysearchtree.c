#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char title[50];
    struct Node *left, *right;
} Node;

Node* createNode(char *title) {
    Node *newNode = malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    strcpy(newNode->title, title);
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* addBook(Node *root, char *title) {
    if (!root) return createNode(title);
    if (strcmp(title, root->title) < 0)
        root->left = addBook(root->left, title);
    else if (strcmp(title, root->title) > 0)
        root->right = addBook(root->right, title);
    return root;
}

int searchBook(Node *root, char *title) {
    if (!root) return 0;
    if (strcmp(title, root->title) == 0) return 1;
    if (strcmp(title, root->title) < 0)
        return searchBook(root->left, title);
    return searchBook(root->right, title);
}

void freeTree(Node *root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    Node *root = NULL;
    char input[50];

    printf("Enter book titles (type 'stop' to finish):\n");
    while (1) {
        printf("Add book: ");
        scanf(" %[^\n]s", input);
        if (strcmp(input, "stop") == 0) break;
        root = addBook(root, input);
    }

    printf("\nSearch for a book: ");
    scanf(" %[^\n]s", input);
    if (searchBook(root, input)) {
        printf("Book '%s' found.\n", input);
    } else {
        printf("Book '%s' not found.\n", input);
    }

    freeTree(root);
    return 0;
}


/*
Big O Analysis:
Insertion: 
𝑂(𝑙𝑜𝑔𝑛)(balanced), 
𝑂(𝑛)(unbalanced)

Search: 
𝑂(𝑙𝑜𝑔𝑛)(balanced), 
𝑂(𝑛)(unbalanced)
*/