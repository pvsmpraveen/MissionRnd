/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * sortLinkedList(struct node *head) {
	if (head == NULL || head->next == NULL){
		return head;
	}
	int tmp;
	node *t = head;
	node *ti = head, *tj;
	while (ti){
		tj = ti->next;
		while (tj){
			if (ti->num > tj->num){
				tmp = ti->num;
				ti->num = tj->num;
				tj->num = tmp;
			}
			tj = tj->next;
		}
		ti = ti->next;
	}
	return t;
}