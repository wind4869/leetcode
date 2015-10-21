// Source : https://leetcode.com/problems/balanced-binary-tree/
// Author : wind4869
// Date   : 2015-04-16

/********************************************************************************** 
 * 
 * Given a binary tree, determine if it is height-balanced.
 * 
 * For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 * 
 *               
 **********************************************************************************/
class Solution {
public:
    bool isBalanced(TreeNode *root) {
    	if (root == NULL)
    		return true;
    	if (abs(depth(root->left) - depth(root->right)) > 1)
    		return false;
    	return isBalanced(root->left) && isBalanced(root->right);
    }

    int depth(TreeNode *root) {
    	if (root == NULL)
    		return 0;
    	return 1 + max(depth(root->left), depth(root->right));
    }
};