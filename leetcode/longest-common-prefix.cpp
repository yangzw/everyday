/*Write a function to find the longest common prefix string amongst an array of strings. 
 *
 * accepted 2014-03-28
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;

string longestCommonPrefix(vector<string> &strs) {
	int i;
	int j = -1;
	int flag = 0;
	if(strs.size() == 0)
		return "";
	do{
		j++;
		for(i = 1; i < strs.size(); i++)
		{
			if(strs[0][j] != strs[i][j])
			{
				flag = 1;
				break;
			}
		}
	}while(flag == 0 && j < strs[0].size());
	string re = string(strs[0],0,j);
	return re;
}

int main()
{
	vector<string> a;
	int i = 0;
	string b;
	for(i = 0; i < 4; i++)
	{
		cin >> b;
		a.push_back(b);
	}
	cout << longestCommonPrefix(a) << endl;
	return 0;
}
