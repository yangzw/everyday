/*
 * Implement regular expression matching with support for '.' and '*'.
 *
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 *
 * The matching should cover the entire input string (not partial).
 *
 * The function prototype should be:
 * bool isMatch(const char *s, const char *p)
 *
 * Some examples:
 * isMatch("aa","a") → false
 * isMatch("aa","aa") → true
 * isMatch("aaa","aa") → false
 * isMatch("aa", "a*") → true
 * isMatch("aa", ".*") → true
 * isMatch("ab", ".*") → true
 * isMatch("aab", "c*a*b") → true
 *
 * accepted 2014-03-27
 */
#include<iostream>
using namespace std;

bool isMatch(const char *s, const char *p)
{
//	cout << s << ": :" << p << endl;
	if(*p == 0)
		return *s == 0;
	if(*(p+1) != '*')
	{
		if(*p == *s || (*p == '.' && *s != 0))
			return isMatch(s+1,p+1);
		return false;
	}
	else
	{
		while((*(p+2) != 0) && (*(p+2) == *p) && (*(p+3) == '*'))
			p = p + 2;
		while(*p == *s || (*p == '.' && *s != 0))
		{
			if(isMatch(s,p+2))
				return true;
			s++;
		}
		return isMatch(s,p+2);
	}
}

int main()
{
	char a[50];
	char b[50];
	cin >> a >> b;
	cout << isMatch(a,b) << endl;
	return 0;
}
