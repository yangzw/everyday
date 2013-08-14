#include<iostream>
using namespace std;

void swap(int &a, int &b)
{
	int tmp;
	tmp = a;
	a  = b;
	b = tmp;
}

void print_array(int* array, int size)
{
	for(int i = 0;i < size;i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

//冒泡排序
void bublesort(int* array, int size)
{
	int i,j;
	for(i = 0; i < size; i++)
	{
		for(j = size - 1; j > i ; j--)
		{
			if(array[j] < array[j-1])
				swap(array[j],array[j-1]);
		}
	}
}

//插入排序
void insertsort(int* array, int size)
{
	int i,j;
	for(i = 0; i < size; i++)
	{
		j = i;
		while(j)
		{
			if(array[j] < array[j-1])
				swap(array[j],array[j-1]);
			j--;
		}
	}
}

//merge sort
mergesort(int* array, int low, int high)
{
	if(low < high)
	{
		int middle = (high - low) / 2 + low;
		mergesort(array,low,middle);
		mergesort(array,middle+1,high);
	}
}

int main()
{
	int ar[5] = {4,2,5,1,3};
	//bublesort(ar,5);
	insertsort(ar,5);
	print_array(ar,5);
	return 0;
}
