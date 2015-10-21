// Source : https://leetcode.com/problems/path-sum-ii/
// Author : wind4869
// Date   : 2015-08-22

/********************************************************************************** 
 * 
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
 * 
 * For example:
 * Given the below binary tree and sum = 22,
 * 
 *               5
 *              / \
 *             4   8
 *            /   / \
 *           11  13  4
 *          /  \    / \
 *         7    2  5   1
 * 
 * return
 * 
 * [
 *    [5,4,11,2],
 *    [5,8,4,5]
 * ]
 * 
 *               
 *               
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
	void pathSum(TreeNode *root, int sum, vector<int> temp, vector<vector<int>> &result) {
		temp.push_back(root->val);

		if (root->left == NULL && root->right == NULL) {
			if (sum - root->val == 0)
				result.push_back(temp);
			return;
		}

		if (root->left != NULL) 
			pathSum(root->left, sum - root->val, temp, result);

		if (root->right != NULL)
			pathSum(root->right, sum - root->val, temp, result);
	}

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        if (root == NULL)
        	return result;
        vector<int> temp;
        pathSum(root, sum, temp, result);
        return result;
    }
};

int main()
{

}