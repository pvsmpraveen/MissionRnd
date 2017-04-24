/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes 
will be followed by ones and then twos.


INPUTS:  SLL head pointer

OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2


ERROR CASES:

NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};

void sll_012_sort(struct node *head){

	if (head == NULL)
		return ;
	int one = 0, two = 0, zero = 0;
	node *temp = head;

	while (temp!= NULL){
		if (temp->data == 1) one++;
		if (temp->data == 2) two++;
		if (temp->data == 0) zero++;
		temp = temp->next;
	}
	temp = head;
	while (temp != NULL){
		if (zero){
			temp->data = 0;
			zero--;
		}
		else if (one){
			temp->data = 1;
			one--;
		}
		else if(two) {
			temp->data = 2;
			two--;
		}
		temp = temp->next;
	}
}