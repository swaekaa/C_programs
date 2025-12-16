#include<stdio.h>
#include<stdlib.h>

// Correct the typo in the structure definition
struct node {
    int data;
    struct node *next;
    struct node *prev;
};

// Use typedef for easier reference to 'struct node'
typedef struct node node;

node* create(node* start) {
    node *nn, *pr = NULL;  // Corrected initialization of pr pointer
    int c = 1;
    
    while(c != 0) {
        // Allocate memory for the new node
        nn = (node*)malloc(sizeof(node));
        
        printf("Enter data for node %d: \n", c);
        scanf("%d", &nn->data);
        
        nn->next = NULL;
        nn->prev = NULL;

        if(start == NULL) {
            start = nn;  // Assign the first node to 'start'
        } else {
            pr->next = nn;  // Link the previous node with the new one
            nn->prev = pr;  // Set the previous pointer of the new node
        }

        pr = nn;  // Move 'pr' to the newly created node

        printf("Enter 0 to exit or any other number to continue\n");
        scanf("%d", &c);
    }

    return start;  // Return the start of the linked list
}

void display(node *start) {
    while (start != NULL) {
        printf("%d ", start->data);  // Print the data of the current node
        start = start->next;         // Move to the next node
    }
    printf("\n");  // Move to a new line after displaying all nodes
}

int main() {
    node *start = NULL;  // Initialize the start pointer for the linked list

    // Create a linked list and display the nodes
    start = create(start);
    display(start);

    return 0;
}
