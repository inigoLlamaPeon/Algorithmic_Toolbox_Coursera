#include <stdio.h>
#include <stdint.h>

int32_t prizes(int32_t *dst, int32_t n);

int main()
{
	int32_t arr[100000], n, result;
	scanf("%ld", &n);
	result = prizes(arr, n);
	printf("%ld\n", result);
	for (int j = 0; j < result; j++)
		printf("%ld ", arr[j]);
}

int32_t prizes(int32_t *dst, int32_t n)
{
	int32_t p = 0;
	for (int32_t i = 1; i <= n; i++)
	{
		n -= i;
		if (n <= i)
			dst[p] = n + i;
		else if (n == 0)
		{
			dst[p] = i;
			break;
		}
		else
		{
			dst[p] = i;
			p++;
		}
	}
	return p + 1;
}