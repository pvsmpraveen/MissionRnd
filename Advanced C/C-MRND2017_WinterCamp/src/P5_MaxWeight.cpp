/*

	Given an array of strings. 
	For each string calculate the weight and return the highest weight. 
	Weight is sum of all the absolute differences of ASCII codes of the consecutive characters.

	Weight is calculated as follows.
		"age" = abs(diff(a, g)) + abs(diff(g, e))

	Ex: 
		INPUT: 
			Array of Strings=> { "age", "get", "tap" }

		Explanation:
			weight of "age" = abs(1 - 7) + abs(7 - 5) = 6 + 2 = 8
			weight of "get" = abs(7 - 5) + abs(5 - 20) = 2 + 15 = 17
			weight of "tap" = abs(20 - 1) + abs(1 - 16) = 19 + 15 = 34

		OUTPUT: 
			Highest weight is 34 so return 34.

*/

#include <stdio.h>
#include <stdlib.h>

int maxWeight(char **strings, int len)
{
	if (strings == NULL || len == 0) return 0;
	int Max = 0;
	for (int i = 0; i < len; i++){
		int d = 0;
		for (int j = 1; strings[i][j]; j++){
			d += abs(strings[i][j] - strings[i][j - 1]);
		}
		if (d > Max) Max = d;
	}
	return Max;
}


/*
	Include other solutions of this questions here
	
*/