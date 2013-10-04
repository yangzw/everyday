#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

bool compare(int a, int b)
{
	return a > b;
}

int main()
{
	int array[101];
	vector<int> vec;
	int k,tmp;
	bool flag = false;
	cin >> k;
	memset(array,0,sizeof(array));
	while(k--)
	{
		cin >> tmp;
		vec.push_back(tmp);
		while(tmp > 1)
		{
			if(tmp % 2 == 1)
				tmp = 3*tmp + 1;
			tmp /= 2;
			if(tmp <= 100)
				array[tmp] = 1;
		}
	}
	sort(vec.begin(),vec.end(),compare);

	for(vector<int>::iterator it=vec.begin();it!=vec.end();it++)
	{
		if(array[*it] == 0)
		{
			if(flag)
				cout << " ";
			else
				flag = true;
			cout << *it;
		}
	}
	cout << endl;
	return 0;
}
