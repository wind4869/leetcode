// Source : https://leetcode.com/problems/reorder-list/
// Author : wind4869
// Date   : 2015-04-16

/********************************************************************************** 
 * 
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 * 
 * You must do this in-place without altering the nodes' values.
 * 
 * For example,
 * Given {1,2,3,4}, reorder it to {1,4,2,3}.
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
    void reorderList(ListNode *head) {
    	if (head == NULL || head->next == NULL) return;

    	ListNode *slow = head, *fast = head;
    	while (fast->next != NULL && fast->next->next != NULL) {
    		slow = slow->next;
    		fast = fast->next->next;
    	}

    	ListNode *mid = slow->next;
    	ListNode *pre = slow->next = NULL;

    	while (mid != NULL) {
    		ListNode *next = mid->next;
    		mid->next = pre;
    		pre = mid;
    		mid = next;
    	}

    	while (head != NULL && pre != NULL) {
    		ListNode *node1 = head;
  			head = head->next;

    		ListNode *node2 = pre;
    		pre = pre->next;

    		node1->next = node2;
    		node2->next = head;
    	}
    }
};

int main()
{
	ListNode *head = NULL;
	int values[] = {1, 2, 3, 4, 5, 6, 7};
	for (auto i: values)
		AddToTail(&head, i);
	Solution().reorderList(head);
	Print(head);
}