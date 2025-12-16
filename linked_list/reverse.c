#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

typedef struct node node;

node* create(node* start) {
    node* nn;
    node* pr;
    int c = 1;
    while(c != 0) {
        nn = (node*)malloc(sizeof(node));
        printf("Enter data for node: \n");
        scanf("%d", &nn->data);

        nn->next = NULL;

        if(start == NULL) {
            start = nn; // Initialize start if the list is empty
        } else {
            pr->next = nn; // Link previous node to current node
        }
        pr = nn; // Move the previous pointer to the current node

        printf("Enter 0 to exit else print any number: ");
        scanf("%d", &c);
    }
    return start;
}

void display(node* start) {
    while(start != NULL) {
        printf("%d ", start->data);
        start = start->next;
    }
    printf("\n");
}

// Function to reverse the linked list
node* reverse(node* start) {
    node* prev = NULL;
    node* current = start;
    node* next = NULL;

    while(current != NULL) {
        next = current->next; // Store the next node
        current->next = prev; // Reverse the current node's pointer
        prev = current;       // Move prev and current one step forward
        current = next;
    }
    start = prev; // Update start to the new head (prev points to the new head)
    return start;
}

int main(void) {
    node* start = NULL;
    start = create(start);

    printf("Original Linked List:\n");
    display(start);

    start = reverse(start);

    printf("Reversed Linked List:\n");
    display(start);

    return 0;
}
