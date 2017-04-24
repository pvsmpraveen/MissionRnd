/*
OVERVIEW: Given an Integer Array return the count of one's and two's in a new array of length two.
Ex: input: [1,2,2,1,2,1,2] 
	output: [3,4]
	where 3 is the count of 1's and 4 is the count of 2's

INPUTS: An Integer Array and length of the array 

OUTPUT: An Array with 1's count and 2's count

ERROR CASES: Return NULL for invalid inputs

Difficulty : Very Easy
*/

#include <stdio.h>
#include <stdlib.h>
int* oneTwoCount(int* input, int length)
{
	if (length < 2)
		return NULL;
	int *Result = (int *)calloc(2, sizeof(int));
	for (int i = 0; i < length; i++){
		if (input[i] == 1){
			Result[0]++;
		}
		else if (input[i] == 2){
			Result[1]++;
		}
	}
	return Result;
}