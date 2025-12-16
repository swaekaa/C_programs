#include<stdio.h>
#include<stdlib.h>

// Definition for doubly circular linked list node
struct node {
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node node;

node* create(node* start) {
    node *nn, *pr = NULL;
    int c = 1;
    
    while (c != 0) {
        nn = (node*)malloc(sizeof(node));  // Allocate memory for new node
        
        printf("Enter data for node %d: \n", c);
        scanf("%d", &nn->data);
        
        nn->next = NULL;
        nn->prev = NULL;

        if (start == NULL) {
            start = nn;  // First node
        } else {
            pr->next = nn;  // Link previous node with new one
            nn->prev = pr;  // Set the prev pointer
        }

        pr = nn;  // Move pr to the newly created node

        printf("Enter 0 to exit or any other number to continue\n");
        scanf("%d", &c);
    }

    // Make the list circular
    if (start != NULL && pr != NULL) {
        pr->next = start;  // Last node's next points to first node
        start->prev = pr;  // First node's prev points to last node
    }

    return start;  // Return the circular linked list
}

void display(node *start) {
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }

    node *temp = start;
    do {
        printf("%d ", temp->data);  // Print the data of the current node
        temp = temp->next;          // Move to the next node
    } while (temp != start);        // Stop when we loop back to the start

    printf("\n");
}

int main() {
    node *start = NULL;  // Initialize the start pointer for the circular list

    // Create a circular doubly linked list and display the nodes
    start = create(start);
    display(start);

    return 0;
}
