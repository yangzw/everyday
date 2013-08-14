//编程之美2.3
//求数组中某个超过一半的数字
//
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

int main()
{
	int ID[10] = {1,2,4,2,4,2,2,2,2,9};
	printf("%d\n",find(ID,10));
}
