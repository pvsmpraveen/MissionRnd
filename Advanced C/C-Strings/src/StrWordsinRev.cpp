/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <stdio.h>
#include <string.h>

void reverseIT(char *str, int l, int r){
	for (int i = l, j = r; i<j; i++, j--){
		char temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}

void str_words_in_rev(char *input, int len){
	if (input == '\0')
		return;
	reverseIT(input, 0, len - 1);
	int st = 0, ed;
	for (int i = 0; i<len; i++){
		if (input[i] == ' '){
			ed = i;
			reverseIT(input, st, ed - 1);
			st = i + 1;
		}
	}
	reverseIT(input, st, len - 1);
	return;
}
