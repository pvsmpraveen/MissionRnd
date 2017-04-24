/*

Problem : Return the Last word in a string

Input : I will do this without using String Library
Output : Library

Note:Dont modify original string Neglect Spaces at the right end and at left end if required .
->Create a new string and return it , Use dynamic memory allocation .
*/
#include <stdlib.h>

char * get_last_word(char * str){
	if (str == NULL)
		return NULL;
	int len = 0, ed, st;
	for (len = 0; str[len]; len++);
	for (ed = len - 1; ed > 0; ed--){
		if (str[ed] != ' ')
			break;
	}
	for (st = ed - 1; st > 0; st--){
		if (str[st] == ' ')
			break;
	}
	if (st) st++;
	if (!ed) ed--;
	char *ret = (char *)calloc(ed - st + 5, sizeof(char));
	int k = 0;

	for (int i = st; i <= ed; i++){
		ret[k++] = str[i];
	}

	return ret;
}