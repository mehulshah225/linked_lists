/* Count the nodes in the list */
/* Author: Mehul Shah */

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node_t;

// Head pointer to mark the start of the list
node_t *head;

// Function to create the required nodes
node_t* createNode(int data){
    node_t* newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL)
        printf("Malloc failed!");

    newNode->data = data;
    newNode->next = NULL;
}

// Function to insert nodes to the list
void insertNode(int data){
    node_t* new = createNode(data);
    if(new == NULL)
        return;
    new->next = head;
    head = new;
}

// Function to display all the nodes
void displayList(){
    node_t* current = head;
    while(current != NULL){
        printf("%d ->", current -> data);
        current = current -> next;
    }
    printf("NULL\n");
} 

// Function to count the nodes in the list
void countNodes(){
    int count = 0;
    if(head == NULL)
        printf("Linked list is empty");
    while(head != NULL){
        head = head -> next;
        count++;
    }
    printf("No of nodes in the list: %d", count);
}

int main(void){
    insertNode(3);
    insertNode(4);

    displayList();

    countNodes();
    return 0;
}
