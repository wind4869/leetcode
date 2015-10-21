// Source : https://leetcode.com/problems/remove-duplicates-from-sorted-list/
// Author : wind4869
// Date   : 2015-04-15

/********************************************************************************** 
 * 
 * Given a sorted linked list, delete all duplicates such that each element appear only once.
 * 
 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
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
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;

        ListNode *node = head;
        int current = head->val;

        while (node->next != NULL) {
        	int val = node->next->val;
        	if (val == current) {
        		ListNode *toBeDeleted = node->next;
        		node->next = node->next->next;
        		delete toBeDeleted;
        		toBeDeleted = NULL;
        	} else {
				current = val;
        		node = node->next;
        	}
        }

        return head;
    }
};

int main()
{
	ListNode *head = NULL;
	int values[] = {1, 1, 1};
	for (auto i: values)
		AddToTail(&head, i);
	Print(Solution().deleteDuplicates(head));
}