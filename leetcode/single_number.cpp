/*Given an array of integers, every element appears twice except for one.
 *Find that single one.
 *Note:
 *Your algorithm should have a linear runtime complexity.
 *Could you implement it without using extra memory?

  accepted@2014-3-22
*/
#include<iostream>
using namespace std;

int singleNumber(int a[], int n)
{
	int i;
	int b = a[0];
	for(i = 1; i < n; i++)
		b  = a[i] ^ b;
	return b;
}

int main()
{
	int a[11] = {1, 2, 3, 1, 3, 5, 7, 9, 7, 5, 9};
	int b = singleNumber(a,11);
	cout << b << endl;
}

