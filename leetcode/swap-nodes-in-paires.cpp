/** Given a linked list, swap every two adjacent nodes and return its head.
 * For example,
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 * Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed. 
 *
 *   Definition for singly-linked list.
 *   struct ListNode {
 *       int val;
 *       ListNode *next;
 *       ListNode(int x) : val(x), next(NULL) {}
 *   };
 *
 *   accecpted 2014-03-30
 */

#include<iostream>
using namespace std;

ListNode *swapPairs(ListNode *head) {
	ListNode *phead,*p,*pnext;
	phead = p = pnext = NULL;
	if(head == NULL || head->next == NULL)
		return head;
	phead = head;
	p = phead->next;
	head = p;
	do
	{
		pnext = p->next;
		p->next = phead;
		phead->next = pnext;
		if(pnext == NULL)
			break;
		if(pnext->next)
			phead->next = pnext->next;
		phead = pnext;
		p = phead->next;
	}while(p);
	return head;
}
