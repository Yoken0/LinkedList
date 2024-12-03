/* Project: Class Assignment 4-16
Name: Kenzo Matsuo
Date: 05/1/2024
File: Q5
Notes: Implemented a function to merge sort a linked list
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
int size = 0;

// Function prototypes
void createNodeList(int n);
void displayList();   
void MergeSort(struct Node** head);
struct Node* SortedMerge(struct Node* L1, struct Node* L2);
void ListSplit(struct Node** front, struct Node** back, struct Node* newStart);



// Main function
int main() {
    // size of the list
    int n;
    printf("\n\nLinked List : MergeSort the LinkedList :\n");
    printf("------------------------------------------------------------------------------\n");
    // Inputting the number of nodes for the linked list
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);
    // creates the node list
    createNodeList(n);
    // Creating the linked list with n nodes	
    // Displaying the data entered in the linked list
    printf("Original linked list: \n");
    displayList();
    // sort the list
    MergeSort(&start);
    // Displaying sorted list
    printf("\nSorted linked list: \n");
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
        printf("Element %d: ", x + 1);
        scanf("%d", &item);
        newnode->item = item;
        newnode->next = NULL;
        size++;
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

// mergeSort
void MergeSort(struct Node** head) {
    // set a ptr that derefences the ptr of the source
    struct Node* defHead = *head;
    // base cases
    if((defHead == NULL) || (defHead->next == NULL)){
        return;
    }

    // set the two halves
    struct Node* half1;
    struct Node* half2;
    
    // call to split the lists 
    ListSplit(&half1, &half2, defHead);
    // then recursevily call first half and second half separetly
    MergeSort(&half1);
    MergeSort(&half2);
    // then reassign the head ptr as the full list complete and sorted
    *head = SortedMerge(half1, half2);

}
// Function to display the linked list
void displayList() {
    // set head as the start node
    struct Node* head = start;
    // while head is not empty
    while(head != NULL){
        //print the item along the node
        printf("%d ", head->item);
        // then skip to the next node
        head = head->next;
    }
}

void ListSplit(struct Node** front, struct Node** back, struct Node* newStart){
    // List1 and List2 variables
    struct Node* List1;
    struct Node* List2;
    
    // created two initial lists, set one to newStart and one to newStart.next

    List1 = newStart;
    List2 = newStart->next;

    // now using size which gives us the amount of nodes in the list
    // we can set one list to be half of the nodes

    while(List2 != NULL){
        List2 = List2->next;
        // we check if the First List has arrived at the last node
        if(List2 != NULL){
            List1 = List1->next;
            List2 = List2->next;
        }
    }
    // set the front ptr to be the newStart
    *front = newStart;
    // back to be the next node in the List1
    *back = List1->next;
    List1->next = NULL;
}

struct Node* SortedMerge(struct Node* L1, struct Node* L2)
{
    struct Node* result = NULL;
 
    // Base cases 
    if (L1 == NULL)
        return (L2);
    else if (L2 == NULL)
        return (L1);
 
    // choose between l1 or l2 then recursively put them together
    if (L1->item <= L2->item) 
    {
        result = L1;
        result->next = SortedMerge(L1->next, L2);
    }
    else
    {
        result = L2;
        result->next = SortedMerge(L1, L2->next);
    }
    // full list
    return (result);
}


