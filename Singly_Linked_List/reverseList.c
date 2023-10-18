/* Code to reverse the linked list */
/* Author: Mehul Shah */

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node_t;

// Function to create node for the list
node_t* createNode(int data){
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    if(newNode == NULL){
        printf("Malloc failed");
        exit(1);
    }

    newNode->data=data;
    newNode->next=NULL;

    return newNode;
}

// Function to insert node in the list
void insertNode(node_t** head, int data){
    node_t* new = createNode(data);
    if(new == NULL){
        printf("Malloc failed");
    }

    new->next = *head;
    *head = new;
}

// Fucntion to reverse the list
void reverseList(node_t** head){
	node_t* current = *head;
	node_t* prev = NULL;
	node_t* temp;
	
	while(current != NULL){
		temp = current->next;
		current->next = prev;
		prev = current;
		current = temp;
	}
	*head = prev;
}

// Display function
void displayList(node_t* head){
    node_t* current = head;

    while(current != NULL){
        printf("%d ->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main(void){
	
	node_t* head = NULL;
	
	insertNode(&head, 3);
	insertNode(&head, 5);
	insertNode(&head, 7);
	insertNode(&head, 9);
	printf("Before reverse:");
	displayList(head);


	reverseList(&head);
	printf("\nAfter reverse:");
	displayList(head);
	return 0;
}
