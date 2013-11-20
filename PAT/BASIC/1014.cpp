#include<iostream>
#include<cstring>
using namespace std;

char array[4][61];
int main()
{
	memset(array,'0',sizeof(array));
	int i=0,j=0;
	for(i = 0;i < 4;i++)
		cin.getline(array[i],61);
	int len1 = strlen(array[0]);
	int len2 = strlen(array[1]);
	int len3 = strlen(array[2]);
	int len4 = strlen(array[3]);


	i = 0;
	for (;i<len1&&j<len2;i++,j++)
	{
		if (array[0][i]==array[1][j] && array[0][i]>='A' &&array[0][i]<='G')
		{
			switch(array[0][i])
			{
				case 'A':cout << "MON ";break;
				case 'B':cout << "TUE ";break;
				case 'C':cout << "WED ";break;
				case 'D':cout << "THU ";break;
				case 'E':cout << "FRI ";break;
				case 'F':cout << "SAT ";break;
				case 'G':cout << "SUN ";break;		  
			}
			break;
		}
	}
	for (i++,j++;i<len1&&j<len2;i++,j++)
	{
		if (array[0][i]==array[1][j] && (array[0][i]>='A' &&array[0][i]<='N' || array[0][i]>='0'&&array[0][i]<='9'))
		{
			int t=0;
			if (array[0][i]>='A'&&array[0][i]<='N')
				t = array[0][i] - 'A' +10;
			else
				t = array[0][i]-'0';
			cout << t/10 << t%10 << ":";
			break;
		}
	}
	for (i=0,j=0;i<len3&&j<len4;i++,j++)
	{
		if (array[2][i]==array[3][j] && (array[2][i]>='A' && array[2][i]<='Z'||array[2][i]>='a'&&array[2][i]<='z'))
		{
			cout << i/10 << i%10;
			break;
		}
	}



	return 0;
}
