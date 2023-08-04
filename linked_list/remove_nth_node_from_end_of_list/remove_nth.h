 /**
  * Given the head of a linked list, remove the
  * nth node from the end of the list and return
  * its head. */

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL)
            return NULL;

        ListNode *iter = head;
        int size = 0;

        while (iter != NULL) {
            size++;
            iter = iter->next;
        }

        iter = head;

        int ndx = size - n;

        if (ndx == 0)
            return head->next;

        ListNode *prev;
        for (int i = 0; i < ndx; ++i) {
            prev = iter;
            iter = iter->next;
        }
        prev->next = iter->next;

        return head;
    }
};
