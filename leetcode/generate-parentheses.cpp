/*
  Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 For example, given n = 3, a solution set is:
 "((()))", "(()())", "(())()", "()(())", "()()()"
 *
 * accepted 2014-03-29
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;

void rec(string a, int d, int flag, vector<string> &re, int n)
{
	if(d >= 2*n)
	{
		if(flag == 0)
			re.push_back(a);
		return;
	}
	if(flag > 0 && flag < n)
	{
		a[d] = '(';
		rec(a,d+1,flag+1,re,n);
		a[d] = ')';
		rec(a,d+1,flag-1,re,n);
	}
	else if(flag == 0)
	{
		a[d] = '(';
		rec(a,d+1,flag+1,re,n);
	}
	else if(flag == n)
	{
		a[d] = ')';
		rec(a,d+1,flag-1,re,n);
	}
	else
		return;
}

vector<string> generateParenthesis(int n){
	vector<string> re;
	if(n == 0)
	{
		string b = "";
		re.push_back(b);
		return re;
	}
	string a = string(2*n, '(');
	rec(a,1,1,re,n);
	return re;
}

int main()
{
	vector<string> a = generateParenthesis(4);
	for(int i = 0; i < a.size(); i++)
		cout << a[i] << endl;
	return 0;
}
