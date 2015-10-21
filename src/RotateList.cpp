// Source : https://leetcode.com/problems/rotate-list/
// Author : wind4869
// Date   : 2015-04-15

/********************************************************************************** 
 * 
 * Given a list, rotate the list to the right by k places, where k is non-negative.
 * 
 * For example:
 * Given 1->2->3->4->5->NULL and k = 2,
 * return 4->5->1->2->3->NULL.
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
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL || head->next == NULL) return head;

        int count = 1;
        ListNode *pEnd = head;
        while (pEnd->next != NULL) {
        	pEnd = pEnd->next;
        	count++;
        }

        k = k % count;
        if (k == 0) return head;

        ListNode *pStart = head;
        for (int i = 0; i < count - k; ++i) {
        	pEnd->next = pStart;
        	pEnd = pStart;
        	pStart = pStart->next;
        	pEnd->next = NULL;
        }

        return pStart;
    }
};

int main()
{
	ListNode *head = NULL;
	int values[] = {1, 2, 3};
	for (auto i: values)
		AddToTail(&head, i);
	Print(Solution().rotateRight(head, 2000000000));
}

