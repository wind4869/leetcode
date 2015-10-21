// Source : https://leetcode.com/problems/linked-list-cycle/
// Author : wind4869
// Date   : 2015-04-09

/********************************************************************************** 
 * 
 * Given a linked list, determine if it has a cycle in it.
 * 
 * Follow up:
 * Can you solve it without using extra space?
 * 
 *               
 **********************************************************************************/
#include <iostream>
using namespace std;

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (slow && fast && fast->next) {
        	slow = slow->next;
        	fast = fast->next->next;
        	if (slow == fast) return true;
        }
        return false;
    }
};


