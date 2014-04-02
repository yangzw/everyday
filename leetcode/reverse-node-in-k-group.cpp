/* Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 * If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
 * You may not alter the values in the nodes, only nodes itself may be changed.
 * Only constant memory is allowed.
 * For example,
 * Given this linked list: 1->2->3->4->5
 * For k = 2, you should return: 2->1->4->3->5
 * For k = 3, you should return: 3->2->1->4->5 
 *
 * accepted 2014-03-30
 */
#include<iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reversekGroup(ListNode *head, int k){
	int i = 0;
	ListNode *p = head;
	while(p && i < k-1)
	{
		i++;
		p = p->next;
	}
	if(p == NULL || k == 1)
		return head;
	ListNode *p1,*p2,*p0;
	p0 = p1 = p2 = head;
	head = p;//Kth node
	p = p1;
	p1 = p1->next;
	p2 = p1->next;
	int j;
	do
	{
		i = 0;
		while(i < k - 1)
		{
			p1->next = p0;
			p0 = p1;
			p1 = p2;
			if(p2 == NULL)
			{
				p->next = NULL;
				return head;
			}
			p2 = p2->next;
			i++;
		}
		j = 1;
		while(p2 && j < k-1)
		{
			j++;
			p2 = p2->next;
		}
		if(p2 == NULL)
		{
			p->next = p1;
			break;
		}
		else
		{
			p->next = p2;
			p = p1;
			p1 = p1->next;
			p2 = p1->next;
			p0 = p;
		}
	}while(1);
	return head;
}

int main()
{
	ListNode *a = new ListNode(3);
	a->next = new ListNode(6);
	a->next->next = new ListNode(9);
	a->next->next->next = new ListNode(10);
	ListNode *b = reversekGroup(a,3);
	while(b)
	{
		cout << b->val << " ";
		b = b->next;
	}
	cout << endl;
	return 0;
}
