// Source : https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
// Author : wind4869
// Date   : 2015-03-24

/********************************************************************************** 
 * 
 * Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
 * 
 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
 * 
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * 
 * return its bottom-up level order traversal as:
 * 
 * [
 *   [15,7],
 *   [9,20],
 *   [3]
 * ]
 * 
 * confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
 * 
 * OJ's Binary Tree Serialization:
 * 
 * The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.
 * 
 * Here's an example:
 * 
 *    1
 *   / \
 *  2   3
 *     /
 *    4
 *     \
 *      5
 * 
 * The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}". 
 * 
 *               
 **********************************************************************************/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > result;
        if (root == NULL) return result;

        vector<int> v;
        vector<TreeNode *> level;
        queue<vector<TreeNode *> > q;

        level.push_back(root);
        q.push(level);

        vector<vector<int> >::iterator it = result.begin();
        while (!q.empty()) {
        	vector<TreeNode *> roots = q.front();
        	q.pop();

        	level.clear();
        	v.clear();
        	for (vector<TreeNode *>::iterator i = roots.begin(); i != roots.end(); ++i) {
        		if ((*i)->left != NULL)
        			level.push_back((*i)->left);
        		if ((*i)->right != NULL)
        			level.push_back((*i)->right);
        		v.push_back((*i)->val);
        	}
        	if (!level.empty()) q.push(level);
        	if (!v.empty()) it = result.insert(it, v);
        }
        return result;
    }
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

int main()
{
	int values[] = {3,9,20,0,0,15,7};
	TreeNode *root = create(values, 0, 7);
	Solution s;
	vector<vector<int> > result = s.levelOrderBottom(root);
	for (auto v : result)
	{
		for (auto i : v)
			cout << i << ' ';
		cout << endl;
	}
}


