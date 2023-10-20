# This is a code to insertAfter.c

Code to insert a node after a given node(by data or position)

Logic explained(for data):

-   iterate in the while loop till you reach the node which has data to be matched
-   if data matches, 
		//Make new node point to it's next node in the list (make first)
                new->next = current->next;
                //Break current->next old connection and point it to new node
                current->next = new;

Logi explained(for position):

-   iterate through while to certain location, store the location in a pointer
-   Make connection of new to point to it's next node
-   unlink the old nodes connection
