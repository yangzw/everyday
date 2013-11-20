#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<map>

using namespace std;

int city[505][505];
int teamnum[505];
int dijkstra[505];
bool isVisited[505];
int shortest,sumroad,sumteam;
const int INF = 10000000;

void init()
{
	for(int i = 0;i < 505;i++)
		isVisited[i] = false;
}

void Dijkstra(int n,int begin,int end)
{
	int i;
	for(i=0;i< n;i++)
		dijkstra[i] = city[begin][i];
	isVisited[begin] = true;
	for(i=0;i<n-1;i++)
	{
		int min = INF;
		int flag = INF;
		for(int j = 0;j < n;j++)
		{
			if(isVisited[j] == false && dijkstra[j] < min)
			{
				min = dijkstra[j];
				flag = j;
			}
			isVisited[flag] = true;
			if(flag == end)
				break;
			for(int k = 0;k < n;k++)
				if(isVisited[k] == false && dijkstra[flag] + city[flag][k] < dijkstra[k])
					dijkstra[k] = dijkstra[flag] + city[flag][k];
		}
	}
}

void DFS(int begin, int end,int n, int curDis,int curTeam)
{
	isVisited[begin] = true;

	if(begin == end)
	{
		if(curDis == shortest)
		{
			sumroad++;
			if(curTeam > sumteam)
				sumteam = curTeam;
		}
		return;
	}

	for(int i = 0;i < n;i++)
	{
		if(isVisited[i] == false && city[begin][i] != INF)
			if(curDis + city[begin][i] > shortest)
				continue;
			else
			{
				DFS(i,end,n,curDis+city[begin][i],curTeam+teamnum[i]);
				isVisited[i] = false;
			}
	}
	return;
}

int main(void)
{
	int N,M,C1,C2;
	cin >> N >> M >> C1 >> C2;
	for(int i = 0;i < N;i ++)
		cin >> teamnum[i];
	for(int p = 0;p < N;p ++)
		for(int q = 0;q < N;q++)
			if(p == q)
				city[p][q] = 0;
			else
				city[p][q] = INF;
	for(int i = 0;i < N;i ++)
		dijkstra[i] = INF;
	for(int i = 0;i < N;i ++)
		isVisited[i] = false;
	while(M){
		int a,b,len;
		cin >> a >> b >> len;
		city[a][b] = len;
		city[b][a] = len;
		M--;
	}
	Dijkstra(N,C1,C2);
	shortest = dijkstra[C2];
	init();
	DFS(C1,C2,N,0,teamnum[C1]);
	cout << sumroad << " " << sumteam;
	return 0;

}
