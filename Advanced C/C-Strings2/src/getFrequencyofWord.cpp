/*

Problem : Return the Count of how many times the word occurred in given string in two ways
Way1: Not using Recursion
Way2:Using Recursion [Optional]

Input : "Hello HelloAgain HelloAGAINAGAIN commonItsHelloagain","Hello"
Output : 4

Note: Dont modify original str or word,Just return count ,Spaces can also be part of words like "ab cd" in "ab cd ab cd" returns 2
*/

#include <stdlib.h>

int count_word_in_str_way_1(char *str, char *word){
	if (str == NULL || word == NULL)
		return -1;
	int len1, len2;
	int count = 0;
	for (len1 = 0; str[len1]; len1++);
	for (len2 = 0; word[len2]; len2++);
	for (int i = 0; i < len1 - len2 + 1; i++){

		bool ok = true;
		int k = 0;
		for (int j = i; j < i + len2; j++){
			if (str[j] != word[k++])
				ok = false;
		}
		if (ok)
			count++;
	}
	return count;
}



int count_word_int_str_way_2_recursion(char *str, char *word){
	return 0;
}

