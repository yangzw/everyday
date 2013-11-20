#include<iostream>
using namespace std;

int main()
{
	int times;
	cin >> times;
	char a;
	a = cin.get(); //去换行符号
	int flag;
	int count0,count,count1;
	while(times)
	{
		times--;
		flag = 0;
		count0 = 0;
		count = 0;
		count1 = 0;
		while((a = cin.get()) != '\n')
		{
			if(flag == 0)
			{
				if(a == 'P')
					flag = 1;
				else if(a != 'A')
					flag = -1;
				else
					count0 ++;
			}
			else if(flag == 1)
			{
				if(a == 'A')
					count ++;
				else if(a == 'T')
				{
					if(count >= 1)
						flag = 2;
					else
						flag = -1;
				}
				else
						flag = -1;
			}
			else if(flag == 2)
			{
				if(a != 'A')
				{
					flag = -1;
				}
				else
					count1++;
			}
		}
		if((flag == 2) && (count1 == count0 * count))
			cout << "YES";
		else
			cout << "NO";
		if(times)
			cout << endl;
	}
}
