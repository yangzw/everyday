/*Given an integer, convert it to a roman numeral.
 *
 * Input is guaranteed to be within the range from 1 to 3999.
 *
 * 用map代码更简洁
 *
 * accepted 2014-03-28
 */
#include<iostream>
#include<string>
using namespace std;

string intToRoman(int num) {
	string re = "";
	int i;
	if(num >= 1000)
	{
		i = num / 1000;
		while(i-->0)
			re += 'M';
		num = num % 1000;
	}
	if(num >= 100)
	{
		i = num / 100;
		if(i == 9)
			re += "CM";
		else
		{
			if(i >= 5)
			{
				re += 'D';
				i = i - 5;
			}
			if(i == 4)
				re += "CD";
			else
				while(i-->0)
					re += 'C';
		}
		num = num % 100;
	}
	if(num >= 10)
	{
		i = num / 10;
		if(i == 9)
			re += "XC";
		else
		{
			if(i >= 5)
			{
				re += 'L';
				i = i - 5;
			}
			if(i == 4)
				re += "XL";
			else
				while(i-->0)
					re += 'X';
		}
		num = num % 10;
	}
	if(num >= 1)
	{
		i = num;
		if(i == 9)
			re += "IX";
		else
		{
			if(i >= 5)
			{
				re += 'V';
				i = i - 5;
			}
			if(i == 4)
				re += "IV";
			else
				while(i-->0)
					re += 'I';
		}
	}
	return re;
}

int main()
{
	int a;
	cin >> a;
	cout << intToRoman(a) << endl;
	return 0;
}
