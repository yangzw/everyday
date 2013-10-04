#include<iostream>

using namespace std;
void printPY(int n)
{
	if(n == 0)
		cout << "ling";
	else if(n == 1)
		cout << "yi";
	else if(n == 2)
		cout << "er";
	else if(n == 3)
		cout << "san";
	else if(n == 4)
		cout << "si";
	else if(n == 5)
		cout << "wu";
	else if(n == 6)
		cout << "liu";
	else if(n == 7)
		cout << "qi";
	else if(n == 8)
		cout << "ba";
	else if(n == 9)
		cout << "jiu";
}

int main()
{
	char a;
	int num[3] = {-1,-1,-1};
	int sum = 0;
	while((a = cin.get()) != '\n')
		sum += (a - '0');
	int i = 0;
	while(sum != 0)
	{
		num[i++] = sum % 10;
		sum = sum / 10;
	}
	for(i = 2;i >0;i--)
	{
		if(num[i] >= 0)
		{
			printPY(num[i]);
			cout << " ";
		}
	}
	printPY(num[0]);
	return 0;
}
