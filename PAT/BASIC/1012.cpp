#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int a[5] = {0};
	int b,c,flag,count;
	flag = 1;
	int flag1 = 0;
	int flag2 = 0;
	count = 0;
	int N;
	cin >> N;
	while(N--)
	{
		cin >> b;
		c = b % 5;
		if(c == 0)
		{
			if(b % 2 == 0)
			{
				flag1 = 1;
				a[0] += b;
			}
		}
		else if(c == 1)
		{
			flag2 = 1;
			a[1] += flag*b;
			flag = -flag;
		}
		else if(c == 2)
		{
			a[2] ++;
		}
		else if(c == 3)
		{
			count ++;
			a[3] += b;
		}
		else if(c == 4)
		{
			if(b > a[4])
				a[4] = b;
		}
	}
	int i;
	if(flag1)
		cout << a[0] << " ";
	else
		cout << "N ";
	if(flag2)
		cout << a[1] << " ";
	else
		cout << "N ";
	if(a[2])
		cout << a[2] << " ";
	else
		cout << "N ";
	double a3 = (double)a[3];
	if(a[3])
		cout << fixed << setprecision(1) << a3/count << " ";
	else
		cout << "N ";
	if(a[4])
		cout << a[4];
	else
		cout << "N";
}
