/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>
#include <malloc.h>

#define SIZE 31


char ** getWords(char *str, int len, int *n){
	char **words = (char **)calloc(SIZE, sizeof(char *));
	int k = 0, i = 0, st = 0, ln, ed;
	while (i<len && str[i++] == ' '){ st = i; }

	char temp[SIZE];
	ln = 0;
	i = 0;
	for (i = st; i < len; i++){
		if (str[i] == ' '){
			ed = i;
			for (int j = st; j < ed; j++){
				temp[k++] = str[j];
			}

			temp[k] = '\0';
			if (k>0)
			{
				words[ln] = (char *)calloc(k + 1, sizeof(char));
				for (int i = 0; i < k; i++){
					words[ln][i] = temp[i];
				}
				words[ln][k] = '\0';
				k = 0;
				ln++;
			}
			while (i<len && str[i++] == ' '){ st = i; }
		}
	}

	k = 0;
	while (i<len && str[i++] == ' '){ st = i; }
	for (int i = st; i<len && str[i] != ' '; i++){
		temp[k++] = str[i];
	}

	if (k>0){
		words[ln] = (char *)calloc(k + 1, sizeof(char));
		for (int i = 0; i < k; i++){
			words[ln][i] = temp[i];
		}
		words[ln++][k] = '\0';
	}

	*n = ln;
	return words;

}

bool Compare(char *str1, char *str2){
	int len1, len2;
	for (len1 = 0; str1[len1]; len1++);
	for (len2 = 0; str2[len2]; len2++);
	if (len1 != len2)
		return false;

	for (int i = 0; i<len1; i++){
		if (str1[i] != str2[i])
			return false;
	}
	return true;
}

char ** commonWords(char *str1, char *str2) {
	if (str1 == NULL || str2 == NULL)
		return NULL;
	int len1, len2;

	for (len1 = 0; str1[len1]; len1++);
	for (len2 = 0; str2[len2]; len2++);

	int n1, n2;
	char **words1 = getWords(str1, len1, &n1);
	char **words2 = getWords(str2, len2, &n2);

	char **Common = (char **)calloc(SIZE, sizeof(char *));
	int n = 0, len;

	for (int i = 0; i<n1; i++){
		for (int j = 0; j<n2; j++){
			if (Compare(words1[i], words2[j])){
				for (len = 0; words1[len]; len++);
				Common[n] = (char *)calloc(len + 1, sizeof(char));
				for (int k = 0; k<len; k++){
					Common[n][k] = words1[i][k];
				}
				Common[n++][len] = '\0';
			}
		}
	}

	if (n == 0)
		return NULL;
	return Common;
}