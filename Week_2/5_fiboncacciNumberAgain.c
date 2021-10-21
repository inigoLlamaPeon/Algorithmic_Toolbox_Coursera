#include <stdio.h>
#include <stdint.h>

uint64_t fibonacciAgain(uint64_t N, uint16_t m);
uint32_t fibonacciMod(uint32_t N, uint16_t m);
uint16_t pisano(uint16_t m);

int main()
{
	uint64_t N;
	int m;
	scanf("%llu", &N);
	scanf("%d", &m);
	printf("%llu", fibonacciAgain(N, (uint16_t)m));
	return 0;
}

uint64_t fibonacciAgain(uint64_t N, uint16_t m)
{
	uint16_t L = pisano(m);
	uint64_t remainder;
	do
	{
		remainder = N % L;
		N = remainder;
	} while (remainder >= L);
	return ((uint64_t)fibonacciMod(N, m));
}

uint32_t fibonacciMod(uint32_t N, uint16_t m)
{
	uint32_t arr[N + 1];
	if (N < 2)
		return N;
	arr[0] = 0;
	arr[1] = 1;
	for(int i = 2; i <= N; i++)
		arr[i] = (arr[i - 1] + arr[i - 2]) % m;
	return arr[N];
}

uint16_t pisano(uint16_t m)
{
	int n1 = -1, n2 = -1, i = 2;
    	if (m == 1)
        	return 0;
    	while (1)
    	{
        	n2 = fibonacciMod((uint32_t)i, m);
        	if (n2 == 1 && n1 == 0)
            		return i - 1;
        	n1 = n2;
        	i++;
    	}
}
