/*
Problem Code : ISDIVSLL

You are Given an SLL where each Node has a character (which is picked from digits or '-'/'+') and a Key integer .
Example SLL : '1' -> '2' -> '3' -> '4' 

You need to return 1 if the sum of numbers formed by (the SLL and reverse SLL) is divisible by key ,Return 0 otherwise . Return -1 for invalid cases  .

Sample Input :
SLL: '+'->'1'->'3'->'6'; (which is 136) and Key is 59 .

Sample Output :
1

If Key is 67 in the above example ,You should return 0 .

Explanation :
SLL is 136 , Reverse SLL is 631 . Sum is 631+136 = > 767 . 767 is divisible by 59 , So you should return 1 .

Constraints :

->Characters Range will be in from the following string "+-0123456789" .
->Length of SLL will be less than 10Nodes .
->0<=Key<=10000000
->First char need not defenetly be a sign , if its a digit ,it is considered as a positive number .

Note : Reverse of a negetive SLL is negetive only .And -963 can be divided by 3 . 
*/

#include <stddef.h>
#include <malloc.h>
#include <stdio.h>

struct charNode{
	char letter;
	struct charNode *next;
};


int isDivisibleSLL(struct charNode * head, int key){
	if (head == NULL || key == 0)
		return -1;
	struct charNode *temp = head;
	int len = 0;

	while (temp){
		temp = temp->next;
		len++;
	}

	int *Arr = (int *)calloc(len + 1, sizeof(int)), k = 0;

	temp = head;
	while (temp){
		if (temp->letter >= '0' && temp->letter <= '9'){
			Arr[k++] = (temp->letter - '0');
		}
		temp = temp->next;
	}

	int Sum = 0, RevSum = 0;
	for (int i = 0; i<k; i++){
		Sum = Sum * 10 + Arr[i];
		RevSum = RevSum * 10 + Arr[k - i - 1];
	}

	int x = Sum + RevSum;

	if (x%key == 0)
		return 1;
	return 0;
}
