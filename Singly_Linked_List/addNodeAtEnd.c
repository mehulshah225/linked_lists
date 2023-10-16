#include <stdio.h>
#include <stdlib.h>

typedef struct node{    
        int data;
        struct node* next;
}node_t;

node_t* head = NULL;

// Function to create new node
node_t* createNode(int data){
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    if(newNode == NULL)
            printf("Malloc failed");

    newNode->data = data;
    newNode->next = NULL;
    
    return newNode;
}

//Function to insert nodes in the list
void insertNode(int data){
    node_t* new = createNode(data);
    node_t* current = head;
    if(new == NULL)
            printf("Malloc failed");

    new->next = current;
    head = new;
}

// Fnction to insert nodes at the end of the list
void insertAtEnd(int data){
    node_t* current = head;
    node_t* insertNode = createNode(data);

    insertNode->data = data;
    insertNode->next = NULL;
    
    if(head == NULL)
        head = insertNode;
        
    //Loop until you reach the last element
    while(current->next != NULL){
        current = current->next;
    }
    
    //Assign new node at the end
    current->next=insertNode;
}

// Function to display the list
void displayList(){
    node_t* current = head;
    while(current != NULL){
            printf("%d ->", current->data);
            current = current->next;
    }
    printf("NULL\n");
}

int main(void){

    insertNode(4);
    insertNode(6);
    insertNode(7);
    insertNode(11);
    displayList();

    insertAtEnd(10);
    displayList();

    return 0;
}
