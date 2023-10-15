/* Creation of a new linked list */
/* Author: Mehul Shah */

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

// Function to create a new node with the given data
struct node* createNode(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    //Condition to check whether the created node has failed dynamic memory allocation
    if(newNode == NULL)
        exit(1);
        
    newNode -> data = data;
    newNode -> next = NULL;
    
    return newNode;
}

// Head pointer to traverse the list
struct node* head = NULL;
    
//Function to insert nodes in the list
void insertNode(int data){
    struct node* new = createNode(data);
    // Condition to check if the new node is memory allocated
    if(new == NULL){
        return;
    }
    new -> next = head;
    head = new;
}

// Function to display all the elements in the given list
void displayList(){
    struct node* current = head;
    while(current != NULL){
        printf("%d ->", current -> data);
        current = current->next;
    }
    printf("NULL");
}

// Function to free the heap memory space after creating the list
void deleteList(){
    struct node* current = head;
    while(current != NULL){
        struct node* temp = current;
        current = current -> next;
        free(temp);
    }
}

int main(void){
    
    insertNode(3);  // Insert node 
    insertNode(4);
    
    displayList();
    
    deleteList();
    return 0;
}
