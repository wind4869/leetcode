// Source : https://leetcode.com/problems/copy-list-with-random-pointer/
// Author : wind4869
// Date   : 2015-07-26

/********************************************************************************** 
 * 
 * A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
 * 
 * Return a deep copy of the list.
 * 
 *               
 *               
 *               
 **********************************************************************************/
#include <iostream>
using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
	void cloneNodes(RandomListNode *head) {
		RandomListNode *node = head;
		while (node != NULL) {
			RandomListNode *cloned = new RandomListNode(node->label);
			cloned->next = node->next;
			node->next = cloned;
			node = cloned->next;
		}
	}

	void connectRandomNodes(RandomListNode *head) {
		RandomListNode *node = head;
		while (node != NULL) {
			RandomListNode *cloned = node->next;
			if (node->random != NULL)
				cloned->random = node->random->next;
			node = cloned->next;
		}
	}

	RandomListNode *reconnectNodes(RandomListNode *head) {
		RandomListNode *clonedHead = head->next;
		RandomListNode *clonedNode = clonedHead;
		RandomListNode *node = head;

		node->next = clonedNode->next;
		node = node->next;

		while (node != NULL) {
			clonedNode->next = node->next;
			clonedNode = clonedNode->next;
			node->next = clonedNode->next;
			node = node->next;
		}

		return clonedHead;
	}

    RandomListNode *copyRandomList(RandomListNode *head) {
    	if (head == NULL)
    		return NULL;

    	cloneNodes(head);
    	connectRandomNodes(head);
    	return reconnectNodes(head);
    }
};

int main()
{
	RandomListNode *head = new RandomListNode(-1);
	Solution().copyRandomList(head);
}

