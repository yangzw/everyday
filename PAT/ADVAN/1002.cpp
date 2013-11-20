#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

int main()
{
	int na,nb;
	int k;
	double nk;
	double result[1001];
	int index[20];
	memset(result,0.0,sizeof(result));
	memset(index,-1,sizeof(index));
	cin >> na;
	int max = -1;
	while(na--)
	{
		cin >> k >> nk;
		if(k > max)
			max = k;
		result[k] += nk;
	}
	cin >> nb;
	while(nb--)
	{
		cin >> k >> nk;
		if(k > max)
			max = k;
		result[k] += nk;
	}
	int count = -1;
	for(;max>=0;max--)
	{
		if(((result[max] - 0.0) > 1e-3) ||((0.0 - result[max]) > 1e-3) )
		{
			index[++count] = max;
		}
	}
	if(count >= 0)
	{
		cout << count+1 << " ";
		for(max=0;max < count;max++)
			cout << index[max] << " " << fixed << setprecision(1)<< result[index[max]] << " ";
		cout << index[count] << " " << fixed << setprecision(1)<< result[index[count]];
	}
	else
		cout << "0";
	return 0;
}
