#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node_t;

// Function creates the node and returns to insertNode
node_t* createList(node_t* head, int data[], int size) {
    for (int i = 0; i < size; i++) {
        node_t* newNode = (node_t*)malloc(sizeof(node_t));
        newNode->data = data[i];
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            node_t* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }
    return head;
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

// Merge while sorting 
node_t* mergeList(node_t* head1, node_t* head2, int size1, int size2){
    node_t* mergedHead = NULL;
    node_t* current = NULL;

    int i = 0;
    int j = 0;

    while (i < size1 && j < size2) {
        if (head1->data <= head2->data) {
            if (mergedHead == NULL) {
                mergedHead = current = head1;
            } else {
                current->next = head1;
                current = current->next;
            }
            head1 = head1->next;
            i++;
        } else {
            if (mergedHead == NULL) {
                mergedHead = current = head2;
            } else {
                current->next = head2;
                current = current->next;
            }
            head2 = head2->next;
            j++;
        }
    }

    while (i < size1) {
        current->next = head1;
        current = current->next;
        head1 = head1->next;
        i++;
    }

    while (j < size2) {
        current->next = head2;
        current = current->next;
        head2 = head2->next;
        j++;
    }

    return mergedHead;
}


int main(void) {
    node_t* head1 = NULL;
    node_t* head2 = NULL;
    node_t* mergedHead = NULL;
    
    int data1[] = {1, 3, 5};
    int size1 = sizeof(data1) / sizeof(data1[0]);
    head1 = createList(head1, data1, size1);
    displayList(head1);
    
    int data2[] = {2, 4, 6};
    int size2 = sizeof(data2) / sizeof(data2[0]);
    head2 = createList(head2, data2, size2);
    displayList(head2);
    
    mergedHead = mergeList(head1, head2, size1, size2);
    displayList(mergedHead);
    
    return 0;
}
