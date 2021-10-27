#include <stdio.h>

const int coin[3] = {10, 5, 1};

int getChange(int money);

int main()
{
	int money;
	scanf("%d", &money);
	printf("%d", getChange(money));
	return 0;
}

int getChange(int money)
{
	int totalCoins = 0, i = 0, aux;
	while(money != 0)
	{
		aux = money - coin[i];
		if (aux >= 0)
		{
			money = aux;
			totalCoins++;
		}
		else
			i++;
	}
	return totalCoins;
}