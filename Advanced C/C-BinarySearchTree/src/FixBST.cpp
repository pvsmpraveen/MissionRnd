/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

  5
 / \
2   3
 \
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

         9
        / \
       4   1
      /     \
    20      30
Nodes 1 and 20 need to be fixed here .

*/
#include <stdio.h>
#include <stdlib.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

int InorderTraversal(struct node *root, int k, struct node **Address){
	if (!root)
		return k;

	if (root->left){
		k = InorderTraversal(root->left, k, Address);
	}
	//arr[k++] = root->data;
	Address[k++] = root;
	if (root->right){
		k = InorderTraversal(root->right, k, Address);
	}
	return k;

}

void fix_bst(struct node *root)
{
	if (!root)
		return;
	struct node **Address = (struct node **)calloc(4 * 10, sizeof(struct node *));
	int SIZE = InorderTraversal(root, 0, Address);

	int p, q;
	// Inorder Traversal Data Must be sorted if its BST.
	// Since Two Elements are swapped, used sortedArrayPositionsChange.cpp
	// And Interchanged the values in the address.

	for (int i = 0; i < SIZE - 1; i++){
		if (Address[i]->data>Address[i + 1]->data){
			p = i;
			break;
		}
	}

	for (int i = SIZE - 1; i>0; i--){
		if (Address[i]->data < Address[i - 1]->data){
			q = i;
			break;
		}
	}

	//cout << root << " " << Address[1] << endl;
	int tmp = Address[p]->data;
	Address[p]->data = Address[q]->data;
	Address[q]->data = tmp;
}