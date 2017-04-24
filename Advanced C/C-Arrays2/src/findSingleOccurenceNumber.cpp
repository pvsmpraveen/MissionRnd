/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
There are better ways of solving the problem than a brute-force solution which is of O(n^2)
complexity .
*/

#include<stdio.h>
#include <stdlib.h>

int cmp(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}
int findSingleOccurenceNumber(int *A, int len) {
	if (A == NULL || len <= 0)
		return -1;

	qsort(A, len, sizeof(int), cmp);

	int Num = A[0], cnt = 1;
	for (int i = 1; i < len; i++){
		if (A[i] == Num){
			cnt++;
		}
		else{
			if (cnt == 1)
				return A[i - 1];
			Num = A[i];
			cnt = 1;
		}
	}
	return Num;
}