#include <stdio.h>
#include <stdint.h>

int16_t fibonacciMod(int16_t n, int16_t m);
int16_t pisano(int16_t m);
int64_t fibonacciAgain(int64_t n, int64_t m);
int16_t fibonacciSum(int64_t init, int64_t fin);

int main()
{
	int64_t init, fin, res;
	scanf("%lld", &init);
    scanf("%lld", &fin);
    res = fibonacciSum(init, fin);
	printf("%d", res < 0 ? (res + 10) : res);
	return 0;
}


int16_t fibonacciMod(int16_t N, int16_t m)
{
    int16_t arr[N + 1];
    if (N < 2)
        return N;
    arr[0] = 0;
    arr[1] = 1;
    for (int16_t i = 2; i <= N; i++)
        arr[i] = (arr[i - 1] + arr[i - 2]) % m;
    return arr[N];
}

int16_t pisano(int16_t m)
{   
    int16_t n1 = -1, n2 = -1, i = 2;
    if (m == 1)
        return 0;
    while (1)
    {
        n2 = fibonacciMod(i, m);
        if (n2 == 1 && n1 == 0)
            return i - 1;
        n1 = n2;
        i++;
    }
}

int64_t fibonacciAgain(int64_t N, int64_t m)
{
    int16_t len = pisano(m);
    int64_t remainder;
    do
    {
        remainder = N % len;
        N = remainder;
    } while (remainder >= len);
    return fibonacciMod(N, m);
}

int16_t fibonacciSum(int64_t init, int64_t fin)
{
    return ((fibonacciAgain(fin + 2, 10) - 1) - (fibonacciAgain(init + 1, 10) - 1));
}
