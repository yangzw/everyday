/*
 * Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
 * Note:
 *     Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ¡Ü b ¡Ü c ¡Ü d)
 *     The solution set must not contain duplicate quadruplets.
 *     For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
 *                 A solution set is:
 *                 (-1,  0, 0, 1)
 *                 (-2, -1, 1, 2)
 *                 (-2,  0, 0, 2)
 *
 *accepted 2014-03-29
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int> > fourSum(vector<int> &num, int target){
	vector<vector<int> > re;
	sort(num.begin(), num.end());
	int i,j,n,k;
	int len = num.size();
	for(i = 0; i < (len - 3); i++)
	{
		if(i > 0 && num[i] == num[i-1])
			continue;
		for(j = i+1; j < (len - 2); j++)
		{
			if(j != i+1 && num[j] == num[j-1])
				continue;
			n = j + 1;
			k = len - 1;
			while(n < k)
			{
				//cout << num[i] << ' ' << num[j] << ' ' << num[k] << endl;
				if(num[j] + num[k] + num[i] + num[n] > target)
					k--;
				else if(num[j] + num[k] + num[i] + num[n] < target)
					n++;
				else
				{
					//cout << i << j << n << k << endl;
					vector<int> b (4);
					b[0] = num[i];
					b[1] = num[j];
					b[2] = num[n];
					b[3] = num[k];
					re.push_back(b);
					k--;
					while(k > n && num[k+1] == num[k])
						k--;
				}
			}
		}
	}
	return re;
}

int main()
{
	vector<int> a;
	int i,b,n;
	cin >> n;
	for(i = 0; i < n; i++)
	{
		cin >> b;
		a.push_back(b);
	}
	int target;
	cin >> target;
	vector<vector<int> > c = fourSum(a, target);
	int j;
	for(i = 0; i < c.size(); i++)
	{
		cout << '(';
		for(j = 0;j < c[i].size(); j++)
			cout << c[i][j] << ',';
		cout << ")\n";
	}
	return 0;
}
