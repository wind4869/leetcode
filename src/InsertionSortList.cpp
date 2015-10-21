// Source : https://leetcode.com/problems/insertion-sort-list/
// Author : wind4869
// Date   : 2015-04-16

/********************************************************************************** 
 * 
 * Sort a linked list using insertion sort.
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
    ListNode *insertionSortList(ListNode *head) {
    	if (head == NULL || head->next == NULL) return head;

    	ListNode *helper = new ListNode(0);
    	helper->next = head;

    	ListNode *prev = helper;
    	ListNode *node = head;

    	while (node->next != NULL) {
    		ListNode *temp = node->next;
    		prev = helper;

    		while (prev->next != temp && prev->next->val <= temp->val)
    			prev = prev->next;

    		if (prev->next != temp) {
    			node->next = temp->next;
    			temp->next = prev->next;
    			prev->next = temp;
    		} else node = temp;
    	}

    	return helper->next;
    }
};

int main()
{
	ListNode *head = NULL;
	int values[] = {5, 3};
	for (auto i: values)
		AddToTail(&head, i);
	Print(Solution().insertionSortList(head));
}