 /* Given the head of a linked list, reverse the
  * nodes of the list k at a time, and return the
  * modified list.
  *
  * k is a positive integer and is less than or
  * equal to the length of the linked list. If
  * the number of nodes is not a multiple of k
  * then left-out nodes, in the end, should remain
  * as is.
  *
  * You may not alter the values in the list's
  * nodes, only the nodes themselves may be changed. */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1)
            return head;
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        
        while (true) {
            ListNode* curr = prev->next;
            ListNode* groupTail = prev;
            
            // Check if there are at least k nodes remaining
            for (int i = 0; i < k; i++) {
                groupTail = groupTail->next;
                if (groupTail == nullptr)
                    return dummy.next;
            }
            
            // Reverse the group of k nodes
            for (int i = 0; i < k - 1; i++) {
                ListNode* next = curr->next;
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
            }
            
            prev = curr;
        }
        
        return dummy.next;
    }
};
