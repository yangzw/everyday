/*Reverse digits of an integer.
 *
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321
 *
 * accepted 2014-03-27
 */
#include<iostream>
using namespace std;

int reverse(int x) {
	int neg = 0;
	int ret;
	if(x < 0)
	{
		neg = 1;
		ret = -x;
		if(x != -ret)
			return 0;
		x = ret;
	}
	ret = 0;
	do
	{
		if(ret <= x%10 + ret*10)
		{
			ret = x % 10 + ret*10;
			x = x / 10;
		}
		else
			return 0;

	}while(x);
	if(neg)
		return 0-ret;
	return ret;
}

int main()
{
	int b = reverse(-1003);
	cout <<  b << endl;
	return 0;
}
