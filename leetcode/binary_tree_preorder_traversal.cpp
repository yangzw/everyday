/* Given a binary tree, return the preorder traversal of its nodes' values.
 * Note: Recursive solution is trivial, could you do it iteratively?
 *
 * accepted 2014-3-22
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
    vector<int> preorderTraversal(TreeNode *root) {
            vector<int> pre_order;
            stack<TreeNode*> node;
            if(root == NULL)
                return pre_order;
            pre_order.push_back(root->val);
            if(root->right != NULL)
                node.push(root->right);
            if(root->left != NULL)
                node.push(root->left);
            TreeNode *nodep;
            while((!node.empty()) && ((nodep = node.top()) != NULL))
            {
	                node.pop();
	                pre_order.push_back(nodep->val);
	                if(nodep->right != NULL)
	                    node.push(nodep->right);
	                if(nodep->left != NULL)
	                    node.push(nodep->left);
	            }
            return pre_order;
        }
};
