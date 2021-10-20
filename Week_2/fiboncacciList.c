#include <stdio.h>
#include <stdlib.h>

unsigned long int fibonacci(int N);

int main()
{
	int N;
	printf("Insert a number: ");
	scanf("%d", &N);
	printf("Result: %lu", fibonacci(N));
	printf("%lu", fibonacci(N));
	return 0;
}

unsigned long int fibonacci(int N)
{
	unsigned long int arr[N + 1];
	if (N < 2)
		return N;
	arr[0] = 0;
	arr[1] = 1;
	printf("arr[0] = %d\n", arr[0]);
	printf("arr[1] = %d\n", arr[1]);
	for(int i = 2; i <= N; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
		printf("arr[%d] = %d\n", i, arr[i]);
	}
	return arr[N];
}