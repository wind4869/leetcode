// Source : https://leetcode.com/problems/binary-tree-maximum-path-sum/
// Author : wind4869
// Date   : 2015-07-09

/********************************************************************************** 
 * 
 * Given a binary tree, find the maximum path sum.
 * 
 * The path may start and end at any node in the tree.
 * 
 * For example:
 * Given the below binary tree,
 * 
 *        1
 *       / \
 *      2   3
 * 
 * Return 6.
 * 
 *               
 **********************************************************************************/
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int help(TreeNode* root, int &m) {
		if (root == NULL)
			return 0;

		int left = help(root->left, m);
		int right = help(root->right, m);
		int ret = max(max(left, right), 0) + root->val;
		m = max(max(m, ret), left + right + root->val);
		return ret;
	}
    int maxPathSum(TreeNode* root) {
        if (root == NULL)
        	return 0;
        int m = root->val;
        help(root, m);
        return m;
    }
};

int main()
{

}