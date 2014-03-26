/*You are given two linked lists representing two non-negative numbers.
 * The digits are stored in reverse order and each of their nodes contain a single digit. 
 * Add the two numbers and return it as a linked list.

	Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
	Output: 7 -> 0 -> 8*

 *Definition for singly-linked list.
 *struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 *};

 accepted 2014-03-26
 */
class Solution {
	public:
		ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
			int flag = 0;//½øÎ»
			int a;
			ListNode *root = new ListNode(0);
			ListNode *relist = root;
			if(l1 != NULL && l2 != NULL)
			{
				a = l1->val + l2->val + flag;
				flag = ((a - 10) >= 0) ? 1 : 0;
				a = (a >= 10) ? (a - 10) : a;
				relist->val = a;
				l1 = l1->next;
				l2 = l2->next;
			}
			while(l1 != NULL && l2 != NULL)
			{
				a = l1->val + l2->val + flag;
				flag = ((a - 10) >= 0) ? 1 : 0;
				a = (a >= 10) ? (a - 10) : a;
				relist->next = new ListNode(a);
				relist = relist->next;
				l1 = l1->next;
				l2 = l2->next;
			}
			while(l1 != NULL)
			{
				a = l1->val + flag;
				flag = ((a - 10) >= 0) ? 1 : 0;
				a = (a >= 10) ? (a - 10) : a;
				relist->next = new ListNode(a);
				relist = relist->next;
				l1 = l1->next;
			}
			while(l2 != NULL)
			{
				a = l2->val + flag;
				flag = ((a - 10) >= 0) ? 1 : 0;
				a = (a >= 10) ? (a - 10) : a;
				relist->next = new ListNode(a);
				relist = relist->next;
				l2 = l2->next;
			}
			if(flag)
				relist->next = new ListNode(flag);
			return root;
		}
};
