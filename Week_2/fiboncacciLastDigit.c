#include <stdio.h>
#include <stdlib.h>

unsigned long int fibonacciLastDigit(int N);

int main()
{
	int N;
	scanf("%d", &N);
	printf("%lu", fibonacciLastDigit(N));
	return 0;
}

unsigned long int fibonacciLastDigit(int N)
{
	unsigned long int arr[N + 1];
	if (N < 2)
		return N;
	arr[0] = 0;
	arr[1] = 1;
	for(int i = 2; i <= N; i++)
		arr[i] = (arr[i - 1] + arr[i - 2])%10;
	return arr[N];
}