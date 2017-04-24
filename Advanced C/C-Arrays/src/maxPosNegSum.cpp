
/*
OVERVIEW: Given an array of integers find the maximum possible sum formed by a positive and the negative
integer in the array.
Ex: input: [1, 9, 8, 2, 3, -1,-10,-5] output: 8 (formed by 9 and -1) 

INPUTS: An Integer array and the length of the array

OUTPUT: Maximum possible sum formed by a positive and the negative integer in the array

ERROR CASES: Return 0 for the invalid inputs

NOTES:
*/

#include <stdio.h>

int maxPosNegSum(int* input,int length)
{
	if (length < 2)
		return 0;

	int pos = 0, neg = 0;
	int MaxPos = -1, MaxNeg = -2e9;
	for (int i = 0; i < length; i++){
		if (input[i] >= 0){
			if (input[i] > MaxPos)
				MaxPos = input[i];
			pos = 1;
		}
		else{
			neg = 1;
			if (input[i] > MaxNeg){
				MaxNeg = input[i];
			}
		}
	}
	if (!pos || !neg)
		return 0;
	return MaxPos + MaxNeg;
	return 0;
}