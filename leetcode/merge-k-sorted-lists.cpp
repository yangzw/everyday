/*Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity. 
 * 
 * accepted 2014-03-30
 */
#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void shiftdown(ListNode** nodearray, int len, int pos)
{
	int i = pos;
	int tmp = 0;
	while(i*2 <= len)
	{
//		cout << i << "here?" << len << endl;
		tmp = i*2;
		if(2*i + 1 <= len && nodearray[i*2 + 1]->val < nodearray[tmp]->val)
			tmp = tmp + 1;
		if(nodearray[tmp]->val < nodearray[i]->val)
		{
			ListNode *nodetmp = nodearray[tmp];
			nodearray[tmp] = nodearray[i];
			nodearray[i] = nodetmp;
		}
		i = tmp;
	}
}

ListNode *mergeKLists(vector<ListNode *> &lists){
	int arraylen = lists.size();
	ListNode *array[arraylen+1];
	ListNode *re;
	int i,j;
	for(i = 0,j = 0; i < lists.size(); i++)
	{
		if(lists[i] == NULL)
			continue;
		array[++j] = lists[i];
	}
	arraylen = j;
	if(arraylen == 0)
		return NULL;
	int tmp;
	for(i = arraylen/2; i >= 1; i--)
	{
		shiftdown(array,arraylen,i);
	}
	re = new ListNode(array[1]->val);
	ListNode* p = re;
	while(arraylen > 0)
	{
		while(array[1]->next)
		{
			array[1] = array[1]->next;
			shiftdown(array,arraylen,1);
//			cout << "-(" << array[1]->val;
			p->next = new ListNode(array[1]->val);
			p = p->next;
		}
		if(arraylen == 1)
			break;
		array[1] = array[arraylen];
		arraylen = arraylen - 1;
		shiftdown(array,arraylen,1);
//		cout << "+(" << array[1]->val;
		p->next = new ListNode(array[1]->val);
		p = p->next;
	}
	return re;
}


int main()
{
	vector<ListNode *> a;
	ListNode* b1 = new ListNode(-8);
	ListNode* a1 = b1;
	b1->next = new ListNode(-7);
	b1 = b1->next;
	b1->next = new ListNode(-6);
	b1 = b1->next;
	b1->next = new ListNode(-3);
	b1 = b1->next;
	b1->next = new ListNode(-2);
	b1 = b1->next;
	b1->next = new ListNode(-2);
	b1 = b1->next;
	b1->next = new ListNode(-0);
	b1 = b1->next;
	b1->next = new ListNode(3);
	ListNode* b2 = new ListNode(-10);
	ListNode* a2 = b2;
	b2->next = new ListNode(-6);
	b2 = b2->next;
	b2->next = new ListNode(-4);
	b2 = b2->next;
	b2->next = new ListNode(-4);
	b2 = b2->next;
	b2->next = new ListNode(-4);
	b2 = b2->next;
	b2->next = new ListNode(-2);
	b2 = b2->next;
	b2->next = new ListNode(-1);
	b2 = b2->next;
	b2->next = new ListNode(4);
	ListNode* b3 = new ListNode(-10);
	ListNode* a3 = b3;
	b3->next = new ListNode(-9);
	b3 = b3->next;
	b3->next = new ListNode(-8);
	b3 = b3->next;
	b3->next = new ListNode(-8);
	b3 = b3->next;
	b3->next = new ListNode(-6);
	ListNode* b4 = new ListNode(-10);
	ListNode* a4 = b4;
	b4->next = new ListNode(0);
	b4 = b4->next;
	b4->next = new ListNode(4);
	a.push_back(a1);
	a.push_back(a2);
	a.push_back(a3);
	a.push_back(a4);
	ListNode *back = mergeKLists(a);
	while(back)
	{
		cout << back->val << endl;
		back = back->next;
	}
	return 0;
}
