/*Given a binary tree, find its maximum depth.
 *
 * The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 *
 * accepted 2014-3-22
 */

/*
 *Definition for binary tree
 *struct TreeNode {
 *	int val;
 *	TreeNode *left;
 *	TreeNode *right;
 *	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *};
 */
class Solution {
	public:
    int maxDepth(TreeNode *root) {
            if(root == NULL)
                return 0;
            if(root->left == NULL && root->right == NULL)
            {
	                return 1;
	            }
            else
            {
	                int max = 0;
	                int b = 0;
	                if(root->left != NULL)
	                    max = maxDepth(root->left) + 1;
	                if(root->right != NULL)
	                    b = maxDepth(root->right) + 1;
	                if(b > max)
	                    max = b;
	                return max;
	            }
        }
};
