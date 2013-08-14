//3.4从无头单链表中删除节点
//给定单链表的头，只遍历一次，将链表中元素反转
//
#include<iostream>
using namespace std;

//通过删除next，并将next的数据复制到current中来实现
void DeleteRandomNode(node* pCurrent)
{
	Assert(pCurrent != NULL);
	node* pNext = pCurrent->next;
	if(pNext != NULL)
	{
		pCurrent->next = pNext-next;
		pCurrent->data = pNext->data;
		delete pNext;
	}
}

//遍历一次实现反转
node* ReverseNodeList(node* head)
{
	if(head == NULL)
		return NULL;
	node* pNext = head->next;
	node* pRes = head;
	pRes->next = NULL;
	while(pNext != NULL)
	{
		head = pNext->next;
		pNext->next = pRes;
		pRes = pNext;
		pNext = head;
	}
	head = pRes;
	return head;
}
