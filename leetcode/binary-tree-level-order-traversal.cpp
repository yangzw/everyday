/*Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
 *
 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
 *         3
 *        / \
 *       9  20
 *         /  \
 *        15   7
 * return its level order traversal as:
 * [
 *   [3],
 *   [9,20],
 *   [15,7]
 * ]
 *
 *Definition for binary tree
 *
 *struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *};
 */

class Solution {
	public:
		vector<vector<int> > levelOrder(TreeNode *root) {
			vector<vector<int> > re;
			if(root == NULL)
				return re;
			TreeNode * cur;
			queue<TreeNode *> que;
			que.push(root);
			vector<int> tmp;
			while(!que.empty())
			{
				int size  = que.size();
				for(int i = 0; i < size; i++)
				{
					cur = que.front();
					que.pop();
					tmp.push_back(cur->val);
					if(cur->left)
						que.push(cur->left);
					if(cur->right)
						que.push(cur->right);
				}
				re.push_back(tmp);
				tmp.resize(0);
			}
			if(!tmp.empty())
			return re;
		}
};
