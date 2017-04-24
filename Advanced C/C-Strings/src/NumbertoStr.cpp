/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>
#include <math.h>

void number_to_str(float number, char *str, int afterdecimal){
	int len = 0;
	if (number < 0){
		str[len++] = '-';
		number = number * (-1);
	}
	long double f = number - int(number);
	int i, n = int(number);
	int rev = 0;
	while (n){
		rev = rev * 10 + n % 10;
		n = n / 10;
	}

	i = 0;
	while (rev){
		str[len++] = rev % 10 + '0';
		rev = rev / 10;
	}
	if (f == 0.00)
		return;

	str[len++] = '.';

	//15 digit precision.
	long long int d = ceil(f*1e15);
	int AfterDec[15] = { 0 };
	for (int i = 14; i >= 0; i--){
		AfterDec[i] = d % 10;
		d = d / 10;
	}
	for (int i = 0; i< afterdecimal; i++){
		str[len++] = AfterDec[i] + '0';
	}
	str[len] = '\0';

}