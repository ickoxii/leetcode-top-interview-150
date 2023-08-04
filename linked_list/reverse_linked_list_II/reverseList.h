 /**
  * Given the head of a singly linked list and two
  * integers left and right where left <= right,
  * reverse the nodes of the list from position left
  * to position right, and return the reversed list. */

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || left == right)
            return head;
        
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        // Move curr to the node at position left
        for (int i = 1; i < left; i++) {
            prev = curr;
            curr = curr->next;
        }
        
        ListNode* prevSublistTail = prev; // Node before the sublist
        ListNode* sublistHead = curr; // Head of the sublist
        
        // Reverse the sublist
        for (int i = left; i <= right; i++) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        // Connect the reversed sublist back to the original list
        sublistHead->next = curr;
        if (prevSublistTail != nullptr)
            prevSublistTail->next = prev;
        else
            head = prev;
        
        return head;
    }
};
