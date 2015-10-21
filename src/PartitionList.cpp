// Source : https://leetcode.com/problems/partition-list/
// Author : wind4869
// Date   : 2015-04-16

/********************************************************************************** 
 * 
 * Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
 * 
 * You should preserve the original relative order of the nodes in each of the two partitions.
 * 
 * For example,
 * Given 1->4->3->2->5->2 and x = 3,
 * return 1->2->2->4->3->5.
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
    ListNode *partition(ListNode *head, int x) {
    	if (head == NULL || head->next == NULL) return head;

        ListNode *node = head;
        ListNode *prev = NULL;

        if (node->val < x) {
        	while (node->next != NULL && node->next->val < x)
        		node = node->next;
        	if (node->next == NULL) return head;
        	else prev = node;
        }

        while (node->next != NULL) {
        	if (node->next->val < x) {
                ListNode *temp = node->next;
                node->next = temp->next;

        		if (prev == NULL) {
        			temp->next = head;
        			head = temp;
        			prev = head;
        		} else {
        			temp->next = prev->next;
        			prev->next = temp;
        			prev = prev->next;
        		}
                
        	} else node = node->next;
        }

        return head;
    }
};

int main()
{
	ListNode *head = NULL;
	int values[] = {1, 4, 2, 3, 5, 2};
	for (auto i: values)
		AddToTail(&head, i);
	Print(Solution().partition(head, 3));
}