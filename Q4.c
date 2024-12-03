/* Project: Class Assignment 4-16
Name: Kenzo Matsuo
Date: 05/1/2024
File: Q4
Notes: implemented a function that removes the first node
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
void deleteFirst();
void displayList();   



// Main function
int main() {
    // size of the list
    int n;
    // Displaying the purpose of the program
    printf("\n\n Linked List : Deletes the first Node of the Linked List :\n");
    printf("------------------------------------------------------------------------------\n");
    // Inputting the number of nodes for the linked list
    printf(" Input the number of nodes (3 or more) : ");
    scanf("%d", &n);
    // creates the node list
    createNodeList(n);
    // Creating the linked list with n nodes
    printf("\nData entered in the list are : \n");		
    // Displaying the data entered in the linked list
    displayList();

    printf("\nData of node 1 which is being deleted is : %d", start->item);
    // call the function to delete the first node
    deleteFirst();
    printf("\nData, after deletion of first node : \n");
    
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

// delete first node
 void deleteFirst() {
    struct Node* temp = start;
    start = start->next;
    free(temp);
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


