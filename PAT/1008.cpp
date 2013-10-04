#include<iostream>
using namespace std;

void rotate(int* array,int begin,int end)
{
	int tmp;
	while(begin < end)
	{
		tmp = array[end];
		array[end] = array[begin];
		array[begin] = tmp;
		begin++;
		end--;
	}
}

int main()
{
	int n,m;
	cin >> n >> m;
	int array[n];
	int i;
	for(i=0;i<n;i++)
		cin >> array[i];
	m = m % n;
	rotate(array,0,n-m-1);
	rotate(array,n-m,n-1);
	rotate(array,0,n-1);
	for(i=0;i<n-1;i++)
		cout << array[i] << " ";
	cout << array[n-1];
}
