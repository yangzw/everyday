/*Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 *
 * The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 *
 * accepted 2014-03-29
 */
#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool isValid(string s){
	int i;
	stack<char> cstack;
	char tmp;
	for(i = 0; i < s.size(); i++)
	{
		if(s[i] == '(' || s[i] == '{' || s[i] == '[')
			cstack.push(s[i]);
		else if(s[i] == ')' || s[i] == '}' || s[i] == ']')
		{
			if(cstack.empty())
				return false;
			if(s[i] == '}')
				tmp = '{';
			else if(s[i] == ')')
				tmp = '(';
			else if(s[i] == ']')
				tmp = '[';
			if(cstack.top() != tmp)
				return false;
			cstack.pop();
		}
	}
	if(cstack.empty())
		return true;
	return false;
}

int main()
{
	string a;
	cin >> a;
	cout << isValid(a) << endl;
	return 0;
}
