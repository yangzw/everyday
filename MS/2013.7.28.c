//求N!末尾0的个数
//求N!的二进制表示中最低位1的位置
//
#include<stdio.h>

//只需要转化成求质因数分解以后5的个数就行
int function1(int n)
{
	int ret = 0;
	int i,j;
	for(i = 1;i <= n;i++)
	{
		j = i;
		while(j % 5 == 0)
		{
			ret ++;
			j = j / 5;
		}
	}
	return ret;
}

int function2(int n)
{
	int ret = 0;
	while(n)
	{
		ret += n / 5;
		n /= 5;
	}
	return ret;
}

//等价与于求N!中含有质因数2的个数
int function2_1(int n)
{
	int ret = 0;
	while(n)
	{
		n >>= 1;
		ret += n;
	}
	return ret;
}

int main()
{
	printf("Please input:");
	int a;
	scanf("%d",&a);
	printf("question1:\n");
	printf("%d\n",function1(a));
	printf("%d\n",function2(a));
	printf("question2:\n");
	printf("%d\n",function2_1(a));
}
