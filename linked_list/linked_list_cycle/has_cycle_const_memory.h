/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:

public:
    /* solves in constant memory using the tortoise
     * and the hare method. if the hare catches up
     * to the tortoise, the list contains a cycle */
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return false;

        ListNode *tortoise = head;
        ListNode *hare = head->next;

        while (tortoise != hare) {
            if (hare == nullptr || hare->next == nullptr)
                return false;

            tortoise = tortoise->next;
            hare = hare->next->next;
        }

        return true;
    }
};
