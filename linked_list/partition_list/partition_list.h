 /**
  * Given the head of a linked list and a value x,
  * partition it such that all nodes less than x
  * come before nodes greater than or equal to x.
  *
  * You should preserve the original relative order
  * of the nodes in each of the two partitions. */

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
    ListNode* partition(ListNode* head, int x) {
        ListNode *dummyLeft = new ListNode(0); 
        ListNode *dummyRight = new ListNode(0);
        ListNode *iterLeft = dummyLeft;
        ListNode *iterRight = dummyRight;
        ListNode *iter = head;

        while (iter != NULL) {
            int val = iter->val;
            if (val < x) {
                iterLeft->next = new ListNode(val);
                iterLeft = iterLeft->next;
            } else {
                iterRight->next = new ListNode(val);
                iterRight = iterRight->next;
            }
            iter = iter->next;
        }

        iterLeft->next = dummyRight->next;
        return dummyLeft->next;
    }
};
