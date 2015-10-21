// Source : https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
// Author : wind4869
// Date   : 2015-04-15

/********************************************************************************** 
 * 
 * Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
 * 
 * For example,
 * Given 1->2->3->3->4->4->5, return 1->2->5.
 * Given 1->1->1->2->3, return 2->3.
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
        ListNode *prev = NULL;

        while (node != NULL && node->next != NULL) {
        	int val = node->val;
        	if (node->next->val == val) {
				while (node->next != NULL && node->next->val == val)
					node = node->next;
        		if (prev == NULL) head = node->next;
        		else prev->next = node->next;
        	} else prev = node;
        	node = node->next;
        }
        return head;
    }
};

int main()
{
	ListNode *head = NULL;
	int values[] = {1, 1, 2, 2};
	for (auto i: values)
		AddToTail(&head, i);
	Print(Solution().deleteDuplicates(head));
}
