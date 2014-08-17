/**
 * the solution also works for Populating Next Right Pointers in Each Node II
 *
 * For example,
 * Given the following perfect binary tree,
 *          1
 *         /  \
 *        2    3
 *       / \  / \
 *      4  5  6  7
 *After calling your function, the tree should look like:
 *       1 -> NULL
 *      /  \
 *     2 -> 3 -> NULL
 *    / \  / \
 *   4->5->6->7 -> NULL
 *
 *Definition for binary tree with next pointer.
 *
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 **/
class Solution{
	public:
		void connect(TreeLinkNode *root){
			if(!root)
				return;
			queue<TreeLinkNode *> que;
			que.push(root);
			TreeLinkNode *before;
			while(!que.empty())
			{
				before = NULL;
				int size = que.size();
				for(int i = 0; i < size; i++)
				{
					TreeLinkNode *now = que.front();
					que.pop();
					if(before)
						before->next = now;
					if(now->left)
						que.push(now->left);
					if(now->right)
						que.push(now->right);
					before = now;
				}
				before->next = NULL;
			}
		}
};
