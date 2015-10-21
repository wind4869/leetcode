// Source : https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
// Author : wind4869
// Date   : 2015-07-07

/********************************************************************************** 
 * 
 * Given inorder and postorder traversal of a tree, construct the binary tree.
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    	int sizeInorder = inorder.size();
    	int sizePostorder = inorder.size();

    	if (sizeInorder <= 0 || sizeInorder != sizePostorder)
    		return NULL;

    	return buildTreeCore(inorder.begin(), inorder.end() - 1, postorder.begin(), postorder.end() - 1);
    }
private:
	typedef vector<int>::iterator iter;
	TreeNode* buildTreeCore(iter beginInorder, iter endInorder, iter beginPostorder, iter endPostorder) {
    	int val = *endPostorder;
    	TreeNode *root = new TreeNode(val);

    	if (beginInorder == endInorder) {
    		if (beginPostorder == endPostorder && *beginInorder == *beginPostorder)
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
    	iter leftPostorderEnd = beginPostorder + leftLength - 1;
    	if (leftLength > 0)
    		root->left = buildTreeCore(beginInorder, rootInorder - 1, beginPostorder, leftPostorderEnd);
    	if (leftLength < endInorder - beginInorder)
    		root->right = buildTreeCore(rootInorder + 1, endInorder, leftPostorderEnd + 1, endPostorder - 1);

    	return root;
	}
};

int main()
{

}
