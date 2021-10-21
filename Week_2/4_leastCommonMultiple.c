#include <stdio.h>

unsigned long long int lcm(unsigned long int n, unsigned long int m);
unsigned long int gcd(unsigned long int n, unsigned long int m);

int main()
{
	unsigned long int x, y;
	scanf("%lu", &x);
	scanf("%lu", &y);
	printf("%llu", lcm(x, y));
	return 0;
}

unsigned long long int lcm(unsigned long int n, unsigned long int m)
{
	return ((unsigned long long int)n * m / gcd(n, m));
}

unsigned long int gcd(unsigned long int n, unsigned long int m)
{
	unsigned long int major, minor, remainder;
	minor = n < m ? n : m;
	major = n < m ? m : n;
	if(n % m == 0 || m % n == 0)
		return minor;
	do
	{
		remainder =  major % minor;
		major = minor;
		minor = remainder;
	}while(remainder != 0);
	return major;
}