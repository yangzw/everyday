#include<iostream>

using namespace std;

int main()
{
	int n;
	int tmp[3] = {-1,-1,-1};
	cin >> n;
	int i = -1;
	while(n)
	{
		tmp[++i] = n % 10;
		n = n / 10;
	}
	int j;
	if(tmp[2] > 0)
		for(j = 0;j < tmp[2];j++)
			cout << "B";
	if(tmp[1] >= 0)
		for(j = 0;j < tmp[1];j++)
			cout << "S";
	if(tmp[0] >= 0)
		for(j = 1;j <= tmp[0];j++)
			cout << j;
	return 0;
}
