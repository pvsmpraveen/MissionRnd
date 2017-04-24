/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	if (head == NULL)
		return -1;

	node *temp = head;
	int cnt = 0;
	while (temp){
		temp = temp->next;
		cnt++;
	}
	int cnt2 = 0, med = 0;
	temp = head;
	while (temp){
		cnt2++;
		if (cnt % 2 == 0){
			if (cnt2 == cnt / 2 || cnt2 == cnt / 2 + 1)
				med += temp->num;
		}
		else{
			if (cnt2 == (cnt + 1) / 2)
				med += temp->num;

		}
		temp = temp->next;

	}
	return (cnt % 2 == 0) ? med / 2 : med;

}