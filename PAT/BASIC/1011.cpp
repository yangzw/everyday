#include<iostream>

using namespace std;

int main()
{
	long a,b,c;
	int n;
	cin >> n;
	int i;
	for(i=0;i<n;i++)
	{
		cin >> a >> b >> c;
		long tmp = 0;
		bool flag = false;
		if(b < 0)
		{
			if(a >= 0)
			{
				tmp = a + b;
				flag = tmp > c;
			}
			else if(a < 0)
			{
				if(c < 0)
				{
					tmp = c - b;
					flag = a > tmp;
				}
			}
		}
		if(b >= 0)
		{
			if(a <= 0)
			{
				tmp = a + b;
				flag = tmp > c;
			}
			else if(a > 0)
			{
				if(c > 0)
				{
					tmp = c - b;
					flag = a > tmp;
				}
				else
					flag = true;
			}
		}
		cout << "Case #" << i+1 << ":";
		if(flag)
			cout << " true" << endl;
		else
			cout << " false" << endl;
	}
}
