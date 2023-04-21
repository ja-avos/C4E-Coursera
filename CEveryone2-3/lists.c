/*
    This program is to demonstrate the use of linked lists
*/
#include <stdio.h>
#include <stdlib.h>

// Define a struct to represent a node in a linked list
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Define a function to print out a linked list
void printList(struct Node *head) {
    struct Node *current = head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Define a function to insert a node at the head of a linked list
struct Node* insertAtHead(struct Node *head, int data) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

// Define a function to insert a node at the tail of a linked list
struct Node* insertAtTail(struct Node *head, int data) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// Define a function to insert a node at a given position in a linked list
struct Node* insertAtPosition(struct Node *head, int data, int position) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;

    if (position == 0) {
        newNode->next = head;
        return newNode;
    }

    struct Node *current = head;
    int i;
    for (i = 0; i < position - 1; i++) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

// Define a function to delete a node at a given position in a linked list
struct Node* deleteAtPosition(struct Node *head, int position) {
    if (position == 0) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node *current = head;
    int i;
    for (i = 0; i < position - 1; i++) {
        current = current->next;
    }
    struct Node *temp = current->next;
    current->next = temp->next;
    free(temp);
    return head;
}

// Define a function to reverse a linked list
struct Node* reverseList(struct Node *head) {
    struct Node *current = head;
    struct Node *prev = NULL;
    struct Node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// Define a function to free a linked list
void freeList(struct Node *head) {
    struct Node *current = head;
    struct Node *next = NULL;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}


