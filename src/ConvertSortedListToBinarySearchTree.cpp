// Source : https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
// Author : wind4869
// Date   : 2015-07-07

/********************************************************************************** 
 * 
 * Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
 *               
 **********************************************************************************/
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
    	if (head == NULL)
    		return NULL;

    	ListNode *slow = head;
    	ListNode *fast = head;
    	ListNode *prev = NULL;
    	while (fast != NULL && fast->next != NULL) {
    		prev = slow;
    		slow = slow->next;
    		fast = fast->next->next;
    	}

    	TreeNode *root = new TreeNode(slow->val);
    	if (prev != NULL) {
    		prev->next = NULL;
    		root->left = sortedListToBST(head);
    	}
    	if (slow->next != NULL)
    		root->right = sortedListToBST(slow->next);

    	return root;
    }
};
