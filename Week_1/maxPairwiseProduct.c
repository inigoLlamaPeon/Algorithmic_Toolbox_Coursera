#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 200000

unsigned long int maxPairwiseProduct(const unsigned long int * arr, unsigned long int N);

int main()
{
	unsigned long int N, arr[MAX_SIZE];
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%lu", &arr[i]);
	printf("%lu", maxPairwiseProduct(arr, N));
	return 0;
}

unsigned long int maxPairwiseProduct(const unsigned long int * arr, unsigned long int N)
{
	unsigned long int  nums[2], aux, i = 2;
	nums[0] = arr[0];
	nums[1] = arr[1];
	while(i < N)
	{
		aux = nums[0] < nums[1] ? 0 : 1;
		while(i < N)
		{
			if(arr[i] > nums[aux])
			{
				nums[aux] = arr[i];
				break;
			}
			i++;
		}
		i++;
	}
	return (nums[0] * nums[1]);
}
