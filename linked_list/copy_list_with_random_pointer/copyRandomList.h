 /**
  * A linked list of length n is given such that each
  * node contains an additional random pointer, which
  * could point to any node in the list, or null.
  *
  * Construct a deep copy of the list. The deep copy
  * should consist of exactly n brand new nodes, where
  * each new node has its value set to the value of
  * its corresponding original node. Both the next
  * and random pointer of the new nodes should point
  * to new nodes in the copied list such that the
  * pointers in the original and copied list represent
  * the same list state. None of the pointers in the
  * new list should point to nodes in the original
  * list. */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL)
            return NULL;

        // create an empty hash map to store the
        // original nodes and their copies
        unordered_map<Node*, Node*> nodeMap;

        // Pass 1: create copies of nodes and poulate
        // the hash map
        Node *curr = head;
        while (curr != NULL) {
            Node *copy = new Node(curr->val);
            nodeMap[curr] = copy;
            curr = curr->next;
        }

        // Pass 2: for each node:
        //  Get the corresponding copy from the hash table
        //  Set the next pointer of the copy to the copy
        //      of the original node's next
        //  Set the random pointer of the copy to the copy
        //      of the original node's random
        curr = head;
        while (curr != NULL) {
            Node *copy = nodeMap[curr];
            copy->next = nodeMap[curr->next];
            copy->random = nodeMap[curr->random];
            curr = curr->next;
        }

        return nodeMap[head]; // return head of the copied list
    }
};
