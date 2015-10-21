// Source : https://leetcode.com/problems/remove-linked-list-elements/
// Author : wind4869
// Date   : 2015-04-27

/********************************************************************************** 
 * 
 * Remove all elements from a linked list of integers that have value val.
 * 
 * Example
 * Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6,  val = 6
 * Return: 1 --> 2 --> 3 --> 4 --> 5
 * 
 * Credits:Special thanks to @mithmatt for adding this problem and creating all test cases.
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
    ListNode* removeElements(ListNode* head, int val) {
    	if (head == NULL) return NULL;

    	ListNode *helper = new ListNode(0);
    	helper->next = head;

    	ListNode *node = helper;
    	while (node->next != NULL) {
    		if (node->next->val == val) {
    			delete node->next;
    			node->next = node->next->next;
    		} else node = node->next;
    	}

    	head = helper->next;
    	delete helper;
    	return head;
    }
};

int main()
{
	ListNode *head = NULL;
	int values[] = {6, 6, 6, 6};
	for (auto i: values)
		AddToTail(&head, i);
	Print(Solution().removeElements(head, 6));
}

