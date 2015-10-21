// Source : https://leetcode.com/problems/count-complete-tree-nodes/
// Author : wind4869
// Date   : 2015-08-22

/********************************************************************************** 
 * 
 * Given a complete binary tree, count the number of nodes.
 * 
 * Definition of a complete binary tree from Wikipedia:
 * In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
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
    int countNodes(TreeNode* root) {
        if (root == NULL)
        	return 0;

        int leftHeight = 1;
        int rightHeight = 1;
        TreeNode *node = root->left;
        while (node != NULL) {
        	++leftHeight;
        	node = node->left;
        }

        node = root->right;
        while (node != NULL) {
        	++rightHeight;
        	node = node->right;
        }

        if (leftHeight == rightHeight)
        	return (1 << leftHeight) - 1;
        else
        	return countNodes(root->left) + countNodes(root->right) + 1;
    }
};

int main()
{
	
}
