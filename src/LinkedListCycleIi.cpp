// Source : https://leetcode.com/problems/linked-list-cycle-ii/
// Author : wind4869
// Date   : 2015-04-15

/********************************************************************************** 
 * 
 * Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 * 
 * Follow up:
 * Can you solve it without using extra space?
 * 
 *               
 **********************************************************************************/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (slow && fast && fast->next) {
        	slow = slow->next;
        	fast = fast->next->next;
        	if (slow == fast) {
        		slow = head;
        		while (slow != fast) {
        			slow = slow->next;
        			fast = fast->next;
        		}
        		return slow;
        	}
        }
        return NULL;
    }
};
