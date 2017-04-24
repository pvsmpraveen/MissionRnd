/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};



int* BSTRighttoLeftRows(struct node* root)
{
	if (!root)
		return NULL;
	struct node **Queue = (struct node **)calloc(100, sizeof(node *));
	int *Ret = (int *)calloc(100, sizeof(int)),k=0;

	Queue[0] = root;
	int i = 0, j = 1;
	while (i != j){
		node *u = Queue[i++];
		Ret[k++] = u->data;
		if (u->right){
			Queue[j++] = u->right;
		}
		if (u->left){
			Queue[j++] = u->left;
		}
	}
    return Ret;
}
