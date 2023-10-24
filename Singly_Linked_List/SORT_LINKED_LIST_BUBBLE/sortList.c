/* C program to sort a given linked list */
/* Author: Meehul Shah */

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}node_t;

// Function creates the node and returns to insertNode
node_t* createNode(int data){
	node_t* newNode = (node_t*) malloc(sizeof(node_t));
	if(newNode == NULL){
		printf("Malloc failed");
		exit(1);
	}

	newNode->data=data;
	newNode;

	return newNode;
}

// Function to insert node to the list
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

//Function to sort list
void sortList(node_t** head){
	node_t* current = *head;
	node_t* temp = NULL;
	int tempVar;

	while(current!=NULL){
		temp = current;
		while(temp->next!=NULL){
			if(temp->data > temp->next->data){
					tempVar = temp->data;
					temp->data = temp->next->data;
					temp->next->data = tempVar;
			}
			temp=temp->next;
		}
		current=current->next;
		
	}
}

int main(void){
	
	node_t* head = NULL;
	insertNode(&head, 3);
	insertNode(&head, 5);
	displayList(&head);

	sortList(&head);
	displayList(&head);
	return 0;
}
