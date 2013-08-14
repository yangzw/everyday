//3.5最短摘要的生成:给定网页经过分词以后的结果，词语序列数组为W。假设用户输入的搜素的关键字是数组q，求生成的最短摘要
//
#include<stdio.h>

int nTargetLen = N + 1;		//设置目标长度为总长度+1
int pBegin = 0;			//初始指针
int pEnd = 0;			//结束指针
int nLen = N;			//目标数组的长度为N
int nAbstractBegin = 0;		//目标摘要的起始地址
int nAbstractEnd = 0;		//目标摘要的结束地址

while(1)
{
	//假设包含所有的关键字，并且后面的指针没有越界，越往后移动指针
	while(!isAllExisted() && pEnd < nLen)
	{
		pEnd++;
	}
	//假设找到一段包含所有关键词信息的字符串,开始移动begin，找出最短的摘要
	while(isAllExisted())
	{
		if(pEnd - pBegin < nTargetLen)
		{
			nTargetLen = pEnd - pBegin;
			nAbstractBegin = pBegin;
			nAbstractEnd = pEnd - 1;
		}
		pBegin ++;
	}
	if(pEnd >= N)
		break;
}
