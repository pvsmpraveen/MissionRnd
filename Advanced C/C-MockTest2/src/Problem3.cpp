/*

Akash is genius reverse engineer, invented a world demanded machine and Kept in a secret building with a passkey.
Sam is very excited to see his wonderful creation. So, she went to the building with the pass key which is a
numeric code example "547". But there are many doors with lock in a linear fashion such that
she can cross second door only after crossing first door.

First door pass key is the largest number that can be formed by given passkey -> 754
Second door pass key is the next largest number that can be formed -> 745
Third door opens for next largest number ->574



Find which Nth door's room contains the machine or How many doors should Sam cross ?

Given input is in form of Doubly Linked List
eg: 7 <-> 5 <-> 8  o/p: 4

explanation: (1) 875 (2) 857 (3) 785 (4) 758

NOTE:	(1)	DLL can contain maximum of 12 nodes
(2)	All doors will have a Passkey which is formed by the numbers of the original pass key only
(3) From the first door to last, passkey will be in decreasing order.
(4) Duplicates are allowed
(5) "075" is not treated as "75". 0 is also given same importance as others.

Return NULL for invalid cases.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	int num;
	struct node *prev;
	struct node *next;
};


int fact(int n){
	int ans = 1;
	for (int i = 1; i <= n; i++) ans = ans*i;
	return ans;
}

int Right(char* str, int low, int high)
{
	int cc = 0, i;

	for (i = low + 1; i <= high; ++i)
		if (str[i] < str[low])
			++cc;
	return cc;
}

int findRank(char* str)
{
	int len = strlen(str);
	int mul = fact(len);
	int Rank = 1;
	int countRight;
	int i;
	for (i = 0; i < len; ++i){
		mul /= len - i;
		countRight = Right(str, i, len - 1);
		Rank += countRight * mul;
	}
	return Rank;
}


int doorstoCross(struct node *passKey)
{
	if (passKey == NULL)
		return NULL;
	struct node *temp = passKey;
	int len = 0, k = 0;
	char key[50] = { '\0' };
	while (temp){
		key[k++] = temp->num + '0';
		temp = temp->next;

	}
	key[k] = '\0';
	if (k == 0) return NULL;
	puts(key);

	return fact(k) - findRank(key) + 1;

}