/*
Given a value n

1. return nth Fibonacci number for the function nthFibonacci(int)
	EX: 0 for n=1 and 1 for n=2


2. return nth prime number for the function nthPrime(int)
	EX: 2 for n=1 and 3 for n=2

INPUTS: single integer n

OUTPUTS: nth Fibonacci number for nthFibonacci() 
		 nth prime number for nthPrime()

ERROR CASES: return -1 for the error cases
*/

int nthFibonacci(int n)
{
	if (n <=0 )
		return -1;
	if (n <= 2)
		return n - 1;
	return nthFibonacci(n-1) + nthFibonacci(n-2);
}

int nthPrime(int num)
{
	if (num <= 0)
		return -1;
	int count = 0;
	int x = 1;
	bool ok;

	while (count != num){
		x++;
		ok = true;
		for (int i = 2; i < x; i++){
			if (x % i == 0)
				ok = false;
		}
		if (ok)
			count++;
	}
	return x;
}