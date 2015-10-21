// Source : https://leetcode.com/problems/intersection-of-two-linked-lists/
// Author : wind4869
// Date   : 2015-03-22

/********************************************************************************** 
 * 
 * Write a program to find the node at which the intersection of two singly linked lists begins.
 * 
 * For example, the following two linked lists: 
 * 
 * A:          a1 → a2
 * B:     b1 → b2 → b3
 * 
 * begin to intersect at node c1.
 * 
 * Notes:
 * 
 * If the two linked lists have no intersection at all, return null.
 * The linked lists must retain their original structure after the function returns. 
 * You may assume there are no cycles anywhere in the entire linked structure.
 * Your code should preferably run in O(n) time and use only O(1) memory.
 * 
 * Credits:Special thanks to @stellari for adding this problem and creating all test cases.
 *               
 **********************************************************************************/
#include <iostream>
using namespace std;

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL)
        	return NULL;

        ListNode *pNodeA = headA;
        ListNode *pNodeB = headB;
        ListNode *temp;
        while (pNodeA->next != NULL && pNodeB->next != NULL) {
        	pNodeA = pNodeA->next;
        	pNodeB = pNodeB->next;
        }

        if (pNodeA->next == NULL && pNodeB->next == NULL) {
        	pNodeA = headA;
        	pNodeB = headB;
        } else if (pNodeA->next == NULL) {
        	temp = headB;
        	while (pNodeB->next != NULL) {
        		temp = temp->next;
        		pNodeB = pNodeB->next;
        	}
        	pNodeA = headA;
        	pNodeB = temp;
        } else {
			temp = headA;
        	while (pNodeA->next != NULL) {
        		temp = temp->next;
        		pNodeA = pNodeA->next;
        	}
        	pNodeA = temp;
        	pNodeB = headB;
        }

        while (pNodeA != NULL && pNodeB != NULL)
        {
        	if (pNodeA == pNodeB)
        		return pNodeA;
        	pNodeA = pNodeA->next;
        	pNodeB = pNodeB->next;
        }

        return NULL;
    }
};