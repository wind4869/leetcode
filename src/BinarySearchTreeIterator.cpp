// Source : https://leetcode.com/problems/binary-search-tree-iterator/
// Author : wind4869
// Date   : 2015-04-09

/********************************************************************************** 
 * 
 * Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
 * 
 * Calling next() will return the next smallest number in the BST.
 * 
 * Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree. 
 * 
 * Credits:Special thanks to @ts for adding this problem and creating all test cases.
 *               
 **********************************************************************************/
#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *create(int values[], int index, int n)
{
	if (index >= n) return NULL;
	if (values[index] == 0) return NULL;

	TreeNode *root = new TreeNode(values[index]);
	root->left = create(values, 2 * index + 1, n);
	root->right = create(values, 2 * index + 2, n);

	return root;
}

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
    	while (root != NULL) {
    		s.push(root);
    		root = root->left;
    	}
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
    	TreeNode *node = s.top();
    	s.pop();
    	if (node->right != NULL) {
    		TreeNode *root = node->right;
    		while (root != NULL) {
    			s.push(root);
    			root = root->left;
    		}
    	}
    	return node->val;
    }
private:
	stack<TreeNode *> s;
};

int main()
{
	int values[] = {1,0,2};
	TreeNode *root = create(values, 0, 3);

	BSTIterator i = BSTIterator(root);
 	while (i.hasNext())
 		cout << i.next();
}

