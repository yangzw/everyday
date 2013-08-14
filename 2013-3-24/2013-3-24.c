/*求斐波那契数列的第n项
 */
#include<stdio.h>

int main()
{
	int n;
	long array[100];
	int count = 0;
	array[0] = 0;
	array[1] = 1;
	count = 1;
	while(scanf("%d",&n) == 1)
	{
		while(n > count)
		{
			array[count+1] = array[count] + array[count-1];
			count++;
		}
		printf("%ld\n",array[n]);
	}
	return 0;
}
