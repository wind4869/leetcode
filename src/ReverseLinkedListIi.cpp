// Source : https://leetcode.com/problems/reverse-linked-list-ii/
// Author : wind4869
// Date   : 2015-04-15

/********************************************************************************** 
 * 
 * Reverse a linked list from position m to n. Do it in-place and in one-pass.
 * 
 * For example:
 * Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 * 
 * return 1->4->3->2->5->NULL.
 * 
 * Note:
 * Given m, n satisfy the following condition:
 * 1 ≤ m ≤ n ≤ length of list.
 * 
 *               
 **********************************************************************************/
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void AddToTail(ListNode **head, int val)
{
	if (head == NULL)
		return;

	ListNode *NewNode = new ListNode(val);
	if (*head == NULL) *head = NewNode;
	else {
		ListNode *node = *head;
		while (node->next != NULL)
			node = node->next;
		node->next = NewNode;
	}
}

void Print(ListNode *head) {
	if (head == NULL)
		return;

	ListNode *node = head;
	while (node != NULL) {
		cout << node->val << " ";
		node = node->next;
	}
	cout << endl;
}

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
    	if (head == NULL || head->next == NULL) return head;
    	if (m == n) return head;

    	int count = 1;
    	ListNode *node = head;
    	ListNode *start = head, *left = NULL, *right = NULL;

    	for (int i = 1; i <= n; ++i) {
    		if (i == m - 1) {
				left = node;
				start = left->next;
    		}
    		node = node->next;
    	}

    	right = node;
    	start = reverse(start, left, right);

    	if (m == 1) return start;
    	return head;
    }

    ListNode *reverse(ListNode *start, ListNode *left, ListNode *right) {
     	ListNode *prev = right;
    	ListNode *node = start;

    	while (node != right) {
    		ListNode *next = node->next;

    		if (node->next == right) {
    			start = node;
    			if (left != NULL)
    				left->next = start;
    		}
    		
    		node->next = prev;
    		prev = node;
    		node = next;
    	}
    	return start;
    }
};

int main()
{
	ListNode *head = NULL;
	int values[] = {1, 2, 3, 4, 5};
	for (auto i: values)
		AddToTail(&head, i);
	Print(Solution().reverseBetween(head, 1, 4));
}
