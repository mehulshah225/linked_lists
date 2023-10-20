/* Code to update data of a specific node */
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

// Display function
void displayList(node_t** head){
    node_t* current = *head;

    while(current != NULL){
        printf("%d ->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to find and replace data within a node
void updateNodeDatabyData(node_t** head, int data, int new){
	node_t* current = *head;
	int found = 0;

	if(current == NULL){
		printf("No data in the list to find and replace\n");
		exit(1);
	}

	while(current != NULL){
		if(current->data == data){
			current->data = new;
			found = 1;		//Using flag to be updated and break out of the loop
			break;
		}

		current = current->next;
	}	
	
	// If the flag is never set, the element to be searched does not exist
	if(!found){
		printf("Element not found\n");
		exit(1);
	}
}

int main(void){

	node_t* head = NULL;
	insertNode(&head, 1);
	insertNode(&head, 6);
	insertNode(&head, 7);

	displayList(&head);

	updateNodeDatabyData(&head, 6, 8);
	printf("Updated list: ");
	displayList(&head);

	updateNodeDatabyData(&head, 2, 11);
	displayList(&head);

	return 0;
}


