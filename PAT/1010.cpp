#include<iostream>

using namespace std;

int main()
{
	int a,b;
	int flag = 0;
	while(cin>>a>>b)
	{
		if(a*b)
		{
			if(flag)
				cout << " ";
			else
				flag = 1;
			cout << a*b << " " <<  b-1;
		}
	}
	if(!flag)
		cout << "0 0";
	return 0;
}
