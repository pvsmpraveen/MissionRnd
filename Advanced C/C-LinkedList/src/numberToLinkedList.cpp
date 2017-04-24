/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES: 

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * numberToLinkedList(int N) {
	N = (N<0 ? -N : N);
	if (N == 0){
		node *head = (node *)calloc(1, sizeof(node));
		head->num = 0;
		head->next = 0;
		return head;
	}

	node *head, *temp;
	head = NULL;
	while (N){
		temp = (node *)calloc(1, sizeof(node));
		temp->num = N % 10;
		N = N / 10;
		temp->next = head;
		head = temp;
	}
	return head;
}