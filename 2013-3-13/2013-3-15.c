//使用了双指针的方法
#include<stdio.h>
#include <string.h>  
#define ARRAY_SIZE 100

char* left(char* array, int pos)
{
	int len = strlen(array);
	int p = 0;
	int q = pos;
	char tmp;
	int i;
	while((pos + q) < len)
	{
		for(i = 0;i<pos;i++)
		{
			tmp = array[p];
			array[p] = array[q];
			array[q] = tmp;
			p++;
			q++;
		}
	}
	//printf("%d%d\n",len,q);
	int time = len - q;
	for(i = 0; i < time;i++,q++)
	{
		int j;
		for(j = 0;j < pos;j++)
		{
			tmp = array[q-j-1];
			array[q-j-1] = array[q-j];
			array[q-j] = tmp;
		}
	}
	return array;
}

int main()
{
	char array[ARRAY_SIZE];
	gets(array);
	int pos;
	scanf("%d",&pos);
	puts(left(array,pos));  
	return 0;
}
