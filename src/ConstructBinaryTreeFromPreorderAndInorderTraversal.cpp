// Source : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// Author : wind4869
// Date   : 2015-07-07

/********************************************************************************** 
 * 
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 *               
 **********************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() > 0 && preorder.size() == inorder.size())
        	return buildTreeCore(preorder.begin(), preorder.end() - 1, inorder.begin(), inorder.end() - 1);
        return NULL;
    }
private:
	typedef vector<int>::iterator iter;
	TreeNode* buildTreeCore(iter beginPreorder, iter endPreorder, iter beginInorder, iter endInorder) {
		int val = *beginPreorder;
		TreeNode *root = new TreeNode(val);
		if (beginPreorder == endInorder) {
			if (beginInorder == endInorder && *beginPreorder == *beginInorder)
				return root;
			else
				return NULL;
		}

		iter rootInorder = beginInorder;
		while (rootInorder != endInorder && *rootInorder != val)
			++rootInorder;
		if (rootInorder == endInorder && *rootInorder != val)
			return NULL;

		int leftLength = rootInorder - beginInorder;
		iter leftEndPreorder = beginPreorder + leftLength;
		if (leftLength > 0)
			root->left = buildTreeCore(beginPreorder + 1, leftEndPreorder, beginInorder, rootInorder - 1);
		if (leftLength < endPreorder - beginPreorder)
			root->right = buildTreeCore(leftEndPreorder + 1, endPreorder, rootInorder + 1, endInorder);

		return root;
	}
};

int main()
{

}


