/*
 * Given a roman numeral, convert it to an integer.
 *
 * Input is guaranteed to be within the range from 1 to 3999.
 *
 * accepted 2014-03-28
 */
#include<iostream>
using namespace std;

int romanToInt(string s){
	int re = 0;
	int i = 0;
	int size = s.size();
	for(;i < size; i++)
	{
		if(s[i] == 'M')
			re += 1000;
		else if(s[i] == 'D')
			re += 500;
		else if(s[i] == 'C')
		{
			if(i+1 < size && s[i+1] == 'M')
			{
				i++;
				re += 900;
			}
			else if(i+1 < size && s[i+1] == 'D')
			{
				i++;
				re += 400;
			}
			else
				re += 100;
		}
		else if(s[i] == 'L')
			re += 50;
		else if(s[i] == 'X')
		{
			if(i+1 < size && s[i+1] == 'C')
			{
				i++;
				re += 90;
			}
			else if(i+1 < size && s[i+1] == 'L')
			{
				i++;
				re += 40;
			}
			else
				re += 10;
		}
		else if(s[i] == 'V')
			re += 5;
		else if(s[i] == 'I')
		{
			if(i+1 < size && s[i+1] == 'X')
			{
				i++;
				re += 9;
			}
			else if(i+1 < size && s[i+1] == 'V')
			{
				i++;
				re += 4;
			}
			else
				re += 1;
		}
	}
	return re;
}

int main()
{
	string a;
	cin >> a;
	cout << romanToInt(a) << endl;
	return 0;
}
