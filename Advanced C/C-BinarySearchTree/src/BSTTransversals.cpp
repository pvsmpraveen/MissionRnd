/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

int InorderTraversal(struct node *root, int *arr, int k){
	if (!root)
		return k;

	if (root->left){
		k = InorderTraversal(root->left, arr, k);
	}
	arr[k++] = root->data;
	if (root->right){
		k = InorderTraversal(root->right, arr, k);
	}
	return k;

}

void inorder(struct node *root, int *arr){
	if (!root || !arr)
		return;
	InorderTraversal(root, arr, 0);
}


int PreorderTraversal(struct node *root, int *arr, int k){
	if (!root)
		return k;
	arr[k++] = root->data;
	if (root->left){
		k = PreorderTraversal(root->left, arr, k);
	}
	
	if (root->right){
		k = PreorderTraversal(root->right, arr, k);
	}
	return k;
}

void preorder(struct node *root, int *arr){
	if (!root || !arr)
		return;
	PreorderTraversal(root, arr, 0);
}

int PostorderTraversal(struct node *root, int *arr, int k){
	if (!root)
		return k;
	
	if (root->left){
		k = InorderTraversal(root->left, arr, k);
	}
	if (root->right){
		k = InorderTraversal(root->right, arr, k);
	}
	arr[k++] = root->data;
	return k;

}
void postorder(struct node *root, int *arr){
	if (!root || !arr)
		return;
	PostorderTraversal(root, arr, 0);
}

