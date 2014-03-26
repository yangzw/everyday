/*Given a binary tree, return the postorder traversal of its nodes' values.
 * Note: Recursive solution is trivial, could you do it iteratively?
 *
 * accepted 2014-3-23
 */
/**
 *Definition for binary tree
 *struct TreeNode {
 *    int val;
 *    TreeNode *left;
 *    TreeNode *right;
 *    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *};
 */
class Solution {
	public:
		vector<int> postorderTraversal(TreeNode *root) {
			stack<TreeNode*> nodestack;
			stack<int> flagstack;
			vector<int> post_order;
			if(root == NULL)
				return post_order;
			nodestack.push(root);
			flagstack.push(0);
			TreeNode* node = root;
			while(node->left != NULL)
			{
				nodestack.push(node->left);
				flagstack.push(0);
				node = node->left;
			}
			int flag = 0;//0 left ; 1 right
			while(!nodestack.empty())
			{
				flag = flagstack.top();
				node = nodestack.top();
				while(flag == 0 && (node->right != NULL))
				{
					flagstack.top() = 1;
					nodestack.push(node->right);
					node = node->right;
					flagstack.push(0);
					while(node->left)
					{
						nodestack.push(node->left);
						flagstack.push(0);
						node = node->left;
					}
					flag = flagstack.top();
				}
				post_order.push_back(nodestack.top()->val);
				flagstack.pop();
				nodestack.pop();
			}
		}
};
