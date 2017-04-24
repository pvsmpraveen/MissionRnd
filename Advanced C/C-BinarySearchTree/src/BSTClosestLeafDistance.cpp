/*
Given a Binary Search Tree and a Node(temp).Find the Closest Distance from the Node to 
any leaf of the Tree.
(Least number of Edges needed to be travelled to go to the Node )

Ex : Consider the below tree .
      2
     / \
,   1   3
         \
         14
For 3 ,Output is 1 . As its closest leaf is 14 and 3 is at a distance of 1 to 14 .

Ex 2: Consider the below tree .
    2
   / \
  1   3
       \
        14
        / \
       9   20
      /      \
     6       25
For 3 ,Output is now 2 . As closest leaf to 3 is 1 and 3 is at a distance of 2 to 1 .
(through root 2 )

For 14 ,O/P : 2
For 2 , O/P : 1

Return -1 ,for Invalid Inputs
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
  struct node * left;
  int data;
  struct node *right;
};


int min(int a, int b){
	return a < b ? a : b;
}

int MinLeafDist(struct node *temp){
	if (temp == NULL)
		return 0;
	int x = 0, y = 0;
	if (temp->left){
		x = 1 + MinLeafDist(temp->left);
	}
	if (temp->right){
		y = 1 + MinLeafDist(temp->right);
	}
	if (x>0 && y == 0)
		return x;
	if (y>0 && x == 0)
		return y;
	return min(x, y);
}

int SubTreeToTemp(struct node *root, struct node *temp, int *Min){
	int x = 0, y = 0;
	if (root == NULL){
		return 555555; //Return some MaxValue if temp is not found in the SubTree.
	}
	// printf("%d %d\n",root->data,MinLeafDist(root));
	if (root == temp){
		return 0;
	}
	x = 1 + SubTreeToTemp(root->left, temp, Min);
	y = 1 + SubTreeToTemp(root->right, temp, Min);

	//printf("%d %d %d %d\n",root->data,MinLeafDist(root),x,y);

	*Min = min(*Min, min(MinLeafDist(root) + x, MinLeafDist(root) + y));
	return min(x, y);
}

int get_closest_leaf_distance(struct node *root, struct node *temp)
{
	if (root == NULL || temp == NULL)
		return -1;
	int d = MinLeafDist(temp);
	int Min = 555555;	//Assign Max to get Min.
	SubTreeToTemp(root, temp, &Min);
	return min(Min, d);
}