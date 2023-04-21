/*  
    Assignment for week 3 - honors. C for Everyone: Structured Programming.
    Juan Avelino
    2023/04/20
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
    Definition of list ADT and functions
*/

// List struct (double linked list)
typedef struct list {
    int value;
    struct list* next;
    struct list* prev;

} list;

// Create list
list* create_list(int value) {
    list* head = malloc(sizeof(list));

    head->value = value;
    head->prev = NULL;
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
    current->next->prev = current;
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

    while (current != NULL) {
        list* tmp = current->next;

        while (tmp != NULL) {
            
            if (current->value >= tmp->value) {
                swap(current, tmp);
            }

            tmp = tmp->next;
        }

        current = current->next;
    }

}

// Remove repeated elements
void remove_repeated(list* head) {

    while (head != NULL) {
        list* tmp = head->next;

        while (tmp != NULL && head->value == tmp->value) {
            list* to_delete = tmp;
            tmp = tmp->next;

            if (tmp != NULL) {
                tmp->prev = head;
            }
            head->next = tmp;

            free(to_delete);
        }

        head = head->next;
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
    5. Removes the repeated numbers.
    6. Prints the processed list.
*/

int main(void) {
    srand(time(NULL));

    list* head = create_list(rand() % 50);

    for(int i = 0; i < 199; i++) {
        insert_to_tail(head, rand() % 50);
    }

    printf("Original list:\n");
    print_list(head);
    printf("\n");

    order_list(head);

    printf("Ordered list:\n");
    print_list(head);
    printf("\n");

    remove_repeated(head);

    printf("Processed list:\n");
    print_list(head);
    printf("\n");

    return 0;
}