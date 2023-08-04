/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
    queue<TreeNode*> nodeStack;

    void pushInOrder(TreeNode* node) {
        if (!node)
            return;
        pushInOrder(node->left);
        nodeStack.push(node);
        pushInOrder(node->right);
    }
public:
    BSTIterator(TreeNode* root) {
        pushInOrder(root);
    }
    
    int next() {
        if (hasNext())
            nodeStack.pop();
        return nodeStack.top()->val;
    }
    
    bool hasNext() {
        return (!nodeStack.empty());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
