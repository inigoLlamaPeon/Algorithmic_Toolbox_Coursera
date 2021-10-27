#include <stdio.h>
#include <stdint.h>

struct item
{
	int32_t value, weight;
	double ratio;
};

double maxValueLoot(const struct item *src, int16_t nItems, int32_t capacity);
void *sortStructbyRatio(struct item *src, int16_t nItems);

int main()
{
	uint16_t nItems;
	uint32_t capacity;
	struct item object[1000];

	scanf("%d", &nItems);
	scanf("%lld", &capacity);
	for(int i = 0; i < nItems; i++)
	{
		scanf("%lld", &object[i].value);
		scanf("%lld", &object[i].weight);
	}
	for(int16_t j = 0; j < nItems; j++)
		object[j].ratio = (double)object[j].value / (double)object[j].weight;
	sortStructbyRatio(object, nItems);
	printf("%.5f", maxValueLoot(object, nItems, capacity));
	return 0;
}

double maxValueLoot(const struct item *src, int16_t nItems, int32_t capacity)
{
	double total = 0;
	int16_t i = 0;
	for(int16_t i = 0; i < nItems; i++)
	{
		if(capacity >= src[i].weight)
		{
			total += src[i].value;
			capacity -= src[i].weight;
		}
		else if(capacity < src[i].weight)
			return total + ((double) src[i].ratio * (double)capacity);
	}
	return total;
}

void *sortStructbyRatio(struct item *src, int16_t nItems)
{
	struct item aux;
	for(int i = 0; i < nItems; i++)
	{
		for(int16_t j = 0; j < nItems; j++)
		{
			if (src[i].ratio > src[j].ratio) 
            {
                aux.ratio = src[i].ratio;
                aux.value = src[i].value;
                aux.weight = src[i].weight;
                src[i].ratio = src[j].ratio;
                src[i].value = src[j].value;
                src[i].weight =src[j].weight;
                src[j].ratio = aux.ratio;
                src[j].value = aux.value;
                src[j].weight = aux.weight;
            }
		}
	}
}