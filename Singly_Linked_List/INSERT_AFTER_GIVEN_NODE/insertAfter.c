/* Code to add a insert a node after a given node (by position or data) */
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

// Insert By Data: Checks if the input data matches the data value in the list
// If it does, it adds the new node after it, maintaining the list
void insertByData(node_t** head, int data, int value){
        node_t* current = *head;
        node_t* new = createNode(value);

        if(current == NULL){
            printf("List is empty");
        }

        if(current->next == NULL){
            printf("Element not found");
        }

        while(current != NULL){
            if(current->data == data){
                //Make new node point to it's next node in the list (make first)
                new->next = current->next;
                //Break current->next old connection and point it to new node
                current->next = new;
            }
            current=current->next;
        }
}


// Insert node by position, return if the position is too large for the list
void insertByPosition(node_t** head, int position, int value){
    node_t* current = *head;
    node_t* new = createNode(value);

    if(current == NULL)
        printf("List is empty");

    // Check if the node added is at first position
    if(position <= 1){
        new->next = *head;
        *head = new;
    }

    else{
        for(int i = 1; i < position-1; i++){
            //Condition to check of large position input
            if(current->next == NULL){
                    printf("Exceeds NULL\n");
                    exit(1);
            }
            //Increment position till the desired position
            current = current->next;
        }

        //Make first, break old
        new->next = current->next;
        current->next = new;
    }
}

int main(void){

    node_t* head = NULL;
    insertNode(&head, 11);
    insertNode(&head, 2);
    insertNode(&head, 4);
    displayList(&head);

    insertByData(&head, 2, 10);
    displayList(&head);

    insertByPosition(&head, 5, 44);
    displayList(&head);

    insertByPosition(&head, 7, 50);
    displayList(&head);

    return 0;
}
