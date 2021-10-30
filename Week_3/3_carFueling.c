#include <stdio.h>
#include <stdint.h>

#define MAX_STATION 300

int numRefill(int32_t distance, int32_t milesTank, int32_t *station, int32_t nStations);

int main()
{
	int32_t distance, milesTank, nStations, station[MAX_STATION];
	scanf("%ld", &distance);
	scanf("%ld", &milesTank);
	scanf("%ld", &nStations);
	for(int16_t i = 0; i < nStations; i++)
		scanf("%ld", &station[i]);
	printf("%d", numRefill(distance, milesTank, station, nStations));
	return 0;
}

int numRefill(int32_t distance, int32_t milesTank, int32_t *station, int32_t nStations)
{
	int cnt = 0;
	int32_t i = 0, position = 0, stop = 0;
	station[nStations] = distance;
	while (i <= nStations)
    	{
        	if (position + milesTank >= distance)
            		return cnt;
        	if (position + milesTank < station[i])
        	{
			stop = i - 1;
            		if (position == station[stop])
            			return -1;
           		position = station[i - 1];
			cnt++;
            		i--;
        	}
        i++;
    	}
	return -1;
}
