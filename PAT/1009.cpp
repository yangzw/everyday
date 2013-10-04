#include<iostream>
#define SIZE 81

using namespace std;

int main()
{
	char array[SIZE];
	int i = 0;
	int len;
	while((array[i++] = cin.get())!= '\n');
	len =  i-1;
	int j;
	while(len > 0)
	{
		i = i - 1;
		while((i>=0) && array[i] != ' ')
			i--;
		for(j=i+1;j<len;j++)
			cout << array[j];
		if(i > 0)
			cout << " ";
		len = i;
	}
	return 0;
}
