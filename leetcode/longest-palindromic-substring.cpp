/*
 * Given a string S, find the longest palindromic substring in S.
 * You may assume that the maximum length of S is 1000,
 * and there exists one unique longest palindromic substring.
 *
 * accepted 2014-3-26
 */
#include<iostream>
#include<string>
using namespace std;

string longestPalindrome(string s) {
	int i, j;
	int maxlen, maxmid;
	string s1 = "";
	maxlen = maxmid = 0;
	int len = s.size();
	char a[len*2];
	a[0] = s[0];
	for(i = 1,j = 1; i < len; i++)
	{
		a[j++] = '*';
		a[j++] = s[i];
	}
	a[2*len - 1] = '\0';
	//cout << a << endl;
	for(i = 0; i < len*2 - 1; i++)
	{
		for(j = 1; (i-j >= 0) && (i+j <= len*2 - 1); j++)
			if(a[i-j] != a[i+j])
				break;
		if((j-1 > maxlen) ||(j-1 == maxlen && a[i] == '*') )
		{
			maxlen = j-1;
			maxmid = i;
		}
	}
	cout << "maxlen" << maxlen << " " << maxmid << endl;
	for(i = maxmid - maxlen; i <= maxmid + maxlen; i++)
	{
		if(a[i] == '*')
			continue;
		s1 += a[i];
	}
	return s1;
}

int main()
{
	string a = "abb";
	string b = longestPalindrome(a);
	cout << b << endl;
	return 0;
}
