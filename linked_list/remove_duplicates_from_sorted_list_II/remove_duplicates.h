 /* Given the head of a sorted linked list, delete
  * all nodes that have duplicate numbers, leaving
  * only distinct numbers from the original list.
  *
  * Return the linked list sorted as well. */

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* curr = head;
        
        while (curr != nullptr) {
            while (curr->next != nullptr && curr->val == curr->next->val)
                curr = curr->next;
            
            if (prev->next == curr)
                prev = prev->next;
            else
                prev->next = curr->next;
            
            curr = curr->next;
        }
        
        return dummy.next;
    }
};
