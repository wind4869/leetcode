// Source : https://leetcode.com/problems/merge-two-sorted-lists/
// Author : wind4869
// Date   : 2015-03-22

/********************************************************************************** 
 * 
 * Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
 *               
 **********************************************************************************/
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == NULL && l2 == NULL)
        	return NULL;
        if (l1 == NULL)
        	return l2;
        if (l2 == NULL)
        	return l1;

        ListNode *head, *prev = NULL;
        while (l1 != NULL && l2 != NULL) {
        	ListNode *pCur;
        	if (l1->val <= l2->val) {
        		pCur = l1;
        		l1 = l1->next;
        	} else {
        		pCur = l2;
        		l2 = l2->next;
        	}
        	if (prev == NULL)
        		head = pCur;
        	else
        		prev->next = pCur;
        	prev = pCur;
        }

        while (l1 != NULL) {
        	prev->next = l1;
        	prev = l1;
        	l1 = l1->next;
        }

        while (l2 != NULL) {
        	prev->next = l2;
        	prev = l2;
        	l2 = l2->next;
        }
        return head;
    }
};
