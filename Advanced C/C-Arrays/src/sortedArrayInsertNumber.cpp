/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use memory allocation techniques to allocate memory.

ProblemCode :SAIN
*/

#include <stdio.h>
#include <malloc.h>

int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
	if (Arr == NULL || len < 1)
		return NULL;
	Arr = (int *)realloc(Arr, (len + 1) * sizeof(int));
	int ok = 0;
	for (int i = 0; i<len; i++){
		if (num < Arr[i]){
			for (int j = len; j >= i; j--){
				Arr[j] = Arr[j--];
			}
			Arr[i] = num;
			ok = 1;
			break;
		}
	}
	if (!ok)
		Arr[len] = num;
	return Arr;
}