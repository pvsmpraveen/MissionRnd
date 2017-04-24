
/*
OVERVIEW: Given a number N return all the prime numbers upto the integer N.
Ex: input: 10 output: [2,3,5,7] 

INPUTS: An Integer N

OUTPUT: Return an Array of Prime numbers until the number N(N inclusive)

ERROR CASES: Return NULL for invalid inputs

Sample Input : 10
Sample Output : An Array consisting elements {2,3,5,7}
NOTES:

Try to think of a optimized way , and avoid unnecessary comparisons.
*/

#include <stdio.h>
#include <stdlib.h>

int sum(int a, int b){

	return a + b;
}
int* nPrime(int N)
{
	if (N < 2)
		return NULL;

	int *Check = (int *)calloc(N+1,sizeof(int));
	for (int i = 2; i <= N; i++){
		if (!Check[i]){
			for (int j = i*i; j <= N; j += i){
				Check[j] = 1;
			}
		}
	}
	
	int Count = 0;
	for (int i = 2; i <= N; i++){
		if (!Check[i])
			Count++;
	}
	int *Result = (int *)calloc(Count, sizeof(int));
	int k = 0;
	for (int i = 2; i <= N; i++){
		if (!Check[i])
			Result[k++] = i;
	}
	return Result;
}