#include <stdio.h>
#include <stdlib.h>

// Structure definition for a node in the linked list
struct node 
{
    int data;            // Data to be stored in the node
    struct node *next;   // Pointer to the next node in the linked list
};

// Typedef to simplify the usage of 'struct node'
typedef struct node NODE;

NODE *create(NODE *start);  
void display(NODE *start);  
NODE *addnode(NODE *start);
void addlast(NODE *start);
int count(NODE *start);
void addpos(NODE *start, int c);
NODE *deletefirst(NODE *start);
NODE *deletenodelast(NODE *start);

int main() 
{
    NODE *start = NULL;  // Initialize the start pointer for the linked list

    // Create a linked list and display the nodes
    start = create(start);
    display(start);

    // Add a new node at the beginning of the list and display it
    start = addnode(start);
    display(start);

    // Add a new node at the end of the list and display it
    addlast(start);
    display(start);

    // Count the total number of nodes in the linked list
    int c = count(start);
    printf("Total nodes: %d\n", c);

    // Add a new node at a specific position and display the updated list
    addpos(start, c);
    display(start);

    // Delete the first node in the list and display the remaining nodes
    start = deletefirst(start);
    printf("after deleting first element\n");
    display(start);

    start=deletenodelast(start);
    printf("after deleting last element\n");
    display(start);

    return 0; // Program ends
}

// Function to create a linked list by adding nodes
NODE *create(NODE *start) 
{
    NODE *newnode, *pr;
    int c = 1;  // Control variable for loop

    while (c != 0) 
    {
        // Allocate memory for a new node
        newnode = (NODE *)malloc(sizeof(NODE));
        if (newnode == NULL) 
        {
            printf("Memory allocation failed\n");
            exit(1); // Exit if memory allocation fails
        }

        // Take user input for the node data
        printf("Enter the value to be in the node: ");
        scanf("%d", &newnode->data);

        newnode->next = NULL;  // Initialize next pointer to NULL for the new node

        // If the list is empty, set the new node as the first node
        if (start == NULL) 
        {
            start = newnode;
        }
        else 
        {
            pr->next = newnode;  // Link the previous node to the new node
        }

        pr = newnode;  // Move to the current node for further linking

        // Ask the user if they want to continue adding nodes
        printf("If you want to exit, press 0. Else, press any other number: ");
        scanf("%d", &c);
    }

    newnode->next=NULL; // the last node of the linked list points to null

    return start;  // Return the head of the linked list
}

// Function to display the data in each node of the linked list
void display(NODE *start) 
{
    while (start != NULL) 
    {
        printf("%d ", start->data);  // Print the data of the current node
        start = start->next;         // Move to the next node
    }
    printf("\n");  // Move to a new line after displaying all nodes
}

// Function to add a new node at the beginning of the list
NODE *addnode(NODE *start) 
{
    NODE *nn = (NODE *)malloc(sizeof(NODE));  // Allocate memory for the new node

    // Get user input for the new node data
    printf("Enter a value to add at the start: ");
    scanf("%d", &nn->data);

    nn->next = start;  // Link the new node to the current start of the list

    return nn;  // Return the new start of the list (newly added node)
}

// Function to add a new node at the end of the linked list
void addlast(NODE *start) 
{
    NODE *ln = (NODE *)malloc(sizeof(NODE));  // Allocate memory for the new node

    if (ln == NULL) 
    {
        printf("Memory allocation failed\n");
        return;  // Exit function if memory allocation fails
    }

    // Get user input for the new node data
    printf("Enter a value to add at the end: ");
    scanf("%d", &ln->data);

    ln->next = NULL;  // New node's next pointer should be NULL


    // Traverse to the last node in the linked list
    while (start->next != NULL) 
    {
        start = start->next;
    }

    start->next = ln;  // Link the last node to the new node
}

// Function to count the total number of nodes in the linked list
int count(NODE *start) 
{
    int count = 0;  // Initialize the count variable

    // Traverse through the list and count each node
    while (start != NULL) 
    {
        count++;
        start = start->next;
    }

    return count;  // Return the total number of nodes
}

// Function to add a new node at a specific position in the list
void addpos(NODE *start, int count) 
{
    printf("Enter the position after which you want to add a node: ");
    int n;
    scanf("%d", &n);

    // Check if the position is valid
    if (n > count || n < 1) 
    {
        printf("ERROR: Invalid position\n");
        return;
    }

    NODE *pn = (NODE *)malloc(sizeof(NODE));  // Allocate memory for the new node
    if (pn == NULL) 
    {
        printf("Memory allocation failed\n");
        return;  // Exit function if memory allocation fails
    }

    // Get user input for the new node data
    printf("Enter a value: ");
    scanf("%d", &pn->data);

    // Traverse to the desired position
    for (int i = 1; i < n; i++) 
    {
        start = start->next;
    }

    // Insert the new node at the specified position
    pn->next = start->next;
    start->next = pn;
}

// Function to delete the first node in the linked list
NODE *deletefirst(NODE *start) 
{
    if (start == NULL) 
    {
        printf("List is empty, no node to delete\n");
        return NULL;
    }

    NODE *temp = start;  // Temporary pointer to hold the first node
    start = start->next; // Move the start pointer to the next node
    free(temp);          // Free the memory allocated for the first node

    return start;  // Return the new start of the list
}

// to delete last nod eof the linked list 
NODE *deletenodelast(NODE *start) 
{
    if (start == NULL) 
    {
        printf("List is empty, no node to delete\n");
        return NULL;
    }

    if (start->next == NULL) 
    {
        // If there's only one node, free it and return NULL
        free(start);
        return NULL;
    }

    // Traverse to the second-to-last node
    NODE *current = start;
    while (current->next->next != NULL) 
    {
        current = current->next;
    }

    // Free the last node and set the second-to-last node's next to NULL
    free(current->next);
    current->next = NULL;

    return start;
}

// as per sirs logic (IN THE BOOK) ---> MUCH EASIER
