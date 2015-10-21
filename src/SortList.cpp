// Source : https://leetcode.com/problems/sort-list/
// Author : wind4869
// Date   : 2015-03-28

/********************************************************************************** 
 * 
 * Sort a linked list in O(n log n) time using constant space complexity.
 *               
 **********************************************************************************/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *sortList(ListNode *head) {
    	return MergeSort(head);
    }

    ListNode *Merge(ListNode *head1, ListNode *head2)
    {
        if (head1 == NULL)
            return head2;
        if (head2 == NULL)
            return head1;
    
        ListNode *head = NULL;
        if (head1->val < head2->val)
        {
            head = head1;
            head->next = Merge(head1->next, head2);
        }
        else
        {
            head = head2;
            head->next = Merge(head1, head2->next);
        }
        return head;
    }
    
    ListNode *MergeSort(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
    
        ListNode *slow = head, *fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
    
        ListNode *head1 = head, *head2 = slow->next;
        slow->next = NULL;
    
        head1 = MergeSort(head1);
        head2 = MergeSort(head2);
    
        return Merge(head1, head2);
    }
};