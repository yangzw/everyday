/* 在一个二维数组中，每一行从左到右按照递归的顺序排列，每一列从上到下递增的顺序排列,请判断一个整数是否在该数组中
不超时的做法*/
#include <iostream>
#include <cstdio>
using namespace std;

string search(int a[][1000], int m, int n, int key)
{
	int i = 0;
	int j = n - 1;
	while(i < m && j >= 0)
	{
		if (a[i][j] == key)
			return "Yes";
		else if (a[i][j] < key)
			i++;
		else
			j--;
	}

	return "No";
}

int main()
{
	int n, m;
	int a[1000][1000];
	while(scanf("%d%d", &m, &n) != EOF)
	{
		int key;
		scanf("%d", &key);
		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; j++)
				scanf("%d", &a[i][j]);
		cout << search(a, m, n, key) << endl;
	}
}
