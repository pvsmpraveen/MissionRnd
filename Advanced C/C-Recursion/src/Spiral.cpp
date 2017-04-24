/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>

void FillItSpiral(int **input_array, int rows, int cols, int i, int j, int *ret, int Type, int *k){
	// Type 0 - Right
	// Type 1 - Down
	// Type 2 - Left
	// Type 3 - Up

	if (i<0 || j<0 || i >= rows || j >= cols)
		return;

	int x = input_array[i][j]; //Set.
	ret[(*k)++] = x;
	
	if (j<cols && input_array[i][j] != -1 && Type == 0){
		input_array[i][j] = -1;
		if (j + 1 != cols && input_array[i][j + 1] != -1)
			FillItSpiral(input_array, rows, cols, i, j + 1, ret, 0, k);
		else if (i + 1 != rows &&  input_array[i + 1][j] != -1)
			FillItSpiral(input_array, rows, cols, i + 1, j, ret, 1, k);
	}

	if (i<rows && input_array[i][j] != -1 && Type == 1){
		input_array[i][j] = -1;
		if (i + 1 != rows && input_array[i + 1][j] != -1)
			FillItSpiral(input_array, rows, cols, i + 1, j, ret, 1, k);
		else if (j - 1 != -1 && input_array[i][j - 1] != -1)
			FillItSpiral(input_array, rows, cols, i, j - 1, ret, 2, k);
	}
	if (j >= 0 && input_array[i][j] != -1 && Type == 2){
		input_array[i][j] = -1;
		if (j - 1 != -1 && input_array[i][j - 1] != -1)
			FillItSpiral(input_array, rows, cols, i, j - 1, ret, 2, k);
		else if (i - 1 != -1 && input_array[i - 1][j] != -1)
			FillItSpiral(input_array, rows, cols, i - 1, j, ret, 3, k);
	}
	if (i >= 0 && input_array[i][j] != -1){
		input_array[i][j] = -1;
		if (i - 1 != 0 && input_array[i - 1][j] != -1)
			FillItSpiral(input_array, rows, cols, i - 1, j, ret, 3, k);
		else if (j + 1 != cols && input_array[i][j + 1] != -1)
			FillItSpiral(input_array, rows, cols, i, j + 1, ret, 0, k);
	}
	input_array[i][j] = x; //Reset.
}

int *spiral(int rows, int columns, int **input_array)
{
	if (input_array == NULL || columns <= 0 || rows <= 0)
		return NULL;

	int *ret = (int *)calloc((rows + 1)*(columns + 1), sizeof(int));
	int k = 0;
	FillItSpiral(input_array, rows, columns, 0, 0, ret, 0, &k);
	return ret;

}

/*  --- ITERATIVE ----
int *spiral(int rows, int columns, int **input_array)
{
	if (input_array == NULL || columns <= 0 || rows <= 0)
		return NULL;

	int *ret = (int *)calloc((rows+1)*(columns+1), sizeof(int));
	
	int Count = 0;

	int i = 0, j = 0;
	int L = 0, R = columns - 1, U = 0, D = rows - 1;
	while (Count < rows*columns){
		while (j <= R){
			ret[Count++] = input_array[i][j];
			j++;

		}
		i++;
		j = R;
		U++;
		while (i <= D){
			ret[Count++] = input_array[i][j];
			i++;
		}
		j--;
		i = D;
		R--;
		while (j >= L){
			ret[Count++] = input_array[i][j];
			j--;
		}
		i--;
		D--;
		j = L;
		while (i >= U){
			ret[Count++] = input_array[i][j];
			i--;
		}
		j++;
		L++;
		i = U;

	}
	
	return ret;
	
}
*/