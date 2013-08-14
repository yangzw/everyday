//递归实现旋转,左右震荡旋转
#include<iostream>
using namespace std;

void rotate(string &str,int n,int m,int head,int tail,bool flag)
{
	if(head == tail || m <= 0)
		return;
	if(flag == true)//右旋转
	{
		int p1 = head;
		int p2 = head + m;
		int k = (n - m) - n % m;
		for(int i = 0;i <k;i++,p1++,p2++)
			swap(str[p1],str[p2]);
		rotate(str,n-k,n%m,p1,tail,false);
	}
	else//左旋转
	{
		int p1 = tail;
		int p2 = tail - m;
		int k = (n - m) - n %m;
		for(int i = 0;i <k;i++,p1--,p2--)
			swap(str[p1],str[p2]);
		rotate(str,n-k,n%m,head,p1,true);
	}
}

int main()
{
	int i;
	string str;
	cin >> str >> i;
	int len = str.length();
	rotate(str,len,i % len,0,len-1,true);
	cout << str.c_str() << endl;
	return 0;
}
