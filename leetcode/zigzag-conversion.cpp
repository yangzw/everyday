/*
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * And then read line by line: "PAHNAPLSIIGYIR"
 * Write the code that will take a string and make this conversion given a number of rows:
 *
 * string convert(string text, int nRows);
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 *
 * accepted 2014-03-27
 */
#include<iostream>
#include<string>
using namespace std;

string convert(string s, int nRows) {
	int len = s.size();
	string re = string(len,' ');
	int i,j,m;
	int gap = 2*(nRows - 1);
	int mingap = 0;
	m = 0;
	if(gap == 0)
	{
		re = s;
		return re;
	}
	for(j = 0; j < len; j+=gap)
		re[m++] = s[j];
	for(i = 1; i < nRows - 1; i++)
	{
		mingap = gap - i*2;
		for(j = i;j < len; j+=gap)
		{
			re[m++] = s[j];
			if(j + mingap < len)
				re[m++] = s[j+mingap];
		}
	}
	for(j = nRows-1; j < len; j+=gap)
		re[m++] = s[j];
	return re;
}

int main()
{
	string a = "AB";
	string b = convert(a,2);
	cout << b << endl;
	return 0;
}
