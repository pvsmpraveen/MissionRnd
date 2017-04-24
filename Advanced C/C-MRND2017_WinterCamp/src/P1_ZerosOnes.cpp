/*

	Given an Array which contains only zeros and ones. Sort them. 
	
	INPUT: Array
	OUTPUT: No need to return anything. Do inplace sort.

	As Discussed in class, write all the solutions and comment them. Keep one of them for testing.

	In the Spec file, there are only base cases. 
	As you are writing the codes with testcases, implement all of them in spec file. 
	From this, you can also learn testing.

	Go through the spec files carefully such that you will understand how to add additional testcases

	Follow this for all the problems

*/

#include <stdio.h>
#include <stdlib.h>


void sortZerosnOnes(int *arr, int len)
{
	if (arr == NULL || len==0) return;
	int one = 0, zero = 0,k=0;
	for (int i = 0; i < len; i++) !arr[i]? zero++ : one++;
	while (zero--) arr[k++] = 0;
	while (one--) arr[k++] = 1;
}

/*

	Write your other methods here


*/