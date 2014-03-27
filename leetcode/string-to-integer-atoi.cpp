/*Implement atoi to convert a string to an integer.
 *
 * Hint: Carefully consider all possible input cases. 
 * If you want a challenge, please do not see below and ask yourself what are the possible input cases.
 *
 * Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). 
 * You are responsible to gather all the input requirements up front.
 *
 * accepted 2014-03-27
 */
#include<iostream>
#include<string>
using namespace std;

int atoi(const char *str) {
	int ret = 0;
	int i = 0;
	int neg = 0;
	int tmp;
	while(str[i] == ' ' || str[i] == '\t')
		i++;
	if(str[i] == '\0')
		return ret;
	if(str[i] == '-' || str[i] == '+')
	{
		if(str[i] == '-')
			neg = 1;
		i++;
	}
	while(str[i] >= '0' && str[i] <= '9')
	{
		tmp = ret * 10 + str[i] - '0';
		//cout << tmp << " " << ret << endl;
		if(tmp >= ret && ret <= 214748364)
		{
			i++;
			ret = tmp;
		}
		else
		{
			if(neg)
				return -2147483648;
			return 2147483647;
		}
	}
	if(neg)
		return 0 - ret;
	return ret;
}

int main()
{
	char a[12] = "10522545459";
	int b = atoi(a);
	cout << b << endl;
	return 0;
}
