//最大公约数问题
#include<iostream>
using namespace std;

int iseven(int x)
{
	return x % 2 == 0;
}

int gcd(int x, int y)
{
	return (!y) ? x : gcd(y,x%y);
}

int gcd2(int x, int y)
{
	if(x < y)
		return gcd2(y,x);
	if(y == 0)
		return x;
	else
		return gcd(x-y,y);
}

int gcd3(int x, int y)
{
	if(x < y)
		return gcd(y,x);
	if(y == 0)
		return x;
	else
	{
		if(iseven(x))
		{
			if(iseven(y))
				return (gcd(x>>1,y>>1)<<1);
			else
				return gcd(x>>1,y);
		}
		else
		{
			if(iseven(y))
				return gcd(x,y>>1);
			else
				return gcd(y,x-y);
		}
	}
}

int main()
{
	cout << gcd(34,17) << endl;
	cout << gcd2(34,17) << endl;
	cout << gcd3(34,17) << endl;
	return 0;
}
