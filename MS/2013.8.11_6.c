//3.8求二叉树中节点的最大距离
//
#include<stdio.h>
struct NODE
{
	NODE* pLeft;
	NODE* pRight;
	int nMaxLeft;
	int nMaxRight;
	char chValue;	//该节点的值
};

int nMaxLen = 0;

//寻找树中最长的两段距离
void FindMaxLen(NDOE* pRoot)
{
	//遍历到叶节点，返回
	if(pRoot == NULL)
		return;
	if(pRoot->pLeft == NULL)
		pRoot->nMaxLeft = 0;
	if(pRoot->pRight == NULL)
		pRoot->nMaxRight = 0;
	if(pRoot->pLeft != NULL)
		FindMaxLen(pRoot->pLeft);
	if(pRoot->pRight != NULL)
		FindMaxLen(pRoot->pRight);
	//计算左子树的最长节点距离
	if(pRoot->pLeft != NULL)
	{
		int nTempMax = 0;
		if(pRoot->pLeft->nMaxLeft > pRoot->pLeft->nMaxRight)
			nTempMax = pRoot->pLeft->nMaxLeft;
		else
			nTempMax = pRoot->pLeft->nMaxRight;
		pRoot->nMaxLeft = nTempMax + 1;
	}

	//计算右子树的最长节点距离
	if(pRoot->pRight != NULL)
	{
		int nTempMax = 0;
		if(pRoot->pRight->nMaxLeft > pRoot->pRight->nMaxRight)
			nTempMax = pRoot->pRight->nMaxLeft;
		else
			nTempMax = pRoot->pRight->nMaxRight;
		pRoot->nMaxRight = nTempMax + 1;
	}
	//更新最长距离
	if(pRoot->nMaxLeft + pRoot -> nMaxRight > nMaxLen)
		nMaxLen = pRoot->nMaxLeft + pRoot->nMaxRight;
}
