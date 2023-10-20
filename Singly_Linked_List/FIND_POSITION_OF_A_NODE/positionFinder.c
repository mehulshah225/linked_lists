/* Code to find the position of the node containing the data */
/* Author: Mehul Shah */

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node_t;

node_t* createNode(int data){
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    if(newNode == NULL){
        printf("Malloc failed");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void insertNode(node_t** head, int data){
    node_t* new = createNode(data);
    if(new == NULL){
        printf("Malloc failed");
        exit(1);
    }

    new->next=*head;
    *head = new;
}

int positionFinder(node_t** head, int data){
    int position = 0;
    node_t* current = *head;

    if(current == NULL){
        printf("Empty list\n");
    }

    if(current->next == NULL){
        printf("element does not exist\n");
    }

    while(current != NULL){
        if(current->data == data){
               return position+1;
        }
        current = current->next;
        position++;
    }
}

void displayList(node_t** head){
    node_t* current = *head;
    while(current != NULL){
        printf("%d ->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main(void){

    node_t* head = NULL;
    insertNode(&head, 2);
    insertNode(&head, 4);
    insertNode(&head, 7);

    displayList(&head);

    printf("Position: %d", positionFinder(&head, 2));
    return 0;
}
