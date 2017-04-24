/*
Given 4 strings, write a fucntion to get smallest string that consists all four strings.
In Case of Multiple strings with smallest length,
Return the string which occurs alphabetically first .

Ex : (acat, tiger, silica, licaria) O/P: "silicariacatiger"
Ex : (def,abc,ghi,jkl)   O/P : “abcdefghijkl” (Alphabetically first )
Ex : (apple,pp,pineapple,nea) O/P: "pineapple";
Ex : (zzzabc,abcdef,yyyzzz,cabyyy) O/P: "cabyyyzzzabcdef" (Order Swapped )

Note : Each string given as input ,should be in the same format in the output string.
Ie if input string is abcd ,it cannot be modified as bdca in the final string .

The Order of Strings in the Final string ,maynot be in the same order
given in which they are given
Function Signatue : char * smallestword(char *s1,char *s2,char *s3,char *s4);

Note : You can use String.h functions .

Constraints :
Length of each String will be less than 100 .

Difficulty : Hard
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void ConCat(char *s1, char *s2){
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	int idx = len1;

	char *cp1, *cp2;
	cp1 = (char *)calloc(105, sizeof(cp1));
	cp2 = (char *)calloc(105, sizeof(cp2));
	for (int id = len1 - 1; id >= 0; id--){
		int k = 0, i = id, j = 0;
		if (len1 - id > len2)
			break;
		while (i<len1 && j<len2){
			cp1[k] = s1[i++];
			cp2[k] = s2[j++];
			k++;
		}
		cp1[k] = cp2[k] = '\0';
		if (strcmp(cp1, cp2) == 0){
			idx = id;
		}
	}

	int k = 0;
	for (int i = 0; i<len2; i++){
		s1[idx++] = s2[i];
	}

}
char * concat_4strings(char *s1, char *s2, char *s3, char *s4){
	if (!s1 && !s2 && !s3 && !s4)
		return NULL;

	char *str[5], *res;
	for (int i = 0; i<5; i++) str[i] = (char *)calloc(105, sizeof(char));
	res = (char *)calloc(450, sizeof(char));
	int minLen = 500;

	strcpy(str[0], s1);
	strcpy(str[1], s2);
	strcpy(str[2], s3);
	strcpy(str[3], s4);

	for (int i = 0; i<4; i++){
		for (int j = 0; j<4; j++){
			for (int k = 0; k<4; k++){
				for (int l = 0; l<4; l++){
					if (i^j && i^k && i^l && j^k && j^l && k^l){
						char *st = (char *)calloc(450, sizeof(char));

						strcpy(st, str[i]);
						if (strstr(st, str[j]) == NULL)
							ConCat(st, str[j]);
						if (strstr(st, str[k]) == NULL)
							ConCat(st, str[k]);
						if (strstr(st, str[l]) == NULL)
							ConCat(st, str[l]);
						int len = strlen(st);
						if (len < minLen){
							minLen = len;
							strcpy(res, st);
						}
						else if (len == minLen){
							if (len == 0){
								strcpy(res, st);
							}
							else {
								if (strcmp(st, res) == -1){
									strcpy(res, st);
								}
							}
						}
					}
				}
			}
		}
	}
	return res;
}
