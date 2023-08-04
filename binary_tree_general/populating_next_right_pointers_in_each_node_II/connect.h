 /**
  * shitty problem description.
  *
  * For every level of the tree, connect each node
  * to the node on its right. This could either be a
  * sibling to the node, or a node on a different
  * subtree. If the node is already the right-most
  * node on its level, its right pointer points
  * to null instead. This is basically a breadth
  * first search of the list. */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        
        std::queue<Node*> nodeQueue;
        nodeQueue.push(root);
        
        while (!nodeQueue.empty()) {
            int levelSize = nodeQueue.size();
            
            for (int i = 0; i < levelSize; ++i) {
                Node* current = nodeQueue.front();
                nodeQueue.pop();
                
                if (i < levelSize - 1)
                    current->next = nodeQueue.front();
                
                if (current->left) nodeQueue.push(current->left);
                if (current->right) nodeQueue.push(current->right);
            }
        }
        
        return root;
    }
};
