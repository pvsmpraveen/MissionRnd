/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/

char removeSpaces(char *str) {
	if (str == '\0')
		return '\0';
	int len = 0;
	for (len = 0; str[len]; len++);
	for (int i = 0; i < len; i++){
		if (str[i] == ' '){
			for (int j = i; j < len - 1; j++){
				str[j] = str[j + 1];
			}
			i--;
			len--;
		}
	}
	str[len] = '\0';
	return '\0';
}