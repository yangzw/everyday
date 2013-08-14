//编程之美2.4
//1.写一个函数，返回1到N之间出现的'1'的个数
//2.满足f(N) = N的最大的N是多少?

#include<stdio.h>

int function1(int n)
{
	int icount = 0;
	int ifactor = 1;
	int ilowernum = 0;
	int icurrnum = 0;
	int ihighernum = 0;

	while(n / ifactor != 0)
	{
		ilowernum = n - (n / ifactor) * ifactor;  //低位数字
		icurrnum = (n / ifactor) % 10; //本身
		ihighernum = n / (ifactor * 10);//高位数字

		switch(icurrnum)
		{
			case 0:
				icount += ihighernum * ifactor;
				break;
			case 1:
				icount += ihighernum * ifactor + ilowernum + 1;
				break;
			default:
				icount += (ihighernum + 1) * ifactor;
				break;
		}
		ifactor *= 10;
	}
	
	return icount;
}

int main()
{
	printf("Please input:");
	int n;
	scanf("%d",&n);
	printf("result:%d\n",function1(n));
	return 0;
}
