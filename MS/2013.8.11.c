//3.2 求电话号码对应的英语单词
#include<stdio.h>
#define TELEPHONE_NUMBER	4
char c[10][10] = 
{
	"",
	"",
	"ABC",
	"DEF",
	"GHI",
	"JKL",
	"MNO",
	"PQRS",
	"TUV",
	"WXYZ",
};
int total[10] = {0,0,3,3,3,3,3,4,3,4};

//index说明对电话号码的第几位进行循环
void RecursiveSearch(int* number,int* answer, int index, int n)
{
	if(index == n)
	{
		int i;
		for(i = 0;i< n;i++)
			printf("%c",c[number[i]][answer[i]]);
		printf("\n");
		return;
	}
	for(answer[index] = 0;answer[index]<total[number[index]];answer[index]++)
		RecursiveSearch(number,answer,index+1,n);
}

int main()
{

	int number[TELEPHONE_NUMBER] = {3,3,2,3};
	int answer[TELEPHONE_NUMBER] = {0,0,0,0}; //初始化为0
	//直接循环法,控制循环的方法很巧妙
	while(1)
	{
		int i;
		for(i=0;i<TELEPHONE_NUMBER;i++) //输出一种可能
			printf("%c",c[number[i]][answer[i]]);
		printf("\n");
		int k = TELEPHONE_NUMBER - 1;
		while(k>= 0)
		{
			if(answer[k] < total[number[k]] - 1) //遍历某一位数字的所有字符
			{
				answer[k]++;
				break;
			}
			else //遍历完毕，归零该字符，转向上一位数字
			{
				answer[k] = 0;k--;
			}
		}
		if(k < 0)
			break;
	}
	printf("==================\n");
	RecursiveSearch(number,answer,0,TELEPHONE_NUMBER);
}
