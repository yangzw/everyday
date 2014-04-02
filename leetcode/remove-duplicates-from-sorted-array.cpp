/* Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 * For example,
 * Given input array A = [1,1,2],
 * Your function should return length = 2, and A is now [1,2]. 
 *
 * accepted 2014-03-30
 */
#include<iostream>
using namespace std;

int removeDuplicates(int A[], int n) {
	if(n == 0)
		return 0;
	int i,j;
	i = 0;
	j = 1;
	while(j < n)
	{
		while(A[j] == A[j-1])
		{
			j++;
			if(j >= n)
				break;
		}
		if(j >= n)
			break;
		A[++i] = A[j++];
	}
	return i+1;
}

int main()
{
	int n,i;
	cin >> n;
	int A[n];
	for(i = 0; i < n; i++)
		cin >> A[i];
	int b =  removeDuplicates(A,n);
	for(i = 0; i < b; i++)
		cout << A[i] << " ";
	cout << endl;
	return 0;
}
