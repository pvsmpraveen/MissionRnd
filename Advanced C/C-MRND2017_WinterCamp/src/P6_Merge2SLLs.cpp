/*

	Given two Singly linked lists which are in ascending order.
	Return an merged sorted SLL of both

	Ex:
		INPUT: 
			one: 1 -> 3 -> 5
			two: 2 -> 4 -> 6

		OUTPUT:
			1 -> 2-> 3-> 4-> 5-> 6


	NOTE:  Dont create any new SLL's. Just change the links

*/


#include<stdio.h>

struct Node {
	char data;
	Node *next;
};

struct Node* merge(struct Node *one, struct Node *two) 
{
	if (!one || !two) return NULL;

	Node *Aptr = one,*tmp1 = one,*tmp2 = two;

	while (tmp1){
		if (tmp1->data > tmp2->data){
			char tmp = tmp1->data;
			tmp1->data = tmp2->data;
			tmp2->data = tmp;
		}
		tmp1 = tmp1->next;
	}
	tmp1 = one;
	while (tmp1->next != NULL) tmp1 = tmp1->next;
	tmp1->next = two;

	return Aptr;
}