/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include<stdio.h>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int Older(char *dob1, char *dob2) {
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
		if (y1 < y2) return 1;
		else return 2;
	}

	if (m1 != m2){
		if (m1 < m2) return 1;
		else return 2;
	}

	if (d1 != d2){
		if (d1 < d2) return 1;
		else return 2;
	}

	return 0;
}


int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	if (Arr == NULL || len<=0 || date==NULL)
		return -1;
	int i;
	for (i = 0; i < len; i++){
		if (Older(Arr[i].date, date) == 2)
			break;
	}

	return len - i;
}
