/*
A String(which only has small case a-z letters) is said to be corrupted if some of the charecters are removed and replaced by the number of characters removed .
Like : apple can be converted into a3e (ppl removed), or a4 (pple removed),ap2e (pl removed) .

helloworld can be modified as hello5 , h9 , 9d , etc , There is no limit on the number of characters that can be removed , or number of different times they can be 
removed .

Some more examples are ,abcdefghijkl can be modified as a2d2g4l , a10l .
If 2 or more numbers occured consecutively , you should consider them as a whole , like a23re , is not a "2Chars removed" "3Chars Removed" re , 
it is a "23 Chars removed" re .

Your Task is , Given two corrupted Strings , you need to find whether a common word can be formed from those both corrupted strings
, If Yes ,return 1 , If no word can formed return 0 , -1 For invalid inputs .

Ex Input : s1= "a4e" and s2="4e" , Example Output : 1 .

This is because , apple word can be formed from both .

Ex Input 2 : s1= "k2e2f" and s2="k1fr3" , Returns 0 . No common word can be formed from those both Strings .
Ex Input 3: "5e3" and "abcdeej2" returns 1 , where as if s1 is 5e3i and s2 is abcdeekoll returns 0

Constraints :
A String will only have letters from "a-z and 0-9" ;
0<=Len Of Str1,Str2 <=10000
Numbers occuring in the String can be anything from 1 till 999 .

You can implement the helper functions ,if you want ,Although its optional .Dont worry about space for this question .

Note : Only 25% of Cases ,will have numbers >9 in the Strings .
*/
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

int isDigit(char letter){
	if (letter >= '0' && letter <= '9')
		return 1;
	return 0;
}

int isLetter(char letter){
	if ((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z'))
		return 1;
	return 0;
}
int getLength(char *str){
	if (str == NULL)
		return -1;
	int len = 0;
	for (len = 0; str[len]; len++);
	return len;
}

char *getString(char *str, int *len){

	char *st = (char *)calloc(20002, sizeof(char));
	int Num = 0, k = 0;
	for (int i = 0; str[i]; i++){
		if (isDigit(str[i])){
			Num = Num * 10 + (str[i] - '0');
		}
		else{
			for (int j = 0; j<Num; j++){
				st[k++] = '0';
			}
			st[k++] = str[i];
			Num = 0;
		}

	}
	for (int j = 0; j<Num; j++){
		st[k++] = '0';
	}
	*len = k;

	return st;

}
int isSTRMatched(char *str1, char *str2){

	if (str1 == NULL || str2 == NULL)
		return -1;

	int len1, len2;
	char *st1 = getString(str1, &len1);
	char *st2 = getString(str2, &len2);

	if (len1 != len2)
		return 0;
	int len = len1;

	/*
	for(int i=0;i<len1;i++){
	cout << i << "  " << st1[i] << endl;;
	}
	for(int i=0;i<len2;i++){
	cout << i << "  " << st2[i] << endl;
	}
	*/

	for (int i = 0; i<len; i++){
		if (st1[i] == '0' || st2[i] == '0'){
			continue;
		}
		if (st1[i] != st2[i]){
			return 0;
		}
	}

	return 1;
}
