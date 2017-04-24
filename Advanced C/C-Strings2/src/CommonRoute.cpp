/*
There are two friends Hack and Code . They have decided to go on a world tour which consists of only Islands.
There are a total of 26 Islands in the world ,where Each Island has a name from A ,B ,C ,D ... till Z .
[Each Island name is restricted to only 1 Letter]

Hack and Code seperately made their travel lists ,where they specify List of Islands they want to visit
in a particular order .
Ex : If Hack's List is "CADBZ" , He wants to go first to C island ,next A island and B and so on ,and finally
reach Z island .

Now Hack and Code had shared their lists , and they observed that their lists are not at all similar .
No one wants to compromise on their Travel List and Order,and each wants other person to accept their List .
After a through discussion,They finally decided that they will Find the Common route in the List which covers
Maxium Islands and make that their Tour .

Cost of Visting each Island will be equal to the position in the Alphabats Series that Island Name is( Letter ) .
Cost of Visiting A island is 1 ,H is 8 , Z is 26 and so on .
Can you help Hack and Code to find the Common Route ,so that their dispute is solved .

Inputs :
Two Strings of Capital Letters ,where each Letter denotes an Island .They can visit each Island any
number of times.
Output :
Return a Common Route String which covers maxiumum Islands

Example 1 :
Input : HackList="CADBZAYZY" CodeList="BZAYACAFRDBZ"
Output: Return "BZAY" and modify the Cost variable to  54 [2+26+1+25]
Explanation :
They both can start at B ,Go to Z ,and go to A,Finally reach Y .This Route covers 4 islands ,where
all other routes like CA ,DBZ , ZAY ,etc covers less than 4 islands .

Note : If there are Two Maximum routes which cover Equal number of Islands , Return the Route which Costs
less . IF the Costs are also equal ,Return the Route ,whose FirstIsland is Alphabetically Before
[Assume two routes with same cost ,will always have first island a different one].

Final Route Islands should be in Both Hack and Codes list and in same order ,If Final route is ACB
There must be a route in both Lists which is ACB . [AZZCB , ADCDB dont qualify ,Order should be continous]
Return NULL for Invalid Inputs or No Common Route[Cost will be 0].

Example 2 : Input : "CABTYUZZZ" , "ZZZTYUCAB" , Output : "CAB" and cost should be 6 (Least Cost )
Example 3 : Input : "HHHZAADTD" , "ZAAHHHDTDRR" , Output : "DTD" (DTD , HHH ,ZAA has same cost of 28 ,but the
First Island in DTD ie 'D' occurs alphabatically before 'H' and 'Z')

*/

#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


char *CopyString(char *s, int st, int ed){
	char *ret = (char *)calloc(strlen(s) + 5, sizeof(char));
	int k = 0;
	for (int i = st; i <= ed; i++){
		ret[k++] = s[i];
	}
	return ret;
}

char * GetBest(char *s1, char *s2){
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	int Len = len1>len2 ? len1 : len2;
	char *ret = (char *)calloc(Len + 5, sizeof(char));

	if (len2 > len1){
		strcpy(ret, s2);
		return ret;
	}
	if (len1 > len2){
		strcpy(ret, s1);
		return ret;
	}

	int Cost1 = 0, Cost2 = 0;
	for (int i = 0; i<Len; i++){
		Cost1 += (s1[i] - 'A' + 1);
		Cost2 += (s2[i] - 'A' + 1);
	}
	if (Cost1 < Cost2){
		strcpy(ret, s1);
		return ret;
	}
	if (Cost2 < Cost1){
		strcpy(ret, s2);
		return ret;
	}
	if (strcmp(s1, s2) == -1){
		strcpy(ret, s1);
		return ret;
	}
	if (strcmp(s1, s2) == 1){
		strcpy(ret, s2);
		return ret;
	}
	strcpy(ret, s2);
	return ret;

}

char *findString(char *big, char *small, int len1, int len2, int StrtIdx){
	char *str = (char *)calloc(len2 + 5, sizeof(char));
	char *res = (char *)calloc(len2 + 2, sizeof(char));
	int *diff = (int *)calloc(len2 + 5, sizeof(int));

	int Idx = StrtIdx;
	int k = 0;
	while (Idx<0){
		Idx++;
		k++;
	}
	int Idx2 = k;
	for (int i = Idx; i<len2 && big[k]; i++){
		diff[i] = small[i] - big[k];
		k++;
	}
	bool ok = false;
	int i = Idx, j = Idx2, st = 0, ed = 0, maxLen = 0;
	while (i<len2 && big[j]){
		if (diff[i] == 0){
			st = i;
			while (diff[i] == 0 && i<len2 && big[j]){
				ed = i;
				i++;
				j++;
			}
			if (i == len2){
				ed = i;
			}
			if (ed - st + 1 >= maxLen){
				str = CopyString(small, st, ed);
				res = GetBest(res, str);
				maxLen = strlen(res);
			}
		}
		i++;
		j++;
	}
	return res;
}
char * find_common_route(char * hacklist, char *codelist, int *cost){
	if (hacklist == NULL || codelist == NULL)
		return NULL;

	char *small, *big;  //else both are equal length.
	if (strlen(hacklist) < strlen(codelist)){
		small = hacklist;
		big = codelist;
	}
	else{
		small = codelist;
		big = hacklist;
	}

	int len1 = strlen(big);
	int len2 = strlen(small);

	char *ret = (char *)calloc(len1 + 5, sizeof(char));
	int maxLength = 0;

	for (int i = -len1 + 1; i<len2; i++){	//O(2*max(m,n))
		/*Sliding big-string over small-string.
		    BCAD 	- small-string
			ADBEC 	- big-string

			Idx : -4
			BCAD
	    ADBEC

			Idx : -3
			BCAD
		 ADBEC

			Idx : -2
			BCAD
		  ADBEC

			Idx : -1
			BCAD
		   ADBEC

			Idx : 0
			BCAD
			ADBEC

			Idx : 1
			BCAD
			 ADBEC

			Idx : 2
			BCAD
			  ADBEC

			Idx : 3
			BCAD
   			   ADBEC
   		*/

		char *got = findString(big, small, len1, len2, i);  
		int len = strlen(got);
		if (len >= maxLength){
			ret = GetBest(ret, got);
		}
	}
	int Len = strlen(ret);
	if (Len == 0){
		*cost = 0;
		return NULL;
	}
	int Cost = 0;
	for (int i = 0; i<Len; i++){
		Cost += (ret[i] - 'A' + 1);
	}

	*cost = Cost;
	return ret;
}