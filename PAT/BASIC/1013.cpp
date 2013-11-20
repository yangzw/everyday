#include<iostream>
using namespace std;
const long N = 200000; 

long prime[N] = {0},num_prime = 0;
int isNotPrime[N] = {1, 1};
int main()
{
	long i,min,max;
	cin >> min >> max;
	for(i = 2 ; i < N ; i ++)
	{
		if(!isNotPrime[i])
			prime[num_prime ++]=i;
		if(num_prime >= max)
			break;
		for(long j = 0 ; j < num_prime && i * prime[j] <  N ; j ++)
		{
			isNotPrime[i * prime[j]] = 1;
			if(!(i % prime[j] ))
				break;
		}
	}
	int col = 1;
	for(i = min-1;i < max-1; i++)
	{
		if(col < 10)
		{
			cout << prime[i] << " ";
			col++;
		}
		else 
		{
			col = 1;
			cout << prime[i] << endl;
		}
	}
	cout << prime[max-1];
	return 0;   
}  
