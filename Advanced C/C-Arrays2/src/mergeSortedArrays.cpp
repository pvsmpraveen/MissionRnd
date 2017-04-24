/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

int isOlder(char *dob1, char *dob2) {
	int len1, len2;
	for (len1 = 0; dob1[len1]; len1++);
	for (len2 = 0; dob2[len2]; len2++);
	int d1 = 0, m1 = 0, y1 = 0, d2 = 0, m2 = 0, y2 = 0;
	
	if (len1 != 10 || len2 != 10)
		return -1;

	for (int i = 0; i < 10; i++){
		if (i < 2){
			if (dob1[i] >= '0' && dob1[i] <= '9' && dob2[i] >= '0' && dob2[i] <= '9'){
				d1 = d1 * 10 + dob1[i] - '0';
				d2 = d2 * 10 + dob2[i] - '0';
			}
			else{
				return -1;
			}
			continue;
		}

		if ((i == 2 || i == 5)){
			if (dob1[i] != '-' || dob2[i] != '-')
				return -1;
			continue;
		}

		if (i >= 3 && i <= 4){
			if (dob1[i] >= '0' && dob1[i] <= '9' && dob2[i] >= '0' && dob2[i] <= '9'){
				m1 = m1 * 10 + dob1[i] - '0';
				m2 = m2 * 10 + dob2[i] - '0';
			}
			else{
				return -1;
			}
			continue;
		}

		if (dob1[i] >= '0' && dob1[i] <= '9' && dob2[i] >= '0' && dob2[i] <= '9'){
			y1 = y1 * 10 + dob1[i] - '0';
			y2 = y2 * 10 + dob2[i] - '0';
		}
		else{
			return -1;
		}
	}

	if (y1 != y2){
		if (y1 < y2)
			return 1;
		else
			return 2;
	}

	if (m1 != m2){
		if (m1 < m2)
			return 1;
		else
			return 2;
	}

	if (d1 != d2){
		if (d1 < d2)
			return 1;
		else
			return 2;
	}
	return 0;
}


struct transaction {
	int amount;
	char date[11];
	char description[20];
};



struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A==NULL || B==NULL || ALen<=0 || BLen<=0)
		return NULL;
	struct transaction *ret = (struct transaction *)calloc(ALen + BLen + 5, sizeof(transaction));
	int i = 0, j = 0,k=0;
	while (i < ALen && j < BLen){
		if (isOlder(A[i].date, B[j].date) == 1){
			ret[k++] = A[i++];
		}
		else{
			ret[k++] = B[j++];
		}
	}

	while (i < ALen){ ret[k++] = A[i++]; }
	while (j < BLen){ ret[k++] = B[j++]; }

	return ret;
}