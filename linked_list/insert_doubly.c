#include <stdio.h>
#include <stdlib.h>

// Node structure for the doubly linked list
typedef struct Node {
    int value;
    struct Node* next;
    struct Node* prev;
} Node;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);  // Exit if memory allocation fails
    }
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// LinkedList structure
typedef struct LinkedList {
    Node* head;
    Node* tail;
} LinkedList;

// Function to insert a node at a specific index
void insertAtIndex(LinkedList * list, int index, int value) {
    Node* newNode = createNode(value);

    if (list->head == NULL) {  // List is empty
        if (index != 0) {
            printf("Invalid index. List is empty.\n");
            free(newNode);
            return;
        }
        list->head = newNode;
        list->tail = newNode;
        return;
    }

    if (index == 0) {  // Insert at the head
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
        return;
    }

    Node* iter = list->head;
    for (int i = 0; i < index - 1; i++) {
        if (iter->next == NULL) {  // Reached the end before the desired index
            printf("Index out of bounds.\n");
            free(newNode);
            return;
        }
        iter = iter->next;
    }

    Node* A = iter;
    Node* B = iter->next;

    A->next = newNode;
    newNode->prev = A;

    if (B != NULL) {  // Middle insertion
        B->prev = newNode;
        newNode->next = B;
    } else {  // Insertion at the tail
        list->tail = newNode;
    }
}

// Function to print the list
void printList(LinkedList* list) {
    Node* temp = list->head;
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    LinkedList list = {NULL, NULL};

    insertAtIndex(&list, 0, 10);  // Insert at head
    insertAtIndex(&list, 1, 20);  // Insert at tail
    insertAtIndex(&list, 1, 15);  // Insert in the middle

    printList(&list);  // Expected output: 10 15 20

    return 0;
}
