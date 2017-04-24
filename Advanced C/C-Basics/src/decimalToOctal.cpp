/*
OVERVIEW: 
1)Write a function which takes a decimal number as input and returns the octal number for decimalToOctal().
E.g.: decimalToOctal(10) returns 12.

2)Write a function which takes a fractional decimal number as input and returns the octal number for decimalToOctalFraction()
until precision two
E.g.: decimalToOctal(6.06) returns 6.03

INPUTS: Single decimal number num;

OUTPUT: Octal value of the Decimal Number num.

Discalimer:Return 0 for invalid cases.[Negetive Numbers]
*/
#include<stdlib.h>

int decimalToOctal(int num)
{
	if (num < 0)
		return 0;
	int temp = num, len = 0;
	for (len = 1; temp /= 10; len++);
	int *oct = (int *)calloc(2*len, sizeof(int));
	int sz = 0;
	for (sz = 0; num >= 1; sz++){
		oct[sz] = num % 8;
		num = num / 8;
	}
	int Octal = 0;
	for (int i = sz-1; i >=0; i--){
		Octal = Octal * 10 + oct[i];
	}
	return Octal;
}

float decimalToOctalFraction(float num)
{
	int dec = (int)num;
	float frac = num - (float)dec;

	if (num < 0.0)
		return 0;
	int temp = dec, len = 0;
	for (len = 1; temp /= 10; len++);
	int *oct = (int *)calloc(2 * len, sizeof(oct));
	int sz = 0;
	for (sz = 0; dec >= 1; sz++){
		oct[sz] = dec % 8;
		dec = dec / 8;
	}
	float Octal = 0;
	for (int i = sz - 1; i >= 0; i--){
		Octal = Octal * 10.0 + oct[i];
	}

	for (int i = 0; i < 2; i++){
		float f = frac * 8;
		Octal = Octal * 10.0 + (int)f;
		frac = f - (int)f;
	}
	Octal = (float)Octal / 100;
	return Octal;
}

