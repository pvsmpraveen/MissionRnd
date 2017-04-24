/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: 
A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

bool AreEqual(char *str1, char *str2){

	int i = 0;
	while (str1[i] && str2[i]){
		if (str1[i] != str2[i])
			return false;
		i++;
	}
	return true;
}

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A==NULL || B==NULL || ALen <=0 || BLen <=0)
		return NULL;
	
	transaction *ret = (transaction *)calloc(ALen + BLen + 5, sizeof(transaction));

	int i = 0, j = 0 ,k = 0;

	for (int i = 0; i < ALen; i++){
		for (int j = 0; j < BLen; j++){
			if (AreEqual(A[i].date, B[j].date)){
				ret[k++] = A[i];
			}
		}
	}
	if (k == 0)
		return NULL;
	return ret;
}