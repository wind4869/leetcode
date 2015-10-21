// Source : https://leetcode.com/problems/path-sum/
// Author : wind4869
// Date   : 2015-04-18

/********************************************************************************** 
 * 
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
 * 
 * For example:
 * Given the below binary tree and sum = 22,
 * 
 *               5
 *              / \
 *             4   8
 *            /   / \
 *           11  13  4
 *          /  \      \
 *         7    2      1
 * 
 * return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
    	if (root == NULL) return false;
    	return helper(root, sum);
    }

    bool helper(TreeNode *root, int sum) {
        if (root == NULL) {
        	if (sum == 0) return true;
        	else return false;
        }

        if (root->left == NULL) return helper(root->right, sum - root->val);
        if (root->right == NULL) return helper(root->left, sum - root->val);

        return helper(root->left, sum - root->val) || helper(root->right, sum - root->val);
    }
};

void print(TreeNode *root)
{
	if (root == NULL) return;

	cout << root->val << endl;
	print(root->left);
	print(root->right);
}

int main()
{
	int values[] = {1, 2};
	TreeNode *root = create(values, 0, 2);
	cout << Solution().hasPathSum(root, 1) << endl;
}
