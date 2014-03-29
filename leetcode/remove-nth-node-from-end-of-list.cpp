/*Given a linked list, remove the nth node from the end of list and return its head.
 *
 * For example,
 *    Given linked list: 1->2->3->4->5, and n = 2.
 *    After removing the second node from the end, the linked list becomes 1->2->3->5.
 *
 *    Note:
 *    Given n will always be valid.
 *    Try to do this in one pass. 
 *
 *    accepted 2014-03-29
 */
#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n) {
	int i = 0;
	ListNode* p = head;
	ListNode* p2 = head;
	if(head->next == NULL)
	{
		delete head;
		return NULL;
	}
	while(i < n-1)
	{
		p = p->next;
		i++;
	}
	while(p->next)
	{
		p = p->next;
		p2 = p2->next;
	}
	ListNode* pnext = p2->next;
	if(pnext == NULL)
	{
		ListNode* pro = head;
		while(pro->next && pro->next != p2)
			pro = pro->next;
		pro->next = NULL;
		delete p2;
		return head;
	}
	p2->next = pnext->next;
	p2->val = pnext->val;
	delete pnext;
	return head;
}

int main()
{
	ListNode* a = new ListNode(1);
//	a->next = new ListNode(2);
	ListNode* b = removeNthFromEnd(a,1);
	while(b)
	{
		cout << b->val << endl;
		b = b->next;
	}
	return 0;
}
