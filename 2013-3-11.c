/*
此做法超时
*/
#include<stdio.h>

int main()
{
	int m,n;
	int array[1000][1000];
	while(scanf("%d%d",&m,&n) == 2)
	{
		int t;
		scanf("%d",&t);
		int i,j;
		for(i = 0; i < m;i++)
		{
			for(j = 0; j <n; j++)
				scanf("%d",&array[i][j]);
		}
		int s_i,s_j;
		s_i = s_j = 0;
		i = m - 1;
		j = n - 1;
		int flag = 1;
		while(s_i < i && s_j < j)
		{
			if(t == array[i][j] || t == array[s_i][s_j])
			{
				printf("Yes\n");
				flag = 0;
				break;
			}
			else if(t > array[i][j] || t < array[s_i][s_j])
			{
				break;
			}	
			else
			{
				if(t <= array[i/2][j])
					i = i /2;
				else
					s_i = i/2 + 1;
				if(t <= array[i][j/2])
					j = j/2;
				else
					s_j = j/2;
			}
		}
		if(flag)
			printf("No\n");
	}
	return;
}
