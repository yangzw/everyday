/*Determine whether an integer is a palindrome. Do this without extra space.
 *
 * accepted 2014-03-27
 */
#include<iostream>
using namespace std;

int mpow(int a, int b)
{
	int i;
	int re = 1;
	for(i = 0; i < b; i++)
		re = re * a;
	return re;
}
bool isPalindrome(int x) {
	int len = 0;
	int tmp = x;
	if(x < 0)
		return false;
	while(tmp)
	{
		len++;
		tmp = tmp / 10;
	}
	if(len == 0 || len == 1)
		return true;
	int i;
	tmp = x;
	for(i = 1; i <= len / 2; i++)
	{
		int low = tmp % 10;
		int high = (x / mpow(10, len - i)) % 10;
		//cout << low << " " << high << " " << len << endl;
		if(low != high)
			return false;
		tmp = tmp / 10;
	}
	return true;
}

int main()
{
	int a = 11;
	cout << isPalindrome(a) << endl;
	return 0;
}
