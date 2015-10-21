// Source : https://leetcode.com/problems/binary-tree-postorder-traversal/
// Author : wind4869
// Date   : 2015-03-24

/********************************************************************************** 
 * 
 * Given a binary tree, return the postorder traversal of its nodes' values.
 * 
 * For example:
 * Given binary tree {1,#,2,3},
 * 
 *    1
 *     \
 *      2
 *     /
 *    3
 * 
 * return [3,2,1].
 * 
 * Note: Recursive solution is trivial, could you do it iteratively?
 *               
 **********************************************************************************/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
    	vector<int> v;
    	if (root == NULL) 
    		return v;

    	stack<TreeNode *> s;
    	s.push(root);

    	TreeNode *prev = NULL;
    	while (!s.empty()) {
    		root = s.top();
    		if ((root->left == NULL && root->right == NULL) ||
    			(prev != NULL && (prev == root->left || prev == root->right))) {
    			v.push_back(root->val);
    			s.pop();
    			prev = root;
    		}
    		else {
				if (root->right != NULL)
    				s.push(root->right);
    			if (root->left != NULL)
    				s.push(root->left);
    		}
    	}
    	return v;
    }
};


