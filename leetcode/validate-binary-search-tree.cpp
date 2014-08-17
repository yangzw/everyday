/* Given a binary tree, determine if it is a valid binary search tree (BST).
 *
 * Assume a BST is defined as follows:
 *
 * The left subtree of a node contains only nodes with keys less than the node's key.
 * The right subtree of a node contains only nodes with keys greater than the node's key.
 * Both the left and right subtrees must also be binary search trees.
 *
 * Definition for binary tree
 *  struct TreeNode {
 *      int val;
 *      TreeNode *left;
 *      TreeNode *right;
 *      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *  };
 */

class Solution{
	public:
		bool isValidBST(TreeNode *root){
			if(!root)
				return true;
			int before = 0;
			stack<TreeNode *> tstack;
			TreeNode *now = root;
			do{
				tstack.push(now);
				now = now->left;
			}while(now);
			before = tstack.top()->val - 1;
			while(!tstack.empty()){
				now = tstack.top();
				tstack.pop();
				if(before >= now->val)
					return false;
				before = now->val;
				if(now->right){
					now = now->right;
					do{
						tstack.push(now);
						now = now->left;
					}while(now);
				}
			}
			return true;
		}
};
