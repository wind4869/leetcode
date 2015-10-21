// Source : https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Author : wind4869
// Date   : 2015-03-22

/********************************************************************************** 
 * 
 * Given a linked list, remove the nth node from the end of list and return its head.
 * 
 * For example,
 * 
 *    Given linked list: 1->2->3->4->5, and n = 2.
 * 
 *    After removing the second node from the end, the linked list becomes 1->2->3->5.
 * 
 * Note:
 * Given n will always be valid.
 * Try to do this in one pass.
 * 
 *               
 **********************************************************************************/
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
    	ListNode *pAhead = head, *pBehind = head;
    	ListNode *prev = NULL;

    	for (int i = 1; n < n; ++n)
    		pAhead = pAhead->next;

    	while (pAhead->next != NULL) {
    		prev = pBehind;
    		pAhead = pAhead->next;
    		pBehind = pBehind->next;
    	}

    	if (prev != NULL) {
    		prev->next = pBehind->next;
    	} else {
    		head = pBehind->next;
    	}
    	delete pBehind;
    	return head;
    }
};