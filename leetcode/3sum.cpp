/*Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
 * Find all unique triplets in the array which gives the sum of zero.
 *
 * Note:
 *     Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ¡Ü b ¡Ü c)
 *         The solution set must not contain duplicate triplets.
 *             For example, given array S = {-1 0 1 2 -1 -4},
 *             A solution set is:
 *                     (-1, 0, 1)
 *                     (-1, -1, 2)
 *accepted 2014-03-29
 */
#include<iostream>
#include<vector>
using namespace std;

#include<algorithm>
vector<vector<int> > threeSum(vector<int> &num)
{
	vector<vector<int> > re;
	sort(num.begin(), num.end());
	int i,j,k;
	//for(i = 0; i < num.size(); i++)
	//	cout << num[i] << " ";
	//cout << endl;
	for(i = 0; i < num.size(); i++)
	{
		if(i > 0 && num[i] == num[i-1])
			continue;
		j = i + 1;
		k = num.size() - 1;
		while(j < k)
		{
			//cout << num[i] << ' ' << num[j] << ' ' << num[k] << endl;
			if(num[j] + num[k] + num[i] > 0)
				k--;
			else if(num[j] + num[k] + num[i] < 0)
				j++;
			else
			{
				vector<int> b (3);
				b[0] = num[i];
				b[1] = num[j];
				b[2] = num[k];
				re.push_back(b);
				k--;
				while(k > j && num[k+1] == num[k])
					k--;
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
	vector<vector<int> > c = threeSum(a);
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
