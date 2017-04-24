/*

	Given an boolean 2-D square array.
	Return the row and column whose decimal equivalent is highest.

	Ex: 
		INPUT: 
			1 0 1 0
			0 1 0 1
			1 1 0 0
			0 0 1 1

		Explanation:
			1st row decimal equivalent = 10 ; 2nd row = 5 ; 3rd row = 12 ; 4th row = 3
			1st column decimal equivalent = 10; 2nd column = 6; 3rd column = 9; 4th column = 5

		OUTPUT: 
			Change the value at address of res_row and res_col as given in function signature
			res_row is 3 and res_col 1

*/

#include <stdio.h>
#include <stdlib.h>


void highestDec(int **arr, int len, int *res_row, int *res_col)
{
	if (arr == NULL || len == 0) return;
	int MaxR = -1, MaxC = -1;
	for (int i = 0; i < len;i++){
		int c = 0, r = 0,two=1;
		for (int j = len - 1; j >= 0; j--){
			if (arr[i][j])
				r += two;
			two = two * 2;
		}
		two = 1;
		for (int j = len - 1; j >= 0; j--){
			if (arr[j][i])
				c += two;
			two = two * 2;
		}
		if (c > MaxC) {
			*res_col = i+1;
			MaxC = c;
		}
		if (r > MaxR){
			*res_row = i+1;
			MaxR = r;
		}
	}
}


/*

	Include other solutions of this question here.


*/

