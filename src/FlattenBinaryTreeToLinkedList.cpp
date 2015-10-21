// Source : https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
// Author : wind4869
// Date   : 2015-07-09

/********************************************************************************** 
 * 
 * Given a binary tree, flatten it to a linked list in-place.
 * 
 * For example,
 * Given
 * 
 *          1
 *         / \
 *        2   5
 *       / \   \
 *      3   4   6
 * 
 * The flattened tree should look like:
 * 
 *    1
 *     \
 *      2
 *       \
 *        3
 *         \
 *          4
 *           \
 *            5
 *             \
 *              6
 * 
 * click to show hints.
 * 
 * Hints:
 * If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.
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
	void help(TreeNode* root, TreeNode* &last) {
		last = root;
		if (root == NULL)
			return;

		TreeNode *myLast, *temp = root->right;
		help(root->left, myLast);
		if (myLast != NULL) {
			last = myLast;
			last->right = temp;
			root->right = root->left;
			root->left = NULL;
		}
		help(root->right, myLast);
		if (myLast != NULL)
			last = myLast;

	}
    void flatten(TreeNode* root) {
        if (root == NULL)
        	return;
        TreeNode *last;
        help(root, last);
    }
};

int main()
{

}
