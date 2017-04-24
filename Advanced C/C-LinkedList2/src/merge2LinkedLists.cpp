/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <stdlib.h>
struct node {
	int num;
	struct node *next;
};

struct node *CreateNode(int K){
	node *nnode = (node *)calloc(1, sizeof(node));
	nnode->next = NULL;
	nnode->num = K;
	return nnode;
}

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	if (head1 == NULL && head2 == NULL)
		return NULL;

	node *head = NULL, *temp = NULL, *append;
	node *temp1 = head1, *temp2 = head2;

	while (temp1 && temp2){
		if ((temp1->num) < (temp2->num)){
			append = temp1;
			temp1 = temp1->next;
		}
		else{
			append = temp2;
			temp2 = temp2->next;
		}

		if (!head){
			head = CreateNode(append->num);
			temp = head;
		}
		else{
			temp->next = CreateNode(append->num);
			temp = temp->next;
		}
	}
	while (temp1){
		if (!head){
			head = CreateNode(temp1->num);
			temp = head;
		}
		else{
			temp->next = CreateNode(temp1->num);
			temp = temp->next;
		}
		temp1 = temp1->next;
	}
	while (temp2){
		if (!head){
			head = CreateNode(temp2->num);
			temp = head;
		}
		else{
			temp->next = CreateNode(temp2->num);
			temp = temp->next;
		}
		temp2 = temp2->next;
	}

	return head;

}