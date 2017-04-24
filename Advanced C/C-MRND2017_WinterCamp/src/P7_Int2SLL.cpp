/*
	
	Given an integer. Convert it into a SLL.

	Ex:
		INPUT: 12345

		OUTPUT: A SLL
			1 -> 2 -> 3 -> 4 -> 5


*/


#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node* int2LL(int n) {
	if (n < 0)
		return NULL;

	struct node *head = (node*)calloc(1, sizeof(node));
	head->data = n % 10;
	n /= 10;
	while (n) {
		node *t = (node *)calloc(1, sizeof(node));
		t->data = n % 10;
		n /= 10;
		t->next = head;
		head = t;
	}
	return head;
}

