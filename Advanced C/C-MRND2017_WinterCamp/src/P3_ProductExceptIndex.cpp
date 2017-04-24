/*

	Given an array of integers. 
	Return an array of same length such that resultant array at index i should contain the -
	product of all the integers except the integer at index i.

	INPUT: Array
	OUTPUT: int pointer of that resultant array

	Ex: 
		INPUT: 1, 2, 3, 4, 5 
		OUTPUT: 120, 60, 40, 30, 24


	You must consider all possible testcases like zeros etc...

	Implement all the methods.


*/

#include <stdio.h>
#include <stdlib.h>


int *productExceptIndex(int *arr, int len)
{
	if (arr == NULL || len == 0) return NULL;
	int *res = (int *)calloc(len, sizeof(int));

	if (len == 1) return res;

	int cnt = 0, Mul = 1;
	for (int i = 0; i < len; i++) arr[i] ? Mul *= arr[i] : cnt++;

	if (cnt == 2){
		for (int i = 0; i < len; i++) arr[i] = 0;
	}
	else if (cnt == 1){
		for (int i = 0; i < len; i++)
			res[i] = arr[i] ? 0 : Mul;
	}
	else{
		for (int i = 0; i < len; i++) 
			res[i] = Mul / arr[i];
	}
	return res;
}


/*

	Include other solutions of this question here.

	
*/


