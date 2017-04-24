/*
OVERVIEW:
1)Write a function which takes a octal number as input and returns the hexadecimal number for 
  octalToHexadecimal().
E.g.: octalToHexadecimal(10) returns 8.

2)Write a function which takes a fractional octal number as input and returns the hexadecimal number for 
octalToHexadecimalFraction() until precision two
E.g.: octalToHexadecimal(6.01) returns 6.04

INPUTS: Single octal number num;

OUTPUT: hexadecimal value of the octal number num.

Discalimer:Return 0 for invalid cases.[Negetive Numbers]
*/
#include<stdlib.h>
#include<math.h>
int octalToHexadecimal(long int num)
{
	if (num < 0)
		return 0;
	int temp = num, len = 0;
	for (len = 1; temp /= 10; len++);
	int Dec = 0;
	int Pw8 = 1;
	while (num >= 1){
		Dec = Dec + (num % 10)*Pw8;
		Pw8 *= 8;
		num = num / 10;
	}

	int Hexa = 0;
	int Pw10 = 1;
	while (Dec >= 1){
		Hexa = Hexa + (Dec % 16)*Pw10;
		Pw10 *= 10;
		Dec = Dec / 16;
	}
	return Hexa;
}

float octalToHexadecimalFraction(float num)
{
	float Hexa = octalToHexadecimal((int)num);
	float f = num - (int)num;
	int fr = ceil(f*1e6);  

	//Taking 6 digits after decimal in octal as 
	//we need only 2 digits in Hexa, 6 are more than 
	//enough if not then at max go for 9 digits. 
	//Because INT_MAX is 4*10^9. 

	int frac[6] = { 0 };
	for (int i = 5; i >= 0; i--){
		frac[i] = fr % 10;
		fr = fr / 10;
	}
	float dec = 0.00;
	float Eight = 8.00;
	for (int i = 0; i <= 5; i++)
	{
		float f = frac[i];
		dec = dec + (float)f / Eight;
		Eight *= 8;
	}

	for (int i = 0; i < 2; i++){
		float f = dec * 16;
		Hexa = Hexa * 10.0 + (int)f;
		dec = f - (int)f;
	}
	Hexa = Hexa / 100.0;
	return Hexa;
}