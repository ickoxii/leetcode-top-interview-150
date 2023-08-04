 /**
  * Given the head of a linked list, rotate the list
  * to the right by k places. */

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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *iter = head;
        ListNode *prev, *newHead;
        int size = 0;

        prev = newHead = NULL;
        
        // get size of list
        while (iter != NULL) {
            size++;
            iter = iter->next;
        }

        k = k % size; // normalize k

        if (k == 0) // no need for rotation
            return head;

        iter = head;
        // element at index [size - k] is the new head
        for (int i = 0; i < (size - k); ++i) {
            prev = iter;
            iter = iter->next;
        }

        prev->next = NULL; // unlink list[size-k-1]
        newHead = iter; // newHead is list[size-k]

        while (iter->next != NULL) {
            iter = iter->next;
        }
        
        iter->next = head; // attach end of list to head
        head = newHead; // update head

        return head;
    }
};
