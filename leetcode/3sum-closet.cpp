/*
 * Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
 *     For example, given array S = {-1 2 1 -4}, and target = 1.
 *     The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 *
 * accepted 2014-03-29
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int threeSumClosest(vector<int> &num, int target)
{
	sort(num.begin(), num.end());
	int i,j,k,tmp;
	int min = (unsigned(-1)>>1);
	int re = 0;
	int flag = 1;
	tmp = 0;
	for(i = 0; i < num.size(); i++)
	{
		j = i + 1;
		k = num.size() - 1;
		while(j < k)
		{
			tmp = num[i] + num[j] + num[k] - target; 
			if(tmp == 0)
				return target;
			else if(tmp > 0)
				k--;
			else
			{
				flag = -1;
				tmp = -tmp;
				j++;
			}
			if(tmp < min)
			{
				min = tmp;
				re = target + flag*tmp;
				flag = 1;
			}
		}
	}
	return re;
}

int main()
{
	vector<int> a;
	int i,b,n,t;
	cin >> n;
	for(i = 0; i < n; i++)
	{
		cin >> b;
		a.push_back(b);
	}
	cin >> t;
	cout << threeSumClosest(a,t) << endl;
	return 0;
}
