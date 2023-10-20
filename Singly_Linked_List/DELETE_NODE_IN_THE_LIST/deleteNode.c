/* Program to delete a node in linked list */
/*Author: Mehul Shah*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node_t;

node_t* createNode(int data){
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    if(newNode == NULL)
        printf("Malloc failed");

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void insertNode(node_t**head, int data){
    node_t* new = createNode(data);
    if(new == NULL)
        printf("Malloc failed");

    new->next = *head;
    *head = new;
}

void deleteNode(node_t**head, int data) {
    node_t* current = *head;
    node_t* previous = NULL;

    if (current == NULL) {
        return; // List is empty, nothing to delete.
    }

    if (current->data == data) {
        // If the node to delete is the head, update the head.
        *head = current->next;
        free(current);
        return;
    }
    
    // Checks if data to be deleted is found
    while (current != NULL) {
        if (current->data == data) {
            previous->next = current->next;
            free(current);
            return;
        }

        previous = current;
        current = current->next;
    }
}

void displayList(node_t* head){
    node_t* current = head;

    while(current != NULL){
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main(void){
    node_t* head = NULL;
    
    insertNode(&head,4);
    insertNode(&head,6);

    displayList(head);

    deleteNode(&head,4);
    displayList(head);
    return 0;
}
