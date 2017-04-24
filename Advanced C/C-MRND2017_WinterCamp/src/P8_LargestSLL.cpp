#include<stdio.h>

/*

	Given two natural numbers in the form of SLL's containing the digits.
	Without converting them into the numbers determine which one of them is higher.

	RETURN 0 if both are equal
	       -1 for invalid inputs
	        1 if 'one' is greater
	        2 if 'two' is greater
	
	If both inputs are NULL, return -1, not 0.

	Ex: 
		INPUT:
			one: 1 -> 2 -> 3
			two: 2 -> 3 -> 4

		OUTPUT: 2

*/

struct link
{
	int data;
	struct link *next;
};

int compare(struct link *one, struct link *two) {
	if (one == NULL && two == NULL) return -1;

	int len1 = 0, len2 = 0;
	link *tmp1 = one, *tmp2 = two;
	while (tmp1 && tmp1->data == 0) tmp1 = tmp1->next;
	while (tmp2 && tmp2->data == 0) tmp2 = tmp2->next;
	link *st1 = tmp1,*st2 = tmp2;
	while (tmp1) tmp1 = tmp1->next, len1++;
	while (tmp2) tmp2 = tmp2->next, len2++;

	if (len1 != len2){
		if (len1 > len2) return 1;
		else return 2;
	}
	while (st1 && st2){
		if (st1->data > st2->data)
			return 1;
		if (st1->data < st2->data)
			return 2;
		st1 = st1->next;
		st2 = st2->next;
	}
	return 0;
}