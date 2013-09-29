//2.14 求数组的子数组之和的最大值
#include<stdio.h>

int MaxSum(int* array, int array_size)
{
	int nStart = array[array_size - 1];
	int nAll = array[array_size - 1];
	int i;
	for(i = array_size - 2;i >= 0;i--)
	{
		if(nStart < 0)
			nStart = 0;
		nStart += array[i];
		if(nStart > nAll)
			nAll = nStart;
	}
	return nAll;
}

int main()
{
	int array[7] = {-8,-1,-2,-5,-9,-3,-4};
	printf("%d\n",MaxSum(array,7));
	return 0;
}
