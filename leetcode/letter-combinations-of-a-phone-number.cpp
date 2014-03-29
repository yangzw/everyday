/*Given a digit string, return all possible letter combinations that the number could represent.
 *
 * A mapping of digit to letters (just like on the telephone buttons) is given below.
	Input:Digit string "23"
	Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
   Note:
    Although the above answer is in lexicographical order, your answer could be in any order you want. *

    accepted 2014-03-29
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;

void dfs(vector<string> &re,string rei, int d, string digits, char** numbers)
{
	if(d >= digits.size())
	{
		re.push_back(rei);
		return;
	}
	int j;
	int k = digits[d] - '0';
	for(j = 0; numbers[k][j] != '\0'; j++)
	{
		//cout << "'" << numbers[k][j] << endl;
		rei[d] = numbers[k][j];
		dfs(re,rei,d+1,digits,numbers);
	}
}

vector<string> letterCombinations(string digits){
	char *numbers[10];
	numbers[0] = " ";
	numbers[1] = " ";
	numbers[2] = "abc";
	numbers[3] = "def";
	numbers[4] = "ghi";
	numbers[5] = "jkl";
	numbers[6] = "mno";
	numbers[7] = "pqrs";
	numbers[8] = "tuv";
	numbers[9] = "wxyz";
	vector<string> re;
	if(digits.size() == 0)
	{
		string b = "";
		re.push_back(b);
		return re;
	}
	int i, j;
	i = digits[0] - '0';
	string rei = string(digits.size(), ' ');
	for(j = 0; numbers[i][j] != '\0'; j++)
	{
		rei[0] = numbers[i][j];
		//cout << numbers[i][j] << endl;
		dfs(re,rei,1,digits,numbers);
	}
	return re;
}

int main()
{
	string a;
	cin >> a;
	vector<string> b = letterCombinations(a);
	int i;
	for(i = 0; i < b.size(); i++)
	{
		cout << b[i] << endl;
	}
	return 0;
}
