//求一个8字节的无符号整型变量,求其二进制表示中'1'的个数
//
#include <stdio.h>

function1(int v)
{
	int num = 0;
	while(v)
	{
		if (v % 2 == 1)
			num ++;
		v = v / 2;
	}
	return num;
}

function2(int v)
{
	int num = 0;
	while(v)
	{
		num += v & 0x01;
		v >>= 1;
	}
	return num;
}

function3(int v)
{
	int num = 0;
	while(v)
	{
		v &= (v-1); //每次都能消去二进制表示中最后一位1,因此只需要循环1的个数次
		num ++;
	}
	return num;
}

//以空间换时间,直接将0-255中1的个数存在数组中,具体过程就不写了
function4(int v)
{
	int countTable[256] =  {};
	return countTable[v];
}

int main()
{
	printf("Please input the byte:");
	int v;
	scanf("%d",&v);
	printf("%d\n",function1(v));
	printf("%d\n",function2(v));
	printf("%d\n",function3(v));
}

