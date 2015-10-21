// Source : https://leetcode.com/problems/binary-tree-paths/
// Author : wind4869
// Date   : 2015-08-20

/********************************************************************************** 
 * 
 * Given a binary tree, return all root-to-leaf paths.
 * 
 * For example, given the following binary tree:
 * 
 *    1
 *  /   \
 * 2     3
 *  \
 *   5
 * 
 * All root-to-leaf paths are:
 * ["1->2->5", "1->3"]
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
 *               
 *               
 * 
 *               
 **********************************************************************************/
#include <iostream>
#include <sstream>
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
	void binaryTreePaths(TreeNode* root, vector<int> temp, vector<string>& result) {
		temp.push_back(root->val);
		if (root->left == NULL && root->right == NULL) {
			stringstream ss;
			for (int i = 0; i < temp.size(); ++i) {
				ss << temp[i];
				if (i < temp.size() - 1)
					ss << "->";
			}
			result.push_back(ss.str());
		}

		if (root->left) binaryTreePaths(root->left, temp, result);
		if (root->right) binaryTreePaths(root->right, temp, result);
	} 

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (root == NULL)
        	return result;
        
        vector<int> temp;
        binaryTreePaths(root, temp, result);
        return result; 
    }
};

int main()
{

}

