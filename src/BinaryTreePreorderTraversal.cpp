// Source : https://leetcode.com/problems/binary-tree-preorder-traversal/
// Author : wind4869
// Date   : 2015-03-22

/********************************************************************************** 
 * 
 * Given a binary tree, return the preorder traversal of its nodes' values.
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
 * return [1,2,3].
 * 
 * Note: Recursive solution is trivial, could you do it iteratively?
 *               
 **********************************************************************************/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
    	vector<int> v;
    	stack<TreeNode *> s;
    	if (root == NULL) return v;

    	while (!s.empty() || root != NULL) {
    		while (root != NULL) {
    			v.push_back(root->val);
    			s.push(root);
    			root = root->left;
    		}

    		root = s.top();
    		s.pop();
    		root = root->right;
    	}
    	return v;
    }
};
