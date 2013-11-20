#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	long a,b,c;
	char array[10];
	memset(array,0,sizeof(array));
	cin >> a >> b;
	c = a + b;
	int i,count = 0;
	if(c < 0)
	{
		c = 0 - c;
		array[9] = '-';
	}
	if(c == 0)
		cout << "0";
	int j = 9;
	for(i = 0;c != 0;i++)
	{
		if(count == 3)
		{
			count = 0;
			array[--j] = ',';
		}
		count ++;
		array[--j] =  c % 10 + '0';
		c = c / 10;
	}
	if(array[9] == '-')
		cout << "-";
	for(;j<9;j++)
		cout << array[j];
	return 0;
}
