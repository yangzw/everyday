//编程之美2.3
//求数组中某个超过一半的数字
//求数组中都出现超过1/4的三个数
#include<stdio.h>

int find(int* ID,int n)
{
	int candiate;
	int ntimes,i;
	for(i = ntimes = 0;i<n;i++)
	{
		if(ntimes == 0)
		{
			candiate = ID[i];
			ntimes = 1;
		}
		else
		{
			if(candiate == ID[i])
				ntimes ++;
			else
				ntimes --;
		}
	}
	return candiate;
}

void find2(int* ID, int n,int* candiate)
{
	int ntimes[3],i,j,flag;
	for(i = 0;i < 3;i++)
	{
		ntimes[i] = 0;
	}
	for(i = 0;i < n;i++)
	{
		flag = 0;
		for(j = 0;j < 3;j++)
		{
			if(ntimes[j] == 0)
				continue;
			if(candiate[j] == ID[i])
			{
				ntimes[j]++;
				flag = 1;
			}
		}
		if(flag)
			continue;
		for(j = 0;j < 3;j++)
		{
			if(ntimes[j] == 0)
			{
				candiate[j] = ID[i];
				ntimes[j]++;
				flag = 1;
				break;
			}
		}
		if(flag)
			continue;
		for(j=0;j < 3;j++)
			ntimes[j]--;
	}
}

int main()
{
	int ID[10] = {1,2,4,2,4,2,2,2,2,9};
	printf("%d\n",find(ID,10));
	int ID2[13] = {1,1,2,2,3,3,2,2,1,1,3,3,4};
	int candiate[3] = {0,0,0};
	find2(ID2,13,candiate);
	int i;
	for(i=0;i < 3;i++)
		printf("%d\n",candiate[i]);
}
