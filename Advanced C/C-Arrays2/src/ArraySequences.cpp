/*
Given an array which has two arithmetic sequences and
one geometric sequence (in any order).
Copy indexes where each sequence starts and ends into an Array and return it.

Note : Each sequence will be of atleast LENGTH 3,and The sequences can be overlapping

Ex : 1, 3, 5, 7, 2, 4, 8, 16 18 20, output is [0, 3, 7, 9, 4, 7]
Ex : 1 ,2, 4, 8, 12, 16, 21, 26     output is [2, 5, 5, 7, 0, 3]
Ex : 10 15 20 30 50 70 100 200 400 800  output is [0, 2, 3, 5, 6, 9]

The final_arr[0], final_arr[1] values in final array
will be start and end indexes of First A.P in the Original Array

The final_arr[2], final_arr[3] values in final array
will be start and end indexes of Second A.P

The final_arr[4], final_arr[5] values in final array
will be start and end indexes of First  G.P (Only)

Input: Array and Length of Array
Output : New Array which has 6 integers , which denote the (start,end) indexes .

Note : All elements in the array will be part of atleast 1 sequence .
Two A.P cannot start at same index .

Difficulty : Medium
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

bool fillGp(int *Ratio, int *Res, int len){
	for (int i = 1; i<len - 1; i++){
		if (Ratio[i] == Ratio[i + 1] && Ratio[i]){
			Res[4] = i - 1;
			for (int j = i + 1; j<len; j++){
				if (Ratio[j] == Ratio[i] && Ratio[j]){
					Res[5] = j;
				}
				else{
					break;
				}
			}
			return true;
		}
	}
	return false;
}
int * find_sequences(int *arr, int len){
	if (arr == NULL || len <= 0)
		return NULL;
	int *ratio1 = (int *)calloc(len + 5, sizeof(int));
	int *ratio2 = (int *)calloc(len + 5, sizeof(int));
	int *diff = (int *)calloc(len + 5, sizeof(int));
	int *ret = (int *)calloc(6, sizeof(int));

	for (int i = 1; i <len; i++){
		diff[i] = arr[i] - arr[i - 1];
		if (arr[i - 1] && arr[i] % arr[i - 1] == 0)
			ratio1[i] = arr[i] / arr[i - 1];
		else
			ratio1[i] = 0;
		if (arr[i] && arr[i - 1] % arr[i] == 0){
			ratio2[i] = arr[i - 1] / arr[i];
		}
		else{
			ratio2[i] = 0;
		}
	}

	ratio1[0] = ratio2[0] = -1;
	bool gp = false;
	if (!gp) gp = fillGp(ratio1, ret, len);
	if (!gp) gp = fillGp(ratio2, ret, len);

	for (int i = 1; i<len - 1; i++){
		if (diff[i] == diff[i + 1]){
			ret[0] = i - 1;
			for (int j = i; j<len; j++){
				if (diff[j] == diff[i])
					ret[1] = j;
				else{
					break;
				}
			}
			break;
		}
	}
	for (int i = ret[1]; i<len - 1; i++){
		if (diff[i] == diff[i + 1]){
			ret[2] = i - 1;
			for (int j = i; j<len; j++){
				if (diff[j] == diff[i])
					ret[3] = j;
				else{
					break;
				}
			}
			break;
		}
	}
	return ret;
}