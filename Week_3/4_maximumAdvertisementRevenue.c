#include <stdio.h>
#include <stdint.h>

int64_t maxAddRevenue(int64_t *src1, int64_t *src2, int n);
void *sortArray(int64_t *src, int n);

int main()
{
	int n;
	int64_t a[1000], b[1000];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	for (int j = 0; j < n; j++)
		scanf("%lld", &b[j]);
	printf("%lld", maxAddRevenue(a, b, n));
	return 0;
}

int64_t maxAddRevenue(int64_t *src1, int64_t *src2, int n)
{
	int64_t result = 0;
	sortArray(src1, n);
	sortArray(src2, n);
	for(int i = 0; i < n; i++)
		result += src1[i] * src2[i];
	return result;
}
void *sortArray(int64_t *src, int n)
{
	int64_t aux;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if (src[i] > src[j]) 
            		{
               			aux = src[i];
                		src[i] = src[j];
                		src[j] = aux;
            		}
		}
	}
}
