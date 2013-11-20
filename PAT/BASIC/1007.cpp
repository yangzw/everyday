#include<iostream>
#include<cmath>
using namespace std;

bool isPrim(int n)
{
	if(n % 2 == 0)
		return false;
	int i;
	int tmp = (int)sqrt(n);
	for(i=3;i <= tmp;i+=2)
		if(n % i == 0)
			return false;
	return true;
}

int main()
{
	int N;
	cin >> N;
	int tmp = 3;
	int flag = 1;
	int count = 0;
	bool a = false;
	while(tmp <= N - 2)
	{
		a = isPrim(tmp+2);
		if(flag)
		{
			if(a)
				count ++;
			else
				flag = 0;
		}
		else if(a)
			flag = 1;
		tmp = tmp + 2;
	}
	cout << count;
}
