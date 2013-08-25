//求周期串
#include<stdio.h>
#include<string.h>

int main()
{
	char word[100];
	int i,j,ok;
	scanf("%s",word);
	int len = strlen(word);
	for(i = 1;i <= len;i++)
		if(len % i == 0)
		{
			ok = 1;
			for(j = i;j < len;j++)
				if(word[j] != word[j%i])
				{
					ok = 0;
					break;
				}
			if(ok)
			{
				printf("%d\n",i);
				break;
			}
		}
}
