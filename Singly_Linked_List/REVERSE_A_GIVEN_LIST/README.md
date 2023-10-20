# This is a code to reverseList.c

Program to reverse the list and print it

Logic explained:

-    We need 4 pointers namely, 
     	current = head
	temp (uninitialized);
	prev = NULL;
-    in the while loop, iterate till current != NULL
	store current->next in temp
	store prev in current->next
	store prev = current
	store current = temp;
-    make head equal to prev
