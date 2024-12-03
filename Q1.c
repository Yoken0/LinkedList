/* Project: Class Assignment 4-16
Name: Kenzo Matsuo
Date: 04/19/2024
File: Q1
Notes: implemented a function to add a node to the start of the linked list
*/
#include <stdio.h>
#include <stdlib.h>


//Create a struct node for linked list

struct Node{
    // item
    int item;
    // pointer to the next node
    struct Node *next;
};
// empty list node
struct Node* start = NULL;

// Function prototypes
void createNodeList(int n);
void addToStart(int item);
void displayList();   



// Main function
int main() {
    // size of the list
    int n;
    // Displaying the purpose of the program
    printf("\n\n Linked List : Insert a new node in the start of the list :\n");
    printf("------------------------------------------------------------------------------\n");
    int item;
    // Inputting the number of nodes for the linked list
    printf(" Input the number of nodes : ");
    scanf("%d", &n);
    // creates the node list
    createNodeList(n);
    // Creating the linked list with n nodes
    printf("\nData entered in the list are : \n");		
    // Displaying the data entered in the linked list
    displayList();

    // Reversing the linked list
    
    printf("\nInput data to insert at the beginning of the list :  \n");
    scanf("%d", &item);
    addToStart(item);
    printf("Data after inserted in the list are : \n");
    // Displaying the reversed linked list
    displayList();

    free(start);

    return 0;
}

// Function to create a linked list with n nodes
void createNodeList(int n) {
    // loop that will iterate through the current node and insert it at the end
    // and after inserting at the end it will create a reference point to NULL for the end of the list
     for(int x = 0;x < n;x++){
        struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
        // insert the item connected to the node
        int item;       
        printf("Input data for node %d : ", x + 1);
        scanf("%d", &item);
        newnode->item = item;
        newnode->next = NULL;
        // if is the first node insert in the start
        if(x == 0){
            start = newnode;
        }
        else{
            // if not iterate through the list and insert it at the end
        struct Node* current = start;
        while(current->next != NULL){
            current = current->next;
        }
        // then put the newnode created in the start as next so it points to the node just added
        // new node's next will point to NULL since its the last node
        current->next = newnode; 
    }
     }
}

// Add to start of the list
 void addToStart(int item) {
    struct Node* newStart = (struct Node*) malloc(sizeof(struct Node));
    newStart->item = item;
    newStart->next = start;
    start = newStart;
}
// Function to display the linked list
void displayList() {
    // set head as the start node
    struct Node* head = start;
    // while head is not empty
    
    while(head != NULL){
        //print the item along the node
        printf("data = %d\n", head->item);
        // then skip to the next node
        head = head->next;
    }
}


