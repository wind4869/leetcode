// Source : https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
// Author : wind4869
// Date   : 2015-07-07

/********************************************************************************** 
 * 
 * Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
    	int size = nums.size();
    	if (size <= 0)
    		return NULL;

    	return sortedArrayToBSTCore(nums, 0, size - 1);
    }
private:
	TreeNode* sortedArrayToBSTCore(vector<int>& nums, int low, int high) {
		int mid = low + ((high - low) >> 1);
		TreeNode *root = new TreeNode(nums[mid]);
		if (low == high)
			return root;

		if (mid > low)
			root->left = sortedArrayToBSTCore(nums, low, mid - 1);
		if (mid < high)
			root->right = sortedArrayToBSTCore(nums, mid + 1, high);

		return root;
	}
};

int main()
{

}
