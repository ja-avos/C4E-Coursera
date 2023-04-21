/*  
    Assignment for week 3. C for Everyone: Structured Programming. Option 1.
    Juan Avelino
    2023/04/20
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
    Definition of list ADT and functions
*/

// List struct
typedef struct list {
    int value;
    struct list* next;
} list;

// Create list
list* create_list(int value) {
    list* head = malloc(sizeof(list));

    head->value = value;
    head->next = NULL;

    return head;
}

// Insert to tail iteratively
void insert_to_tail(list* head, int value) {
    list* current = head;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = create_list(value);
}

// Swap only the values of the two list nodes
void swap(list* node1, list* node2) {
    int tmp = node1->value;
    node1->value = node2->value;
    node2->value = tmp;
}

// Orders the list with bubble sort?
void order_list(list* head) {
    list* current = head;

    while (current->next != NULL) {
        list* tmp = current->next;

        while (tmp->next != NULL) {
            
            if (current->value >= tmp->value) {
                swap(current, tmp);
            }

            tmp = tmp->next;
        }

        current = current->next;
    }

}

// Prints the list with 5 elements in each row
void print_list(list* head) {
    int count = 0;
    while(head != NULL) {
        printf("%d\t", head->value);
        if (++count == 5) {
            printf("\n");
            count = 0;
        }
        head = head->next;
    }
}

/*
    1. Generates a list with 100 random numbers.
    2. Prints the list.
    3. Orders the list.
    4. Prints the ordered list.
*/

int main(void) {
    srand(time(NULL));

    list* head = create_list(rand());

    for(int i = 0; i < 99; i++) {
        insert_to_tail(head, rand());
    }

    printf("Original list:\n");
    print_list(head);
    printf("\n");

    order_list(head);

    printf("Ordered list:\n");
    print_list(head);
    printf("\n");

    return 0;
}