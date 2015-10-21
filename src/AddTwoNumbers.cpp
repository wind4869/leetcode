// Source : https://leetcode.com/problems/add-two-numbers/
// Author : wind4869
// Date   : 2015-03-22

/********************************************************************************** 
 * 
 * You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 *               
 **********************************************************************************/
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *result, *pre = NULL;
        int sum = 0, carry = 0;

        while (l1 != NULL || l2 != NULL) {
        	sum = 0;
        	if (l1 != NULL) {
        		sum += l1->val;
        		l1 = l1->next;
        	}
        	if (l2 != NULL) {
        		sum += l2->val;
        		l2 = l2->next;
        	}
        	sum += carry;
        	carry = sum / 10;

        	ListNode *newNode = new ListNode(sum % 10);

        	if (pre == NULL)
        		result = newNode;
        	else
        		pre->next = newNode;
        	pre = newNode;
        }

        if (carry > 0)
        	pre->next = new ListNode(carry);

        return result;
    }
};
