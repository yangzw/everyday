//计算字符串的相似度
//把两个字符串变成相同有三套操作，分别是修改/增加/删除 一个字符，将操作所需的次数定义为两个字符串的距离，而相似度即为距离+1的倒数
//1用递归法(书上给出
//2 用动态规划的方法(自己写的

#include<iostream>
#include<string>
using namespace std;

int minValue(int a, int b, int c)
{
	return a > b ? (b > c ? c : b) : (a > c ? c : a);
}

int calculateStringDistance(string strA,int pABegin,int pAEnd,string strB,int pBBegin,int pBEnd)
{
	if(pABegin > pAEnd)
	{
		if(pBBegin > pBEnd)
			return 0;
		else
			return pBEnd - pBBegin + 1;
	}

	if(pBBegin > pBEnd)
	{
		if(pABegin > pAEnd)
			return 0;
		else
			return pAEnd - pABegin + 1;
	}

	if(strA[pABegin] == strB[pBBegin])
		return calculateStringDistance(strA,pABegin+1,pAEnd,strB,pBBegin+1,pBEnd);
	else
	{
		int t1 = calculateStringDistance(strA,pABegin,pAEnd,strB,pBBegin+1,pBEnd);
		int t2 = calculateStringDistance(strA,pABegin+1,pAEnd,strB,pBBegin,pBEnd);
		int t3 = calculateStringDistance(strA,pABegin+1,pAEnd,strB,pBBegin+1,pBEnd);
		return minValue(t1,t2,t3) + 1;
	}
}

int calculateStringDistance2(string strA,int lengA, string strB, int lengB)
{
	int i,j;
	int matrix[lengA+1][lengB+1];
	//最外层加初始化的值
	for(i = 0;i <= lengA;i++)
		matrix[i][lengB] = lengA - i; 
	for(j = 0;j <= lengB;j++)
		matrix[lengA][j] = lengB - j;

	for(i = lengA - 1;i >= 0;i--)
	{
		for(j = lengB -1 ;j >= 0;j--)
		{
			if(strA[i] == strB[j])
				matrix[i][j] = matrix[i+1][j+1];
			else
				matrix[i][j] = minValue(matrix[i+1][j],matrix[i+1][j+1],matrix[i][j+1]) + 1;
		}
	}
	return matrix[0][0];
}

int main()
{
	string strA = "akbd";
	string strB = "eabc";
	float dis = calculateStringDistance(strA,0,2,strB,0,3);
	cout << "The distance is:" << dis << endl;
	cout << "The similarity is:"<< 1 / (1 + dis) << endl;
	cout << "==============" << endl;
	float madis = calculateStringDistance2(strA,3,strB,4);
	cout << "The distance is:" << madis << endl;
	cout << "The similarity is:"<< 1 / (1 + madis) << endl;
	return 0;
}
