/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution.

Given nums = [1, 20, 2, 4], target = 24,

Because nums[1] + nums[3] = 20 + 4 = 24,
return [1, 3].

If target is 5 ,Return [0,3]
If target is 22 ,return [1,3]

Note : 
Return_Array[0] should always be less than Return_Array[1]

Constraints : 
len <100000 
-100000< nums[i] <100000

Question Source Link : https://leetcode.com/problems/two-sum/
We Picked this standard problem from Online , as its a very famous one and you will get habituated on solving on
Leetcode .
*/
#include <stdio.h>
#include <malloc.h>
int* sumoftwo(int *nums, int target, int len){
	
	if (nums == NULL || len <= 1)
		return NULL;
	int *ret = (int *)calloc(2, sizeof(int));
	
	/*
		// BRUTE FORCE 

	for (int i = 0; i < len-1; i++){
		for (int  j= i+1; j < len; j++){
			if (nums[i] + nums[j] == target){
				ret[0] = i;
				ret[1] = j;
				return ret;
			}
		}
	}
	*/


	int POS[100005], NEG[100005];
	for (int i = 0; i < 100005; i++){ POS[i] = NEG[i] = -1; }

	for (int i = 0; i < len; i++){
		if (nums[i] >= 0){
			POS[nums[i]] = i;
		}
		else{
			NEG[-nums[i]] = i;
		}
	}
	

	for (int i = 0; i < len; i++){
		int x = target - nums[i];
		if (x >= 0){
			if (POS[x] > i){
				ret[0] = i;
				ret[1] = POS[x];
				return ret;
			}
		}
		else{
			if (NEG[-x] > i){
				ret[0] = i;
				ret[1] = NEG[-x];
				return ret;
			}
		}
	}

	return NULL;
}